#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 * This program generates a random number and prints whether
 * it's positive, zero, or negative.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	srand(time(0));
	n = rand() - RAND_MAX / 2;
/* Check if n is positive, zero, or negative and print the corresponding message */		       
	  if (n > 0)
	  {
		  printf("The number %d is positive\n", n);
	  }
	  else if (n == 0)
	  {
		  printf("The number %d is zero\n", n);
	  }
	  else{
		  printf("The number %d is negative\n", n);
	  }
	return (0);
}
