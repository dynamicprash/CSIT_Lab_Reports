#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to compute GCD using the Euclidean Algorithm
int gcd(int a, int b) {
    int count = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        count++;
    }
    printf("Number of iterations: %d\n", count);
    return a;
}

// Function to generate random numbers within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    int num1, num2;
    char choice;

    printf("--------ALGORITHM FOR GCD--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    srand(time(0));

    do {
        printf("Do you want to enter numbers manually or generate randomly? (m/r): ");
        scanf(" %c", &choice);

        if (choice == 'm' || choice == 'M') {
            printf("Enter two integers: ");
            scanf("%d %d", &num1, &num2);
        } else {
            num1 = generateRandom(1, 100);
            num2 = generateRandom(1, 100);
            printf("Generated numbers: %d and %d\n", num1, num2);
        }

        printf("GCD of %d and %d: %d\n", num1, num2, gcd(num1, num2));

        printf("Do you want to find GCD of another pair of numbers? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
