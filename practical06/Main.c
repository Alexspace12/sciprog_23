#include <stdio.h>

// Calling function in order to avoid the implicit declaration of function erro
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main(){
  // Defining necessary values and creating matrices that match the values
  int n = 5, p = 3, q = 4;
  double A[n][p], B[p][q], C[n][q];
   
  // Creating integrals that will be used in loops
  int i, j;

  // For loop that creates a 5x4 matrix of 0s
  for(i=0; i<n; i++){
  	for(j=0; j<q; j++){
        	C[i][j] = 0;
        }
  }

  // For loop that creates a 5x4 matrix of Aij values
  for (i=0; i<n; i++){
        for (j=0; j<p;  j++){
        	A[i][j] = i + j;
        }
  }

  // For loop that creates 3x4 matrix of Bij
  for (i = 0; i < p; i++){
        for (j = 0; j < q; j++){
        	B[i][j] = i - j;
        }
  }

  // Using the matmult function from the Matmult file
  matmult(n, p, q, A, B, C);

  // Loops that print out the resulting matrices 
  printf("\nMatrix A\n");
  for (i=0; i<n; i++){
  	for (j=0; j<p; j++){
        	printf("%3.0f\t", A[i][j]);
        }
        printf("\n");
  }

  printf("\nMatrix B\n");
  for (i=0; i<p; i++){
        for (j=0; j<q; j++){
        	printf("%3.0f\t", B[i][j]);
        }
        printf("\n");
  }

    printf("\nMatrix C\n");
    for (i=0; i<n; i++){
        for (j=0; j<q; j++){
        	printf("%3.0f\t", C[i][j]);
        }
        printf("\n");
  }

  return 0;
}
