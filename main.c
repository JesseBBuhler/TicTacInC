#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define BOARD_SIZE 3

int printBoard(int board[BOARD_SIZE][BOARD_SIZE]);
bool moveTaken(int move, int board[BOARD_SIZE][BOARD_SIZE]);
int getValidInput(int board[BOARD_SIZE][BOARD_SIZE]);
int makeMove(int turn, int move, int board[BOARD_SIZE][BOARD_SIZE]);
void clearLine();
char winningMove(int move, int turn, int board[BOARD_SIZE][BOARD_SIZE]);
int getCol(int move);
int getRow(int move);
char turnSymbol(int turn);
int turnInt(int turn);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;
    char winner = ' ';

    //populate board
    int boardIndex = 1;
    for(int i = 0; i < BOARD_SIZE; i++) {

        for(int j = 0; j < BOARD_SIZE; j++ ){
            board[i][j] = boardIndex;
            boardIndex++;
        }
    }

    while(winner == ' ' && turn < (BOARD_SIZE * BOARD_SIZE)) {
        printBoard(board);
        int move = getValidInput(board);
        makeMove(turnInt(turn), move, board);
        winner = winningMove(move, turn, board);
        turn++;
    }
    
    printBoard(board);
    if(winner == ' ') {
        printf("Game Over! It's a Tie!");
    } else {
        printf("%c won the game!", winner);
    }
    
    
    return 0;
}

char turnSymbol(int turn) {
    if(turn % 2) {
        return 'O';
    } else {
        return 'X';
    }
}

int turnInt(int turn) {
    return (turn % 2)-1;
}

char winningMove(int move, int turn, int board[BOARD_SIZE][BOARD_SIZE]) {
    bool colWin = true;
    bool rowWin = true;
    bool posWin = true;
    bool negWin = true;
    int col = getCol(move);
    int row = getRow(move);
    char symbol = turnSymbol(turn);

    int checkCol = BOARD_SIZE - 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if(board[row][i] != turnInt(turn)) {
            rowWin = false;
        }

        if(board[i][col] != turnInt(turn)) {
            colWin = false;
        }

        if(board[i][i] != turnInt(turn)) {
            posWin = false;
        }

        if(board[i][checkCol] != turnInt(turn)) {
            negWin = false;
        }
        checkCol--;
    }
    
    if(colWin || rowWin || posWin || negWin) {
        return symbol;
    } else {
        return ' ';
    }
    
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
    int row = getRow(move);
    int col = getCol(move);

    if(board[row][col] != move) {
        taken = true;
    }
    
    return taken;
}

int getCol(int move) {
    int col = BOARD_SIZE - 1;
    if ((move % BOARD_SIZE) > 0) {
        col = (move % BOARD_SIZE) - 1;
    }
    return col;
}
int getRow(int move) {
    int row = ceil((double)move / BOARD_SIZE) - 1;
    return row;
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
    int row = getRow(move);
    int col = getCol(move);

    board[row][col] = turn;
    return 0;
}

void clearLine() {
    char nextChar;

    while(nextChar != '\n') {
        nextChar = getchar();
    }
}