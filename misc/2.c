// a = (v-u)/t;
#include<stdio.h>
int main () {
	float a, v, u, t;
	printf("Enter v = ");
	scanf("%f", &v);
	printf("Enter u = ");
	scanf("%f", &u);
	printf("Enter t = ");
	scanf("%f", &t);
	a = (v - u) / t;
	printf("a = %f\n", a);
	return 0;
}
