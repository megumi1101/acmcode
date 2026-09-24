// AtCoder user: lnxbb
// Contest: code-festival-2017-qualb
// Problem: code_festival_2017_qualb_f
// Submission: https://atcoder.jp/contests/code-festival-2017-qualb/submissions/32771061
// Language: C++ (GCC 9.2.1)

#include<bits/stdc++.h>
using namespace std;
int r,b,g,cnt;
struct node
{
	int a[60],sz;
	node(){memset(a,0,sizeof(a)),sz=1;};
	friend bool operator<(const node &x,const node &y)
	{
		int i;for(int i=1;i<=max(x.sz,y.sz);i++)if(x.a[i]!=y.a[i])return x.a[i]<y.a[i];
		return x.a[i]<y.a[i];
	}
}xx[60];
void print(int x)
{
	if(x==1)printf("a");
	if(x==2)printf("b");
	if(x==3)printf("c");
}
int main()
{
	//freopen("beargguy.in","r",stdin);
	//freopen("beargguy.out","w",stdout);
	scanf("%d%d%d",&r,&b,&g);
	for(int i=1;i<=r;i++)xx[++cnt].a[1]=1;
	for(int i=1;i<=b;i++)xx[++cnt].a[1]=2;
	for(int i=1;i<=g;i++)xx[++cnt].a[1]=3;
	while(cnt!=1)
	{
		sort(xx+1,xx+1+cnt);
		for(int i=1;i<=xx[cnt].sz;i++)xx[1].a[xx[1].sz+i]=xx[cnt].a[i];
		xx[1].sz+=xx[cnt].sz;cnt--;
	}
	for(int i=1;i<=xx[1].sz;i++)print(xx[1].a[i]);
	return 0;
} 