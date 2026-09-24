#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,h[N],w[N],fa[N],ans;
int cn,hd[N],to[N],nt[N];
char s[N];
vector<int>ed[N];
void dfs(int u)
{
	w[u]=w[fa[u]];
	if(s[u]=='(')w[u]=u;
	else if(w[u])h[u]=1+h[fa[w[u]]],w[u]=w[fa[w[u]]];
	for(int i=0;i<ed[u].size();i++)dfs(ed[u][i]);
}
signed main()
{
	scanf("%lld%s",&n,s+1);
	for(int i=2;i<=n;i++)
		scanf("%lld",&fa[i]),ed[fa[i]].push_back(i);
	dfs(1),ans=h[1];
	for(int i=2;i<=n;i++)
		h[i]+=h[fa[i]],ans^=(i*h[i]);
	printf("%lld\n",ans);
	return 0;
}