#include <stdio.h>

void fractionalKnapsack(int weights[], int values[], int n, int W) {
    double ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = (double)values[i] / weights[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;

                double tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;
            }

    double maxValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= weights[i]) {
            W -= weights[i];
            maxValue += values[i];
        } else {
            maxValue += values[i] * ((double) W / weights[i]);
            break;
        }
    }
    printf("Maximum Value: %.2f\n", maxValue);
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int n = 3, W = 50;
    fractionalKnapsack(weights, values, n, W);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fractional Knapsack function with iteration count tracking
void fractionalKnapsack(int weights[], int values[], int n, int W, int* count) {
    (*count)++;  // Increment iteration count

    double ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = (double)values[i] / weights[i];

    // Sort items based on value/weight ratio (greedy approach)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                swap(&values[i], &values[j]);
                swap(&weights[i], &weights[j]);
                double tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;
            }

    // Find maximum value with fractional items
    double maxValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= weights[i]) {
            W -= weights[i];
            maxValue += values[i];
        } else {
            maxValue += values[i] * ((double) W / weights[i]);
            break;
        }
    }
    printf("Maximum Value: %.2f\n", maxValue);
}

// Randomly generate item weights and values
void generateRandomItems(int weights[], int values[], int n) {
    for (int i = 0; i < n; i++) {
        weights[i] = rand() % 10 + 1; // Random weights between 1 and 10
        values[i] = rand() % 100 + 1; // Random values between 1 and 100
    }
}

int main() {
    srand(time(0));  // Initialize random number generator

    int n, W, count;
    char repeat;
    
    printf("--------Fractional Knapsack Problem--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    do {
        printf("Enter number of items: ");
        scanf("%d", &n);
        printf("Enter capacity of knapsack: ");
        scanf("%d", &W);

        int weights[n], values[n];
        generateRandomItems(weights, values, n);  // Generate random items

        printf("Generated Items:\n");
        for (int i = 0; i < n; i++) {
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, weights[i], values[i]);
        }

        count = 0;  // Reset iteration count
        fractionalKnapsack(weights, values, n, W, &count);  // Call knapsack function

        printf("Total iterations: %d\n", count);

        printf("Do you want to run again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
