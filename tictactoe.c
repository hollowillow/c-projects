#include <stdio.h>
// try to build a game of tic-tac-toe
// features:
//      any size board
//      board deliminators
//      let players take turns
//      check win condition/set win condition

// define size of the board
#define boardSize 4
char board[boardSize][boardSize];
int boardRows = sizeof(board)/sizeof(board[0]);
int boardColumns = sizeof(board[0])/sizeof(board[0][0]);

void initializeBoard(void) {
        for (int i = 0; i < boardRows; i++) {
                for (int j = 0; j < boardColumns; j++) {
                        // set initial character
                        board[i][j] = '.';
                }
        }
}

void drawBoard(void) {
        for (int i = 0; i < boardRows; i++) {
                // print top border
                for (int j = 0; j < boardColumns; j++) {
                        printf("+---");
                }
                printf("+\n");

                // print side border
                for (int j = 0; j < boardColumns; j++) {
                        printf("| %c ",board[i][j]);
                }
                printf("|\n");
        }

        // print bottom border
        for (int j = 0; j < boardColumns; j++) {
                printf("+---");
        }
        printf("+\n");
}

int main(void) {
        initializeBoard();
        drawBoard();
}
