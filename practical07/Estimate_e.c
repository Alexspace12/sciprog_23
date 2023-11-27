#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declaring the factorial function
int factorial(int n);

int main(){

  // Creating a variable that will take the user input
  int order;
  // Creating the doubles that will be used to calculate the value of e, and allocate space
  double x = 1, *terms;

  // Statement used to take user input and loop that checks if input is usable 
  printf("Enter polynomial order: ");
  if(scanf("%d", &order) != 1){
  	printf("Incorrect entry\n");
        exit(-1);
  }

  // Allocation of space
  terms = malloc(order * sizeof(double));
  int i;

  // Loop used to produce the error message
  if (order<0){
    	factorial(order);
  } 
  else{
  	// Loop used to calculate the value of each term
     	for(i=0; i<order; i++){
        	terms[i] = 1.0/(double) factorial(i+1);
        	printf("order = %d, e term = %1.20lf\n", i+1, terms[i]);
  	}
  

  	// The value of each term is added onto the x value (e)
  	for(i=0; i<order; i++){
        	x += terms[i];
  	}

  	// frees up terms array from memory
  	free(terms);         
  
  	// Printing the approxmated value of e, and it's difference from the actual value
  	printf("e = %.15lf\ndifference = %e\n", x , (x-exp(1.0)));
 
  }
  return 0;                        

}

  // Function that calculates the factorial of each term
  // int was used in this case as long would cause a change in the value at the 
  // 13th polynomial which would cause the difference to be negative
  // The strange occurance after the 15th polynomual is that the values at  17th, 18th, etc are negative
  // This is mainly due to an overflow caused by the limited range of the 'int' data type 
  int factorial(int n)
  {
    if(n<0){
        printf("Error: n is negative.\n");
        return -1;
    }
    else if(n==0){
        return 1;
    }
    else{
        return(n*factorial(n-1));
    }
  }
