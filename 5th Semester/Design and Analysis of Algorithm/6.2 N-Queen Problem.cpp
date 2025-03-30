#include <stdio.h>

#define MAX 10

int board[MAX][MAX];
int countSolutions = 0;  // To track the number of solutions

void printSolution(int n) {
    printf("\nSolution %d:\n", ++countSolutions);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

int isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])  // Check if there's a queen in the same row
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])  // Check upper diagonal
            return 0;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])  // Check lower diagonal
            return 0;

    return 1;
}

void solveNQueen(int col, int n, int* iterationCount) {
    (*iterationCount)++;  // Increment iteration count each time the function is called
    
    if (col >= n) {
        printSolution(n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            solveNQueen(col + 1, n, iterationCount);
            board[i][col] = 0;
        }
    }
}

int main() {
    int n, iterationCount;
    char repeat;

    printf("--------N-Queens Problem--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    do {
        printf("Enter the value of N: ");
        scanf("%d", &n);

        if (n < 1 || n > MAX) {
            printf("Invalid value of N. Choose a value from 1 to %d.\n", MAX);
            continue;
        }

        iterationCount = 0;  // Reset iteration count for each run
        countSolutions = 0;  // Reset solution count
        printf("\nPossible solutions:\n");
        solveNQueen(0, n, &iterationCount);

        printf("\nTotal number of solutions: %d\n", countSolutions);
        printf("Total iterations: %d\n", iterationCount);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
