#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char a[maxn],b[maxn];
int la,lb,p[maxn];
int main()
{
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	p[1]=0;
	int j=0;
	for(int i=2;i<=lb;i++)
	{
		while(j&&b[i]!=b[j+1])j=p[j];
		if(b[i]==b[j+1])j++;
		p[i]=j;
	}
	j=0;
	for(int i=1;i<=la;i++)
	{
		while(j&&a[i]!=b[j+1])j=p[j];
		if(a[i]==b[j+1])j++;
		if(j==lb)printf("%d\n",i-lb+1),j=p[j];
	}
	for(int i=1;i<=lb;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
}