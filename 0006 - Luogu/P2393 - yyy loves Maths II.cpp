#include<bits/stdc++.h>
using namespace std;
#define db long double
db x,y;
int main()
{
	while(scanf("%Lf",&x)!=EOF)
	{
		y+=x*1000000;
	}
	printf("%.5Lf",y/1000000);
	return 0;
}