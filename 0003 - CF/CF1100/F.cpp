#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,ans;
void op()
{
	freopen("treeless.in","r",stdin);
	freopen("treeless.out","w",stdout);
}
int inline read()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
struct node
{
	int p,pos;
}xx[maxn][32];
void ins(int x,int k)
{
	int pos=k;
	for(int i=0;i<=30;i++)xx[k][i]=xx[k-1][i];
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!xx[k][i].p){xx[k][i].p=x;xx[k][i].pos=pos;break;}
			else if(pos>xx[k][i].pos)swap(xx[k][i].p,x),swap(xx[k][i].pos,pos);
			x^=xx[k][i].p;
		}	
	}
}
int cx(int l,int r)
{
	int res=0;
	for(int i=30;i>=0;i--)
	{
		if(xx[r][i].pos<l)continue;
		res=max(res,res^xx[r][i].p);
	}
	return res;
}
int main()
{
	//op();
	scanf("%d",&n);int x;
	for(int i=1;i<=n;i++)scanf("%d",&x),ins(x,i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
			int l,r,cl,cr;
			l=read();r=read();
			ans=cx(l,r);
			printf("%d\n",ans);
	}
	return 0;
}
