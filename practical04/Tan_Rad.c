#include <stdio.h>
#include <math.h>

// Defining the number of trapezoids. N was not used as it causes a problem with the macro 'N'.
#define NUM_POINTS 12

// Stating the functions before the main
double deg_to_rad(double deg);
double trap_rule(double TanArray[], int num_points);

int main() {
    // Creating the array that stores the tan values
    double TanArray[NUM_POINTS+1];
    double deg, rad;

    // Loop that goes from 0 to 60 in intervals of 5
    // Coverts the values from degrees to radian using the function de_to _rad
    int i;
    for (i = 0; i <= NUM_POINTS; i++) {
        deg = i * 5.0;
        rad = deg_to_rad(deg);
        // Saving the converted values into the array
        TanArray[i] = tan(rad);
    }

    // Obtaining the approximate and exact values of the integral
    double integral_approx = trap_rule(TanArray, NUM_POINTS);
    double integral_exact = log(2.0);

    //Comparing the approximation the the log(2) by calculating the difference in the values
    printf("Trapezoidal rule approximation: %.5f\n", integral_approx);
    printf("Actual value: %.5f\n", integral_exact);
    printf("Difference: %.5f\n", fabs(integral_approx - integral_exact));

    return 0;
}

// Function that converts from degrees to radians
double deg_to_rad(double deg) {
    return (deg * M_PI) / 180.0;
}

// Function that calculates the area under the curve
double trap_rule(double TanArray[], int num_points) {
    double width = deg_to_rad(60.0) / num_points;
    double area = (TanArray[0] + TanArray[num_points]) / 2.0;
    
    int i;
    for (i = 1; i < num_points; i++) {
        area += TanArray[i];
    }

    area *= width;
    return area;
}

