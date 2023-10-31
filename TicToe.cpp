#include <stdio.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---------\n");
        }
    }
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;  // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;  // Vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;  // Diagonal win (top-right to bottom-left)
    }
    return 0;
}

// Function to check if the game is a draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;  // There are still empty cells, the game is not a draw
            }
        }
    }
    return 1;  // All cells are filled, the game is a draw
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    int gameWon = 0;
    int gameDraw = 0;

    do {
        // Display the board
        printf("Tic-Tac-Toe Game\n");
        displayBoard(board);

        // Get player input
        int row, col;
        do {
            printf("Player %c, enter your move (row and column): ", currentPlayer);
            scanf("%d %d", &row, &col);
        } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

        // Update the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            gameWon = 1;
        } else if (checkDraw(board)) {
            gameDraw = 1;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (!gameWon && !gameDraw);

    // Display the final state of the board
    printf("Tic-Tac-Toe Game\n");
    displayBoard(board);

    // Display the result
    if (gameWon) {
        printf("Player %c wins!\n", currentPlayer);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
