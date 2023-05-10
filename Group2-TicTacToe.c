#include <stdio.h>

char board[3][3]; // Tic Tac Toe board

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }

    // Check for a tie
    int tie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = 0;
                break;
            }
        }
    }
    if (tie) {
        return 2;
    }

    return 0;
}

int main() {
    int currentPlayer = 1; // Player 1 starts
    int row, col;
    int gameOver = 0;
    int winner;

    initializeBoard();

    printf("Tic Tac Toe Game\n");

    while (!gameOver) {
        printBoard();

        printf("Player %d's turn.\n", currentPlayer);
        printf("Enter the row (0-2): ");
        scanf("%d", &row);
        printf("Enter the column (0-2): ");
        scanf("%d", &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (currentPlayer == 1) {
    		board[row][col] = 'X';
    		currentPlayer = 2; // switch to player 2
		}
	else {
    	board[row][col] = 'O';
    	currentPlayer = 1; // switch to player 1
	}
}
}
