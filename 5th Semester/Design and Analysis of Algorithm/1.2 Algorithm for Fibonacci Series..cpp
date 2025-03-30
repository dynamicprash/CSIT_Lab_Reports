#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fibonacci(int n) {
    int first = 0, second = 1, next;
    int count = 0;

    printf("Fibonacci Series up to %d terms:\n", n);

    for (int i = 0; i < n; i++) {
        count++;
        if (i <= 1) {
            next = i; // First two terms are 0 and 1
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\nTotal iterations: %d\n", count);
}

// Function to generate a random number within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    int terms;
    char choice;

    printf("--------FIBONACCI SERIES--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    srand(time(0));

    do {
        printf("Do you want to enter the number of terms manually or generate randomly? (m/r): ");
        scanf(" %c", &choice);

        if (choice == 'm' || choice == 'M') {
            printf("Enter the number of terms: ");
            scanf("%d", &terms);
        } else {
            terms = generateRandom(5, 15); // Random number between 5 and 15
            printf("Generated number of terms: %d\n", terms);
        }

        // Generate and print the Fibonacci series
        fibonacci(terms);

        printf("Do you want to generate another Fibonacci sequence? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
