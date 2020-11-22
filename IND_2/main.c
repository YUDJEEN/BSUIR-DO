#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main() {
    double x,y,z,k;
    printf("k value: \n");
    scanf("%lf", &k);
    printf("z value: \n");
    scanf("%lf", &z);

    x = z*((k<1) ? k*z*z : z+1);
    y = pow(log(x*x+1)+cos(x+1),exp(k*x));

    printf("%5.5lf - branch %s", y, (k<1) ? "k<1" : "k>=1");

}