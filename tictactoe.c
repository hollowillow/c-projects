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
int winCondition;

void defineRules(void) {
        // recurse until valid rules defined
        printf("Enter the board size: ");
        scanf("%i", &boardSize);
        if (boardSize < 3) {
                printf("Board size too small!\n");
                defineRules();
                return;
        }

        printf("Enter the number of marks needed to win: ");
        scanf("%i", &winCondition);
        if (winCondition > boardSize) {
                printf("Win condition too large!\n");
                defineRules();
                return;
        } else if (winCondition < 3) {
                printf("Win condition too small!\n");
                defineRules();
                return;

        }
}

void setBoard(void) {
        board = malloc(boardSize * sizeof(char *));
        for (int row = 0; row < boardSize; row++) {
                board[row] = malloc(boardSize * sizeof(char));
                for (int column = 0; column < boardSize; column++) {
                        board[row][column] = ' ';
                }
        }
}

void freeBoard(void) {
    for (int row = 0; row < boardSize; row++) {
        free(board[row]);
    }
    free(board);
}

void drawBoard(void) {
        for (int row = 0; row < boardSize; row++) {
                // print top border
                for (int column = 0; column < boardSize; column++) {
                        printf("+---");
                }
                printf("+\n");

                // print side border
                for (int column = 0; column < boardSize; column++) {
                        printf("| %c ",board[row][column]);
                }
                printf("|\n");
        }

        // print bottom border
        for (int column = 0; column < boardSize; column++) {
                printf("+---");
        }
        printf("+\n");
}

void playerMove(char mark) {
        int row, column;
        printf("Enter column: ");
        scanf("%i", &column);
        printf("Enter row: ");
        scanf("%i", &row);
        row--; column--; // adjust for indexing

        if (row < 0 || row >= boardSize || column < 0 || column >= boardSize) {
                printf("Invalid coordinates!\n");
                playerMove(mark); // recurse until valid move is made
        } else if (board[row][column] == '.') {
                board[row][column] = mark;
        } else {
                printf("Space already occupied!\n");
                playerMove(mark); // recurse until valid move is made
        }
}

void playGame(void) {
        for (int turn = 0; turn < 9; turn++) {
                drawBoard(); // draw current board state

                if (turn % 2 == 0) {
                        printf("\nPlayer 1 (x)\n");
                        playerMove('x');
                } else {
                        printf("\nPlayer 2 (o)\n");
                        playerMove('o');
                }
        }
}

int main(void) {
        setBoardSize();
        allocateBoard();

        initializeBoard();

        playGame();

        freeBoard();

        return 0;
}
