#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt=0;
char s[maxn];
struct node
{
	int fail,son[26],end;
}ac[maxn];
queue<int> q;
void insert(char s[])
{
	int l=strlen(s);
	int u=0;
	for(int i=0;i<l;i++)
	{
		if(!ac[u].son[s[i]-'a'])
		{
			ac[u].son[s[i]-'a']=++cnt;
		}
		u=ac[u].son[s[i]-'a'];
	}
	ac[u].end++;
}
void qiufail()
{
	for(int i=0;i<26;i++)
	{
		if(ac[0].son[i])
		{
			ac[ac[0].son[i]].fail=0;
			q.push(ac[0].son[i]);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			int v=ac[u].son[i];
			if(v)
			{
				ac[v].fail=ac[ac[u].fail].son[i];
				q.push(v);
			}
			else
			{
				ac[u].son[i]=ac[ac[u].fail].son[i];
			}
		}
	}
}
int cx(char s[])
{
	int l=strlen(s);
	int u=0,ans=0;
	for(int i=0;i<l;i++)
	{
		u=ac[u].son[s[i]-'a'];
		int t=u;
		while(t&&ac[t].end!=-1)
		{
			ans+=ac[t].end;
			ac[t].end=-1;
			t=ac[t].fail;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		insert(s);
	}
	qiufail();
	scanf("%s",s);
	printf("%d",cx(s));
	return 0;
}