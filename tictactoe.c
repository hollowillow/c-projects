#include <stdio.h>
#include <stdlib.h>

// function prototypes
void defineRules(void);
void setBoard(void);
void freeBoard(void);
void drawBoard(void);
void playerMove(char);
void playGame(void);
int checkSequence(int,int,int,int,char);
int checkWin(char);
int main(void);

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
                // draw top borders
                for (int column = 0; column < boardSize; column++) {
                        printf("+---");
                }
                printf("+\n");

                // draw side borders
                for (int column = 0; column < boardSize; column++) {
                        printf("| %c ",board[row][column]);
                }
                printf("|\n");
        }

        // draw bottom border
        for (int column = 0; column < boardSize; column++) {
                printf("+---");
        }
        printf("+\n");
}

void playerMove(char mark) {
        int row, column;
        printf("Enter column (1 to %i): ",boardSize); scanf("%i", &column);
        printf("Enter row (1 to %i): ",boardSize); scanf("%i", &row);
        row--; column--; // adjust for indexing

        // recurse until valid move is made
        if (row < 0 || row >= boardSize || column < 0 || column >= boardSize) {
                printf("Invalid coordinates!\n");
                playerMove(mark);
                return;
        } else if (board[row][column] != ' ') {
                printf("Space already occupied!\n");
                playerMove(mark);
                return;
        } else {
                board[row][column] = mark;
        }
}

int checkSequence(int startRow, int startCol, int rowIncrement, int colIncrement, char mark) {
        int count = 0;
        for (int index = 0; index < winCondition; index++) {
                if (board[startRow + index * rowIncrement][startCol + index * colIncrement] == mark) {
                        count++;
                }
        }
        return count == winCondition;
}

int checkWin(char mark) {
        // Check rows and columns
        for (int index = 0; index < boardSize; index++) {
                for (int startCol = 0; startCol <= boardSize - winCondition; startCol++) {
                        if (checkSequence(index, startCol, 0, 1, mark) || // check row
                            checkSequence(startCol, index, 1, 0, mark)) { // check column
                                return 1; // win found
                        }
                }
        }

        // Check diagonals
        for (int startRow = 0; startRow <= boardSize - winCondition; startRow++) {
                for (int startCol = 0; startCol <= boardSize - winCondition; startCol++) {
                        if (checkSequence(startRow, startCol, 1, 1, mark) || // Check top-left to bottom-right
                            checkSequence(startRow, startCol + winCondition - 1, 1, -1, mark)) { // Check top-right to bottom-left
                                return 1; // Win found
                        }
                }
        }

        return 0; // No win found
}

void playGame(void) {
        for (int turn = 0; turn <= boardSize * boardSize; turn++) {
                drawBoard(); // draw current board state each turn

                // if maximum number of moves for boardSize reached, tie
                if (turn == boardSize * boardSize) {
                        printf("\nYou have reached a tie!\n");
                        drawBoard();
                } else if (turn % 2 == 0) { // else X on even turns
                        printf("\nPlayer 1 (x)\n");
                        playerMove('x');
                        if (checkWin('x')) {
                                printf("\nPlayer 1 (x) wins!\n");
                                drawBoard();
                                break;
                        };
                } else { // O on odd turns
                        printf("\nPlayer 2 (o)\n");
                        playerMove('o');
                        if (checkWin('o')) {
                                printf("\nPlayer 2 (o) wins!\n");
                                drawBoard();
                                break;
                        };
                }
        }
}

int main(void) {
        defineRules();
        setBoard();
        playGame();
        freeBoard();

        return 0;
}
