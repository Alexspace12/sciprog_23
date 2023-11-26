#include <stdio.h>
#include <math.h>


int main(){

//Letting a and b equal to the desired values
double a = 0;
double b = (M_PI/3.0);

//Getting the first part of the sum
double Sum = 0;
Sum = (tan(a) + tan(b));

//Setting N to 12 as desired
int N = 12;

//Creating the multiple used on the end points
double width = (b - a)/(double)N;	

int i;
//For loop that generates the 11 equidistant points
for ( i = 1; i < N; i++) {
        double x = a + i * width;
        Sum += 2*tan(x);
    }

double integral_approx = (Sum * width)/2;
double integral_exact = log(2.0);

//Comparing the approximation the the log(2) by calculating the difference in the values
printf("Trapezoidal rule approximation: %.5f\n", integral_approx);
printf("Actual value: %.5f\n", integral_exact);
printf("Difference: %.5f\n", fabs(integral_approx - integral_exact));

return 0;
}
