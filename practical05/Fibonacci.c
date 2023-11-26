#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function that produces the fibonacci sequence based on the number inputted by the user
void fibonacci(int *a, int *b);

int main() {

  // Defining the variables to be used 
  int n, i;
  // Declaring the first 2 variables of the fibonacci sequence 
  int F0 = 0, F1 = 1;

  // Code used to ask for user input 
  printf("Enter the value of n for the Fibonacci series: ");
  scanf("%d", &n);

  // Loop used to ensure an applicable value was inputted
  if(n < 1) {
        printf("Please enter a positive value. \n");
        exit(-1);
  }
  
  printf("The Fibonaccis sequence observed at %d is: \n", n);
  printf("%d  ", F0);
  // Only print F1 if n is greater than 1
  if (n > 1) {
    printf("%d  ", F1);
  }

  for (i = 2; i <= n; i++) {
        fibonacci(&F0, &F1);
        printf("%d  ", F1);
 	
	if((i+1)%10 == 0) printf("\n");
  }

  return 0;
}

void fibonacci(int *a, int *b) {
        int FN;
        FN = *a + *b;
        *a = *b;
        *b = FN;
}
