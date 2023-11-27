#include <stdio.h>
#include <stdlib.h>

// Declaring the GCD functions for iteration and recursion
int gcd_iteration(int a, int b);

int gcd_recursive(int a, int b);

int main(void)
{
  // Creating the variables that will adopt the user input
  int a, b;

  // Asking for the user input
  printf("Input the first interger: ");
  scanf("%d", &a);
  // Loop that makes sure that the value is positive and also a number
  if (a<=0){
	printf("Invalid value inputted, aborting\n");
	return 1;
  }
  else if (a != 1){
	printf("Invalid value inputted, aborting\n");
        return -1;
  }

  printf("\nInput the second interger: ");
  scanf("%d", &b);
  if (b<=0){
        printf("Invalid value inputted, aborting\n");
        return 1;
  }
  else if (b != 1){
        printf("Invalid value inputted, aborting\n");
        return -1;
  }
 
  // Utilising the function to get the answers
  int ans_recursive = gcd_recursive(a, b);
  int ans_iteration = gcd_iteration(a, b);

  printf("Iterative answer= %d\n", ans_iteration);
  printf("Recursive answer= %d\n", ans_recursive);

  return 0;
}

// Function that finds the greatest common denominator using iteration
int gcd_iteration(int a, int b)
{
  int temp;
  while(b != 0)
  {
  	temp = b;
        b = a % b;
        a = temp;
  }

  return a;
}

// Function that finds the greatest common denominator using recursion
int gcd_recursive(int a, int b)
{
  if(b==0)
  {
        return a;
  }
  else
  {
        return gcd_recursive(b, a%b);
  }
}
