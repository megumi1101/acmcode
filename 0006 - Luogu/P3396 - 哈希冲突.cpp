#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5e4+10;
int inline rd()
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
int n,m,a[N],ans[400][400],sz;
void update(int x,int y)
{
	for(int p=1;p<=sz;p++)
		ans[p][x%p]=ans[p][x%p]-a[x]+y;
	a[x]=y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=rd();
	sz=sqrt(n);
	for(int p=1;p<=sz;p++)
		for(int i=1;i<=n;i++)
			ans[p][i%p]+=a[i];
	while(m--)
	{
		int x,y;
		char op[2];scanf("%s",op);x=rd();y=rd();
		if(op[0]=='A')
		{
			if(x<=sz)printf("%d\n",ans[x][y]);
			else
			{
				int res=0;
				for(int i=y;i<=n;i+=x)res+=a[i];
				printf("%d\n",res);
			}
		}
		else update(x,y);
	}
	return 0;
} 