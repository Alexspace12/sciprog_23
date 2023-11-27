// Function used to determine the elements of C
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q])
{
  // Loop intergers
  int i, j, k;
  // The loops go from highest to the lowest
  for (i = 0; i < n; i++){
  	for (j = 0; j < q; j++){
            for (k=0; k<p; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
  }
}
