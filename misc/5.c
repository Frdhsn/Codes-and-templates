// P = mv
#include<stdio.h>
int main () {
	float v, m, P;
	printf("Enter m = ");
	scanf("%f", &m);
	printf("Enter v = ");
	scanf("%f", &v);
	P = m * v;
	printf("P = %f\n", P);
	return 0;
}
