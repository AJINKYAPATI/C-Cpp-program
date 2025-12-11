#include<stdio.h>
int main(){

    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int flage=1,row,col;
    char currentplayer='x';

    //print the board
    printf("welcome to tic-tac-toe\n");
    while(flag){
        
      printf("----------------------\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("| %c |",board[i][j]);
            }
            printf("\n-----------------------\n";)
        }

        printf("player %c is playing.....\n",currentplayer);
        printf("enter row no:");
        
scanf("%d",&row);
        printf("enter col no:");
        scanf("%d",&col);

        board[row-1][col-1]=currentplayer;

        currentplayer= currentplayer=='x'?'o':'x';
    }
    
    return 0;
}
