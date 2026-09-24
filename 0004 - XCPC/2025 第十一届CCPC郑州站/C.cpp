#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
struct node{
    int l,r,tag,max,mark;
    node(int l_=-1,int r_=-1) :l(l_),r(r_),tag(0),max(-1),mark(-1) {}
}tree[1600001];
node push_up(node l,node r){
    node p(l.l,r.r);
    if(l.max<r.max) p.max=r.max,p.mark=r.mark;
    else p.max=l.max,p.mark=l.mark;
    return p;
}
void push_down(int p){
    int tag=tree[p].tag;
    tree[p].tag=0;
    tree[p<<1].max+=tag,tree[(p<<1)|1].max+=tag;
    tree[p<<1].tag+=tag,tree[(p<<1)|1].tag+=tag;
}
void build(int p,int l,int r){
    tree[p]=node(l,r);
    if(l==r) tree[p].max=0,tree[p].mark=l;
    else build(p<<1,l,(l+r)>>1),build((p<<1)|1,((l+r)>>1)+1,r),tree[p]=push_up(tree[p<<1],tree[(p<<1)|1]);
}
void modify(int p,int l,int r,int v){
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].tag+=v,tree[p].max+=v;
        return;
    }
    int mid=(tree[p].l+tree[p].r)>>1;
    push_down(p);
    if(l<=mid) modify(p<<1,l,r,v);
    if(mid<r) modify((p<<1)|1,l,r,v);
    tree[p]=push_up(tree[p<<1],tree[(p<<1)|1]);
}
node query(int p,int l,int r){
    if(l<=tree[p].l&&tree[p].r<=r) return tree[p];
    int mid=(tree[p].l+tree[p].r)>>1;
    node ans;
    push_down(p);
    if(l<=mid&&mid<r) ans=push_up(query(p<<1,l,r),query((p<<1)|1,l,r));
    else
        if(mid<r) ans=query((p<<1)|1,l,r);
        else ans=query(p<<1,l,r);
    return tree[p]=push_up(tree[p<<1],tree[(p<<1)|1]),ans;
}
struct line{
    int l,r,d;
    line(int l_=1e9+7,int r_=1e9+7,int d_=-1) :l(l_),r(r_),d(d_) {}
};
bool operator<(const line& a,const line& b){
    return a.l<b.l;
}
set<line> Chtholly;
int a[200001];
int main(){
    int T,n,m;
    node ans;
    line temp;
    set<line>::iterator it;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m,build(1,1,n<<1),Chtholly.clear();
        for(int i=1;i<=n;++i) cin>>a[i],modify(1,a[i],a[i],1),Chtholly.emplace(i,i,a[i]);
        ans=query(1,1,n<<1),cout<<ans.mark<<' '<<ans.max<<'\n';
        for(int l,r,d;m--;){
            cin>>l>>r>>d;
            it=Chtholly.upper_bound(line(l,r,d));
            --it;
            if(it->l<=l&&r<=it->r){
                temp=*it,it=Chtholly.erase(it);
                modify(1,temp.d+l-temp.l,temp.d+r-temp.l,-1);
                if(temp.l<l) Chtholly.insert(line(temp.l,l-1,temp.d));
                if(r<temp.r) Chtholly.insert(line(r+1,temp.r,temp.d+r+1-temp.l));
            }
            else{
                temp=*it,it=Chtholly.erase(it);
                modify(1,temp.d+l-temp.l,temp.d+temp.r-temp.l,-1);
                if(temp.l<l) Chtholly.insert(line(temp.l,l-1,temp.d));
                for(;it!=Chtholly.end()&&it->r<=r;) modify(1,it->d,it->d+it->r-it->l,-1),it=Chtholly.erase(it);
 
                // ---- 唯一改动：< r -> <= r ----
                if(it!=Chtholly.end()&&it->l<=r){
                    temp=*it,it=Chtholly.erase(it);
                    modify(1,temp.d,temp.d+r-temp.l,-1);
                    if(r<temp.r) Chtholly.insert(line(r+1,temp.r,temp.d+r+1-temp.l));
                }
            }
            modify(1,d,d+r-l,1),Chtholly.insert(line(l,r,d)),ans=query(1,1,n<<1),cout<<ans.mark<<' '<<ans.max<<'\n';
        }
    }
    return 0;
}
/*
1
8 8
7 6 6 4 3 8 5 3
4 4 4
6 8 6
1 1 7
4 7 4
6 7 6
2 7 5
1 5 7
1 6 8
*/
