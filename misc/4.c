// W = mg
#include<stdio.h>
int main () {
	float g, m, W;
	printf("Enter m = ");
	scanf("%f", &m);
	printf("Enter g = ");
	scanf("%f", &g);
	W = m * g;
	printf("W = %f\n", W);
	return 0;
}
