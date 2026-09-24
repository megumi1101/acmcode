#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using std::vector;
#define ls rt<<1
#define rs rt<<1|1
#define mid ((l+r)>>1)
#define rep(a,b,c) for(int a=b;a<=c;a++) 
const int maxn=1e5+1;
struct Edge {
	int u,v;
}e[maxn<<1];
int head[maxn],ecnt;
inline void addedge(int u,int v) { e[++ecnt].v=v;e[ecnt].u=head[u];head[u]=ecnt; }
inline void add(int u,int v) { addedge(u,v); addedge(v,u); }
int fa[maxn],dep[maxn],top[maxn],son[maxn],siz[maxn],vis[maxn],val[maxn<<2],idx[maxn],id,n,m,a,b,q,bcj[maxn],fx,fy;
inline int find(int x) { return bcj[x]==x?x:bcj[x]=find(bcj[x]); }
inline void jh(int &x,int &y) { x^=y^=x^=y; }
inline void pushdown(int rt,int l,int r) { if(val[rt]!=(r-l+1)) return; val[ls]=(mid-l+1); val[rs]=(r-mid); }
inline void pushup(int rt) { val[rt]=val[ls]+val[rs]; }
inline void update(int rt,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return(void)(val[rt]=r-l+1);
	pushdown(rt,l,r);
	if(L<=mid) update(ls,l,mid,L,R);
	if(R>mid) update(rs,mid+1,r,L,R);
	pushup(rt);
}
inline int query(int rt,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return val[rt];
	pushdown(rt,l,r);
	int ANS=0;
	if(L<=mid) ANS+=query(ls,l,mid,L,R);
	if(R>mid) ANS+=query(rs,mid+1,r,L,R);
	return ANS;
}
inline void upd(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) jh(x,y);
		update(1,1,n,idx[top[x]],idx[x]);
		x=fa[top[x]];
	}
	if(dep[y]<dep[x]) jh(x,y);
	update(1,1,n,idx[x]+1,idx[y]);
}
inline int qry(int x,int y) {
	int cnt=0;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) jh(x,y);
		cnt+=query(1,1,n,idx[top[x]],idx[x]);
		x=fa[top[x]];
	}
	if(dep[y]<dep[x]) jh(x,y);
	cnt+=query(1,1,n,idx[x],idx[y]);
	return cnt;
}
inline void dfs1(int x,int f) {
	siz[x]=1; dep[x]=dep[f]+1; fa[x]=f;
	for(int i=head[x],v;i;i=e[i].u) {
		v=e[i].v; if(dep[v]) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
inline void dfs2(int x,int topf) {
	idx[x]=++id; top[x]=topf; if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=head[x],v;i;i=e[i].u) {
		v=e[i].v; if(dep[v]<dep[x]||v==son[x]) continue;
		if(fa[v]==x) dfs2(v,v);
	}
}
inline void dfs3(int x) {
	for(int i=head[x],v;i;i=e[i].u) {
		v=e[i].v; if(v==fa[x]) continue;
		if(fa[v]==x) dfs3(v);
		else if(dep[v]>dep[x]) continue;
		else if(!((dep[x]-dep[v])&1)) upd(x,v);
	}
}
inline void dfs4(int x) {
	for(int i=head[x],v;i;i=e[i].u) {
		v=e[i].v; if(v==fa[x]) continue;
		if(fa[v]==x) dfs4(v);
		else if(dep[v]>dep[x]) continue;
		else if((dep[x]-dep[v])&1) {
			int cnt=qry(x,v)-query(1,1,n,idx[v],idx[v]);
			if(cnt>0) upd(x,v);
		}
	}
}
inline int LCA(int x,int y) {
	while(top[x]!=top[y]) dep[top[x]]>dep[top[y]]?x=fa[top[x]]:y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
inline int dis(int x,int y) {
	return (dep[x]+dep[y]-(dep[LCA(x,y)]<<1));
}
int main() {
	scanf("%d %d",&n,&m);
	rep(i,1,n) bcj[i]=i;
	rep(i,1,m) {
		scanf("%d %d",&a,&b); add(a,b);
		fx=find(a); fy=find(b);
		bcj[fy]=fx;
	}
	rep(i,1,n) {
		if(dep[i]) continue;
		dfs1(i,0); dfs2(i,i); dfs3(i); dfs4(i);
	}
	scanf("%d",&q);
	rep(i,1,q) {
		scanf("%d %d",&a,&b);
		int lca=LCA(a,b);
		if(find(a)!=find(b)) puts("No");
		else {
			if(dis(a,b)&1) puts("Yes");
			else if((qry(a,b)-query(1,1,n,idx[lca],idx[lca]))>0) puts("Yes");
			else puts("No");
		}
	}
}
//
