#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,ind,fir[N],deep[N],id[N],topf[N],son[N],siz[N],fa[N];
struct Edge{int to,nxt;}e[N<<1];
struct node{int lc,rc,cnt;void cln(){lc=rc=cnt=0;}};
struct Segtree
{
	int tag[N<<2];node t[N<<2];
	void cln()
	{
	    memset(tag,0,sizeof tag);
		for(int i=0,h=N<<2;i<h;i++)t[i].cln();	
	}
	void pdn(int k,int l,int r)
	{
		if(!tag[k])return;
		int x=tag[k],mid=(l+r)>>1;tag[k]=0;
		tag[k<<1]=tag[k<<1|1]=x;
		t[k<<1]=(node){x,x,mid-l};
		t[k<<1|1]=(node){x,x,r-mid-1};
	}
	void update(int ul,int ur,int nl,int nr,int pos,int num)
	{
		if(ul<=nl&&nr<=ur){
			t[pos]=(node){num,num,nr-nl};
			tag[pos]=num;return;
		}
		pdn(pos,nl,nr);int mid=(nl+nr)>>1;
		if(ul<=mid)update(ul,ur,nl,mid,pos<<1,num);
		if(mid<ur)update(ul,ur,mid+1,nr,pos<<1|1,num);
		node ls=t[pos<<1],rs=t[pos<<1|1];
		t[pos]=(node){ls.lc,rs.rc,ls.cnt+rs.cnt+(ls.rc==rs.lc)};
	}
	node query(int al,int ar,int nl,int nr,int pos){
		if(al<=nl&&nr<=ar)return t[pos];
		pdn(pos,nl,nr);int cnt=0,mid=(nl+nr)>>1;node w1,w2;
		if(al<=mid){cnt++;w1=query(al,ar,nl,mid,pos<<1);}
		if(mid<ar){cnt+=2;w2=query(al,ar,mid+1,nr,pos<<1|1);}
		if(cnt==1)return w1;if(cnt==2)return w2;
		return (node){w1.lc,w2.rc,w1.cnt+w2.cnt+(w1.rc==w2.lc)};
	}
}sgtree;
void add(int a,int b,int pos){
	e[pos]=(Edge){b,fir[a]};fir[a]=pos;
}
void all_cln(){
	ind=0;sgtree.cln();
	memset(siz,0,sizeof siz);
	memset(fa,0,sizeof fa);
	memset(id,0,sizeof id);
	memset(fir,0,sizeof fir);
	memset(son,0,sizeof son);
	memset(topf,0,sizeof topf);
	memset(deep,0,sizeof deep);
}
void dfs1(int x,int f,int d){
	deep[x]=d;fa[x]=f;siz[x]=1;
	for(int i=fir[x];i;i=e[i].nxt)
	{
		int h=e[i].to;
		if(h!=f)
		{
			dfs1(h,x,d+1);siz[x]+=siz[h];
			if(siz[h]>siz[son[x]])son[x]=h;
		}
	}
}
void dfs2(int x,int tp)
{
	if(!x)return;topf[x]=tp;
	id[x]=++ind;dfs2(son[x],tp);
	for(int i=fir[x];i;i=e[i].nxt)
	{
		int h=e[i].to;if(h!=son[x]&&h!=fa[x])dfs2(h,h);
	}
}
void range_update(int x,int y,int num)
{
	while(topf[x]!=topf[y])
	{
		int tx=topf[x],ty=topf[y];
		if(deep[tx]<deep[ty]){swap(x,y);swap(tx,ty);}
		sgtree.update(id[tx],id[x],1,n,1,num);
		x=fa[tx];
	}
	if(deep[x]<deep[y])swap(x,y);
	sgtree.update(id[y],id[x],1,n,1,num);
}
int range_query(int x,int y){
	bool fg=0;
	node h,ans1=(node){0,0,0},ans2=(node){0,0,0};
	while(topf[x]!=topf[y])
	{
		int tx=topf[x],ty=topf[y];
		if(deep[tx]<deep[ty]){fg=!fg;swap(tx,ty);swap(x,y);}
		h=sgtree.query(id[tx],id[x],1,n,1);
		if(fg)
		    ans2=(node){h.lc,ans2.rc,ans2.cnt+h.cnt+(ans2.lc==h.rc)};
		else
			ans1=(node){ans1.lc,h.lc,ans1.cnt+h.cnt+(ans1.rc==h.rc)};
		x=fa[tx];
	}
	if(deep[x]<deep[y]){swap(x,y);fg=!fg;}
	h=sgtree.query(id[y],id[x],1,n,1);
	if(fg)ans2=(node){h.lc,ans2.rc,ans2.cnt+h.cnt+(ans2.lc==h.rc)};
	else ans1=(node){ans1.lc,h.lc,ans1.cnt+h.cnt+(ans1.rc==h.rc)};
	return ans1.cnt+ans2.cnt+(ans1.rc==ans2.lc);
}
int main(){
	int data;scanf("%d",&data);
	for(int i=1;i<=data;i++)
	{
		all_cln(); 
		int m;scanf("%d%d",&n,&m);
		for(int j=1;j<n;j++)
		{
			int a,b;scanf("%d%d",&a,&b);
			add(a,b,j);add(b,a,j+n-1);
		}
		dfs1(1,0,1);dfs2(1,1);
		for(int j=1;j<=n;j++)sgtree.update(id[j],id[j],1,n,1,-id[j]);
		for(int j=1;j<=m;j++)
		{
		    int opt,a,b;
			scanf("%d%d%d",&opt,&a,&b);
			if(opt&1)range_update(a,b,j);
			else printf("%d\n",range_query(a,b));
		}
	}
	return 0;
}