#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char id;
    int deadline, profit;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Job Sequencing Function
void jobSequencing(Job jobs[], int n, int* count) {
    (*count)++; // Increment iteration count

    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    char result[maxDeadline];
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%c ", jobs[slot[i]].id);
        }
    }
    printf("\n");
}

// Randomly Generate Job Sequence
void generateRandomJobs(Job jobs[], int n) {
    for (int i = 0; i < n; i++) {
        jobs[i].id = 'A' + i;
        jobs[i].deadline = rand() % 3 + 1; // Random deadline between 1 and 3
        jobs[i].profit = rand() % 100 + 1; // Random profit between 1 and 100
    }
}

int main() {
    srand(time(0)); // Initialize random number generator

    int n, count;
    char repeat;
    
    printf("--------Job Sequencing Problem--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    do {
        printf("Enter the number of jobs (max 10): ");
        scanf("%d", &n);

        Job jobs[n];
        generateRandomJobs(jobs, n); // Generate random job data

        printf("Generated Jobs: ");
        for (int i = 0; i < n; i++) {
            printf("(%c, Deadline: %d, Profit: %d) ", jobs[i].id, jobs[i].deadline, jobs[i].profit);
        }
        printf("\n");

        count = 0;  // Reset iteration count
        jobSequencing(jobs, n, &count); // Job sequencing function

        printf("Total iterations: %d\n", count);

        printf("Do you want to run again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
