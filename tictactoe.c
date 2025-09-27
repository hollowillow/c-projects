#include <stdio.h>
// try to build a game of tic-tac-toe

int main() {
        // define size of the board
        const int boardSize = 4;
        char gameBoard[boardSize][boardSize];
        for (int i = 0; i < sizeof(gameBoard)/sizeof(gameBoard[0]); i++) {
                for (int j = 0; j < sizeof(gameBoard[0])/sizeof(char); j++) {
                        gameBoard[i][j] = 'x';
                        printf("%c", gameBoard[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
