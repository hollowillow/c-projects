#include <stdio.h>
#include <stdlib.h>
// try to build a game of tic-tac-toe
// features:
//      any size board
//      board deliminators
//      let players take turns
//      check win condition/set win condition

// global variables
int boardSize;
char **board;

void setBoardSize(void) {
    printf("Enter the board size: ");
    scanf("%d", &boardSize);
}

void allocateBoard(void) {
    // Allocate memory for the board
    board = malloc(boardSize * sizeof(char *));
    for (int i = 0; i < boardSize; i++) {
        board[i] = malloc(boardSize * sizeof(char));
    }
}

void freeBoard(void) {
    // Free allocated memory
    for (int i = 0; i < boardSize; i++) {
        free(board[i]);
    }
    free(board);
}

void initializeBoard(void) {
        for (int i = 0; i < boardSize; i++) {
                for (int j = 0; j < boardSize; j++) {
                        // set initial character
                        board[i][j] = '.';
                }
        }
}

void drawBoard(void) {
        for (int i = 0; i < boardSize; i++) {
                // print top border
                for (int j = 0; j < boardSize; j++) {
                        printf("+---");
                }
                printf("+\n");

                // print side border
                for (int j = 0; j < boardSize; j++) {
                        printf("| %c ",board[i][j]);
                }
                printf("|\n");
        }

        // print bottom border
        for (int j = 0; j < boardSize; j++) {
                printf("+---");
        }
        printf("+\n");
}

int main(void) {
        setBoardSize();
        allocateBoard();

        initializeBoard();
        drawBoard();

        freeBoard();

        return 0;
}
