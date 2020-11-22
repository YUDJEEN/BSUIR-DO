#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main (){
 
    int a;
    double z;
    printf("Alpha angle = ");
    scanf (" %d" , &a);
    
    printf("\n\nz1 = 2sin^2(3pi-2a)cos^2(5pi+2a) \n");
    z = 2*(pow(sin(3*M_PI - 2*a),2.0)*(pow(cos(5*M_PI+2*a),2.0)));
    printf("Result: z1 = %5.5lf \n" , z); 
 
    printf("\n\nz2 = 1/4 - 1/4sin(5/2pi-8a) \n");
    z = (1. - ((sin(2.5*M_PI - 8*a))))/4.;
    printf("Result: z2 = %5.5lf \n" , z);
 
    return 0;
}