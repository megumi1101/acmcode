#include<cstdio>
#include<cmath>
float a,b,c,d,z;
float mm(float x)
{
	z=a*x*x*x+b*x*x+c*x+d;
	return z;
}
int main()
{
scanf("%f%f%f%f",&a,&b,&c,&d);
for(float i=-100;i<=100;i+=0.01)
	{
		float j;
		j=0.01+i;
		if(mm(i)>0&&mm(j)<0||mm(j)>0&&mm(i)<0)
		{
			float m;
			m=(i+j)/2;
			printf("%.2f ",m);
		}
	}return 0;
}
