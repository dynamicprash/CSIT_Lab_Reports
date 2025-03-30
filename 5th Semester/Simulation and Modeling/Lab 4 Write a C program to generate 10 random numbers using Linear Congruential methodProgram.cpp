#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x0, x, a, c, M = 101;
    x0 = 31, a = 17, c = 13;
    double r;

    // Prashant's Linear Congruential Generator for Random Numbers
    printf("Prashant's Linear Congruential Generator to generate random numbers\n");
    for (int i = 1; i <= 15; i++)
    {
        x = (a * x0 + c) % M;
        r = (double)x / M;
        printf("Generated random number %d: %f\n", i, r);
        x0 = x;
    }
    return 0;
}
