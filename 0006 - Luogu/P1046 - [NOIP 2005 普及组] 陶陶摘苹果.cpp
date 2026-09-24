#include<cstdio>
int a[11],c,m;
int main()
{
	for(int i=1;i<=10;i++)
	{
	scanf("%d",&a[i]);
	}
	scanf("%d",&c);
	for(int i=1;i<=10;i++)
	{
		if(c+30>=a[i])
			m++;
	}
	printf("%d",m);
	return 0;	
}