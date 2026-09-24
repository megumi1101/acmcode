#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int maxx;
struct node
{
	int num,bh;
	friend bool operator<(node x,node y)
	{
		return x.num<y.num;
	}
};
priority_queue<node> q;
int num[maxn];
node cl()
{
	while(q.top().num!=num[q.top().bh])
	{
		node tmp=q.top();
		q.pop();
		tmp.num=num[tmp.bh];
		q.push(tmp);
	}
	node res=q.top();
	q.pop();
	return res;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num[i]);
		if(i>1)
		{
			maxx=max(num[i],maxx);
		}
	}
	int re=min(num[1]-(n-num[1])%2,n-2*maxx);
	if(re<=0)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
		printf("%d\n",re);
	}
	num[1]-=re;
	for(int i=1;i<=m;i++)
	{
		q.push((node){num[i],i});
	}
	n-=re;
	int zz=1;
	while(n)
	{
		while(num[zz]<=0)zz++;
		int nn=num[zz];
		while(num[zz]--)
		{
			printf("%d\n",zz);
		}
		while(nn--)
		{
			n--;
			node tmp=cl();
			if(tmp.num*2>=n)
			{
				printf("%d\n",tmp.bh);
				tmp.num--;
				num[tmp.bh]--;
				if(tmp.num>0)
				{
					q.push(tmp);
				}
			}
			else
			{
				q.push(tmp);
				while(num[zz]<=0)zz++;
				num[zz]--;
				printf("%d\n",zz);
			}
			n--;
		}
	}
	int mm=1;
	for(int i=1;i<=re;i++)
	{
		cout<<1<<"\n";
	}
	return 0;
}
/*5 3 2 1 2*/