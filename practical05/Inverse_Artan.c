#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Functionn that calculates the maclaurin series of arc tanh to a precision defined by the delta variable.
double artanh1(const double x, const double delta);

// Function that calculates arc tanh using logarithms
double artanh2(const double x);

// Main function to drive the program
int main() {

    double delta, x;
    int length = 1000;

    double atanh1[length], atanh2[length];
    
    // Prompt user for delta input
    printf("Enter a real positive number for delta: ");
     
    // Loop used to check if the correct value was inputted
    if (scanf("%lf", &delta) != 1) {
        printf("Incorrect entry\n");
        exit(-1);
    }

    x = -0.9;
    // Value used to index the array
    int i = 0;

    // Loop that interates as long as x is less than or equal to 0.9 and the number of iterations isn't greater than the length of the atanh arrays. In each iteration the 
    while(x<0.91 && i<length){
        atanh1[i] = artanh1(x, delta);
        atanh2[i] = artanh2(x);
        printf("x=%.2f, diff=%.10f\n", x, fabs(atanh1[i] - atanh2[i]));
        i++;
        x+=0.01;
    }

    return 0;
}

// Function to calculate arctanh using Maclaurin series
double artanh1(const double x,const double delta) {
    double sum = 0.0;
    double term;
    int n = 0;
    do {
        term = pow(x, 2*n + 1) / (2*n + 1);
        sum += term;
        n++;
    } while (fabs(term) > delta);
    return sum;
}

// Function to calculate arctanh using natural logarithms
double artanh2(const double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}