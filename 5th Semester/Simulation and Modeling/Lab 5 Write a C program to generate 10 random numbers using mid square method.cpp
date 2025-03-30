#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// #include<conio.h> // conio.h is not standard, you can remove it

int main()
{
    long int i, s, x, y, z, nd, seed;
    int n;

    seed = 61;

    // Prashant's Mid-Square Method for Random Number Generation
    printf("Prashant's Mid-Square Method to generate random numbers\n");
    printf("How many random numbers to generate? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        s = (seed * seed);        
        y = s / 10.0;
        z = y / 100.;        
        x = (int)((y / 100.0 - z) * 100.);
        printf("Generated number %d: x = %d\n", i, x);
        seed = x;
    }
    return 0;
}
