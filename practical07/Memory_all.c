#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Declaring the functions before the main.
int *allocatearray(int n);

void fillwithones(int *array, int n);

void printarray(int *array, int n);

void freearray(int *array);

int main(){

  int *a, array;
  
  printf("Size of array wanted: ");
  scanf("%d", &array);

  a = allocatearray(array);
  fillwithones(a, array);
  printarray(a, array);
  freearray(a);

  return 0;
}

// Function used to allocate the size of the array based on the user input
int *allocatearray(int n){
  int *p;
  p = (int *) malloc(n * sizeof(int));
  if(p==NULL){printf("Error in allocation\n");}
  return p;
}

// Function that fills the matrix with values of 1
void fillwithones(int *array, int n){
  int i; 
  for(i=0; i<n; i++){
        array[i] = 1;
  }
}

// Function that prints every value in the array
void printarray(int *array, int n){
  int i;
  for(i=0; i<n; i++){
        printf("a[%d]: %d\n", i, array[i]);
  }
}

// Function that empties the array
void freearray(int *array){
  free(array);
  array = NULL;
}


