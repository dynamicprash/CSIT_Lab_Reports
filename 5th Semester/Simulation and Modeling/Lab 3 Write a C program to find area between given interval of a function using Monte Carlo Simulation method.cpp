#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F(x) (x*x)
#define xl 1
#define yl 1
#define xu 2
#define yu 4
#define N 10000

int main()
{
    int xran, yran, n = 0, a = 1, b = 2, c = 4, i;
    float area;
    srand(time(0));

    // Prashant's Monte Carlo Simulation for Area Estimation
    printf("Prashant's Monte Carlo Method for Area Estimation\n");
    for (i = 1; i <= N; i++)
    {
        xran = (rand() % (xu - xl + 1)) + xl;
        yran = (rand() % (yu - yl + 1)) + yl;   
        if (xran * xran <= yran)
            n++;
    }
    printf("Number of points within the area: %d\n", n);
    area = c * (b - a) * (float)n / N;
    printf("Estimated area using Monte Carlo = %f\n", area);

    return 0;
}
