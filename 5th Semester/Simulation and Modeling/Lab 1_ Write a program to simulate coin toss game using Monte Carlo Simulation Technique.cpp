#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int head = 0, tail = 0, itr;
    double r;
    srand(time(NULL));
    printf("Enter the number of iterations for Prashant's Coin Flip Simulation\n");
    scanf("%d", &itr);
    for (int i = 1; i <= itr; i++)
    {
        r = (double) rand() / RAND_MAX;
        if (r <= 0.5)
            head++;
        else
            tail++;
    }
    printf("Number of Heads: %d\n", head);
    printf("Number of Tails: %d\n", tail);
    if (head > tail)
        printf("Heads wins by %d\n", head - tail);
    else
        printf("Tails wins by %d\n", tail - head);
}
