#include <stdio.h>
#define BOARD_SIZE 3

int printBoard(int board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    int boardIndex = 1;
    for(int i = 0; i < BOARD_SIZE; i++) {

        for(int j = 0; j < BOARD_SIZE; j++ ){
            board[i][j] = boardIndex;
            boardIndex++;
        };
    };
    printBoard(board);
    
    return 0;
}

int printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++ ){
            printf(" %d ", board[r][c]);
            if(c % BOARD_SIZE != 2) {
                printf("|");
            }
        };
        printf("\n");
        if(r % BOARD_SIZE != 2) {
            printf("-----------\n");
        }
        
    };


    return 0;
}