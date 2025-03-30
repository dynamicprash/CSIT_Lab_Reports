#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246
int main()
{
   int itr = 0;
   double x, y;
   int i, count = 0;
   double z;
   double pi;
   printf("Prashant's Pi Estimation using Monte Carlo Method\n");
   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d", &itr);   
   srand(SEED);
   count = 0;
   for (i = 0; i < itr; i++)
   {
      x = (double)rand() / RAND_MAX;
      y = (double)rand() / RAND_MAX;
      z = x * x + y * y;
      if (z <= 1.0) 
         count++;
   }
   pi = (double)count / itr * 4;
   printf("Estimated value of Pi after %d iterations = %f\n", itr, pi);
   return 0;
}
