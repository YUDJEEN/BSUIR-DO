#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void main() {
	double x, y, z, t, a, b, c;
	x = 14.26;
	y = -1.22;
	z = -0.035;
	a = 2 * cos(x - M_PI / 6);
	b = 0.5 + (pow(sin(y), 2));
	c = (1 + (pow(z, 2)) / (3 - pow(z, 2) / 5));
	t = a / b * c;
	printf("%f", t);
}
