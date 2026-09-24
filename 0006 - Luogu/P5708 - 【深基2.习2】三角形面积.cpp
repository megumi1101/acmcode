#include<cstdio>
#include <math.h>
int main()
{
	float a,b,c,d,e;
	scanf("%f%f%f",&a,&b,&c);
	d=(a+b+c)/2;
	e=(d-a)*(d-b)*(d-c)*d;
	printf("%.1f",sqrt(e));
	return 0;
}