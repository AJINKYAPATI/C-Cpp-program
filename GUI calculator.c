/* gtk_calculator.c
 *
 * Simple GUI Calculator using GTK3
 * Features: +, -, *, /, %, ^ (power), sqrt (unary), decimal, backspace, clear, equals
 *
 * Build:
 *   gcc -o gtk_calculator gtk_calculator.c `pkg-config --cflags --libs gtk+-3.0` -lm
 *
 * On Debian/Ubuntu you may need:
 *   sudo apt install libgtk-3-dev
 *
 * Run:
 *   ./gtk_calculator
 */

#include <gtk/gtk.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    GtkWidget *entry;
    double op1;
    double op2;
    char operator;
    gboolean op1_set;
    gboolean waiting_for_op2;
} AppState;

/* Utility: set entry text */
static void set_display(AppState *s, const char *text) {
    gtk_entry_set_text(GTK_ENTRY(s->entry), text);
}

/* Utility: append char to entry (for digits and dot) */
static void append_display_char(AppState *s, const char ch) {
    const char *cur = gtk_entry_get_text(GTK_ENTRY(s->entry));
    char buf[256];
    snprintf(buf, sizeof(buf), "%s%c", cur, ch);
    set_display(s, buf);
}

/* Utility: remove last char (backspace) */
static void backspace_display(AppState *s) {
    const char *cur = gtk_entry_get_text(GTK_ENTRY(s->entry));
    size_t len = strlen(cur);
    if (len == 0) return;
    char *buf = g_strdup(cur);
    buf[len - 1] = '\0';
    set_display(s, buf);
    g_free(buf);
}

/* Convert entry text to double, handle empty as 0 */
static double display_to_double(AppState *s) {
    const char *txt = gtk_entry_get_text(GTK_ENTRY(s->entry));
    if (txt == NULL || txt[0] == '\0') return 0.0;
    return atof(txt);
}

/* Show a result in display with trimming trailing .000... if integer */
static void show_result(AppState *s, double val) {
    /* Format with up to 12 significant decimals but remove trailing zeros */
    char buf[128];
    snprintf(buf, sizeof(buf), "%.12g", val);
    set_display(s, buf);
}

/* Perform pending operation (op1 operator op2). Returns success boolean */
static gboolean perform_operation(AppState *s) {
    if (!s->op1_set) return FALSE;
    s->op2 = display_to_double(s);

    double res = 0.0;
    switch (s->operator) {
        case '+': res = s->op1 + s->op2; break;
        case '-': res = s->op1 - s->op2; break;
        case '*': res = s->op1 * s->op2; break;
        case '/':
            if (s->op2 == 0.0) { set_display(s, "Error: /0"); return FALSE; }
            res = s->op1 / s->op2; break;
        case '%':
            if ((long long)s->op2 == 0) { set_display(s, "Error: %0"); return FALSE; }
            res = (double)((long long)s->op1 % (long long)s->op2); break;
        case '^':
            res = pow(s->op1, s->op2); break;
        default:
            return FALSE;
    }
    s->op1 = res;
    show_result(s, res);
    s->waiting_for_op2 = FALSE;
    return TRUE;
}

/* When an operator button (+,-,*,/,%,^) is pressed */
static void on_operator_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    char op = label[0];

    /* If there's already op1 and operator waiting and user enters a new operator,
       perform previous operation first (like normal calculators) */
    if (s->op1_set && s->waiting_for_op2) {
        if (!perform_operation(s)) {
            /* error already displayed */
            s->op1_set = FALSE;
            s->waiting_for_op2 = FALSE;
            s->operator = '\0';
            return;
        }
    } else {
        /* set op1 from display */
        s->op1 = display_to_double(s);
        s->op1_set = TRUE;
    }

    s->operator = op;
    s->waiting_for_op2 = TRUE;
    /* clear entry so user can type second operand */
    set_display(s, "");
}

/* Handle equals */
static void on_equals_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    if (!s->op1_set || !s->waiting_for_op2) {
        /* Nothing to compute */
        return;
    }
    perform_operation(s);
    /* after equals, keep op1_set true so chained operations possible */
}

/* Handle unary sqrt */
static void on_sqrt_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    double val = display_to_double(s);
    if (val < 0.0) {
        set_display(s, "Error: sqrt");
        return;
    }
    double res = sqrt(val);
    show_result(s, res);
    /* If operator was waiting for op2, result becomes the op2 shown; otherwise replace op1 */
}

/* Handle digit and dot buttons */
static void on_digit_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    /* label could be "0"-"9" or "." */
    if (strcmp(label, ".") == 0) {
        const char *cur = gtk_entry_get_text(GTK_ENTRY(s->entry));
        if (strchr(cur, '.') != NULL) return; /* avoid second decimal point */
        if (cur[0] == '\0') append_display_char(s, '0'); /* leading 0 before '.' */
        append_display_char(s, '.');
    } else {
        append_display_char(s, label[0]);
    }
}

/* Clear (C) */
static void on_clear_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    set_display(s, "");
    s->op1 = s->op2 = 0.0;
    s->operator = '\0';
    s->op1_set = FALSE;
    s->waiting_for_op2 = FALSE;
}

/* Backspace */
static void on_back_clicked(GtkWidget *widget, gpointer data) {
    AppState *s = (AppState *)data;
    backspace_display(s);
}

/* Build UI and attach callbacks */
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    AppState state;
    state.op1 = state.op2 = 0.0;
    state.operator = '\0';
    state.op1_set = FALSE;
    state.waiting_for_op2 = FALSE;

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Vertical box: display on top, grid of buttons below */
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    /* Display entry */
    state.entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(state.entry), 1.0); /* right align */
    gtk_editable_set_editable(GTK_EDITABLE(state.entry), FALSE);
    gtk_entry_set_text(GTK_ENTRY(state.entry), "");
    gtk_widget_set_size_request(state.entry, -1, 40);
    gtk_box_pack_start(GTK_BOX(vbox), state.entry, FALSE, FALSE, 0);

    /* Grid for buttons */
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 6);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    /* Buttons layout matrix (rows) */
    const char *labels[6][4] = {
        {"C", "←", "√", "%"},
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", ".", "=", "+"},
        {"^", "", "", ""}  /* extra row for power button */
    };

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 4; c++) {
            const char *lab = labels[r][c];
            if (lab == NULL || lab[0] == '\0') continue;
            GtkWidget *btn = gtk_button_new_with_label(lab);
            gtk_widget_set_hexpand(btn, TRUE);
            gtk_widget_set_vexpand(btn, TRUE);

            /* Attach callbacks according to label */
            if (strcmp(lab, "C") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_clear_clicked), &state);
            } else if (strcmp(lab, "←") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_back_clicked), &state);
            } else if (strcmp(lab, "√") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_sqrt_clicked), &state);
            } else if (strcmp(lab, "=") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_equals_clicked), &state);
            } else if (strchr("+-*/%^", lab[0]) && strlen(lab) == 1) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_operator_clicked), &state);
            } else { /* digits and dot */
                g_signal_connect(btn, "clicked", G_CALLBACK(on_digit_clicked), &state);
            }

            /* Place buttons on grid. Put '^' in bottom-left area */
            if (r == 5 && strcmp(lab, "^") == 0) {
                gtk_grid_attach(GTK_GRID(grid), btn, 0, 5, 4, 1); /* span full row */
            } else {
                gtk_grid_attach(GTK_GRID(grid), btn, c, r, 1, 1);
            }
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
