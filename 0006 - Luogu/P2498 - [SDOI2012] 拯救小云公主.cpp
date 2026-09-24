#include<bits/stdc++.h>
using namespace std;
#define R register
int n,row,line;
int x[3020],y[3020];
int fa[3020];
const double eps=1e-4;
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
double jdz(double x)
{
	if(x>=0)
	{
		return x;
	}
	return -x;
}
double pf(double x)
{
	return x*x;
}
double jl(int i,int j)
{
	return pf(x[i]-x[j])+pf(y[i]-y[j]);
}
bool pd(double r)
{
	double dd=pf(2*r);
	for(int i=0;i<=n+1;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(jl(i,j)<=dd)
			{
				int f1=find(i);
				int f2=find(j);
				if(f1!=f2)
				{
					fa[f1]=f2;
				}	
			}	
		}
		if(x[i]-r<=1||y[i]+r>=line)
		{
			int f1=find(i);
			int f2=find(0);
			if(f1!=f2)
			{
				fa[f1]=f2;
			}	
		}
		if(x[i]+r>=row||y[i]-r<=1)
		{
			int f1=find(i);
			int f2=find(n+1);
			if(f1!=f2)
			{
				fa[f1]=f2;
			}	
		}
	}
	return find(0)!=find(n+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>row>>line;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	double ll=0,rr=min(row,line);
	while(jdz(ll-rr)>eps)
	{
		double mid=(ll+rr)/2;
		if(pd(mid))
		{
			ll=mid;
		}
		else
		{
			rr=mid;
		}
	}
	printf("%.2f",ll);
	return 0;
}