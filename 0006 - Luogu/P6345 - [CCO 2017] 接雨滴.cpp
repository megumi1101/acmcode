#include<bits/stdc++.h>
using namespace std;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int a[505],n;
bitset<25005>f,g;
int main()
{
	n=rid();
	for(int i=1;i<=n;i++)a[i]=rid();
	sort(a+1,a+1+n);f[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)g|=(f<<(a[j]-a[i]));
		f|=g;
	}
	for(int i=0;i<=25000;i++)if(f[i])printf("%d ",i);
	return 0;
}
