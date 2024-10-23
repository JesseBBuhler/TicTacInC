#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define BOARD_SIZE 3

int printBoard(int board[BOARD_SIZE][BOARD_SIZE]);
bool moveTaken(int move, int board[BOARD_SIZE][BOARD_SIZE]);
int getValidInput(int board[BOARD_SIZE][BOARD_SIZE]);
int makeMove(int turn, int move, int board[BOARD_SIZE][BOARD_SIZE]);
void clearLine();

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    int boardIndex = 1;
    for(int i = 0; i < BOARD_SIZE; i++) {

        for(int j = 0; j < BOARD_SIZE; j++ ){
            board[i][j] = boardIndex;
            boardIndex++;
        }
    }
    printBoard(board);

    makeMove(-1, getValidInput(board), board);
    
    printBoard(board);
    
    return 0;
}

int printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++ ){
            if(board[r][c] > 0) {
                printf(" %d ", board[r][c]);
            } else if(board[r][c] == 0) {
                printf(" O ");
            } else {
                printf(" X ");
            }
            
            if(c % BOARD_SIZE != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if(r % BOARD_SIZE != BOARD_SIZE - 1) {
            printf("-----------\n");
        }
        
    }
    printf("\n");
    return 0;
}

bool moveTaken(int move, int board[BOARD_SIZE][BOARD_SIZE]) {
    bool taken = false;
    int row = ceil((double)move / BOARD_SIZE) - 1;
    int col = (move % BOARD_SIZE) - 1;

    if(board[row][col] != move) {
        taken = true;
    }
    
    return taken;
}

int getValidInput(int board[BOARD_SIZE][BOARD_SIZE]) {
    int move;
    bool valid = false;
    while(!valid) {
        printf("Select your move: ");
        if(scanf("%d", &move) != 1) {
            printf("Must input an integer.\n");
        } else if(move < 1 || move > BOARD_SIZE * BOARD_SIZE || moveTaken(move, board)) {
            printf("Must select an available move.\n");
        } else {
            valid = true;
        }
        clearLine();
    }

    return move;
}

int makeMove(int turn, int move, int board[BOARD_SIZE][BOARD_SIZE]) {
    int row = ceil((double)move / BOARD_SIZE) - 1;
    int col = (move % BOARD_SIZE) - 1;

    board[row][col] = turn;
    return 0;
}

void clearLine() {
    char nextChar;

    while(nextChar != '\n') {
        nextChar = getchar();
    }
}