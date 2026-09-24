#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
struct node{
    int l,r;
    long long cnt,tag;
    node(int l_=-1,int r_=-1) :l(l_),r(r_),cnt(0ll),tag(0ll) {}
}tree[4000001];
 
void push_up(int p){ tree[p].cnt=tree[p<<1].cnt+tree[(p<<1)|1].cnt; }
 
void push_down(int p){
    if(!tree[p].tag) return;
    long long tag=tree[p].tag; tree[p].tag=0ll;
    tree[p<<1].tag+=tag; tree[(p<<1)|1].tag+=tag;
    tree[p<<1].cnt+=(tree[p<<1].r-tree[p<<1].l+1)*tag;
    tree[(p<<1)|1].cnt+=(tree[(p<<1)|1].r-tree[(p<<1)|1].l+1)*tag;
}
 
void build(int p,int l,int r){
    tree[p]=node(l,r);
    if(l!=r){
        int mid=(l+r)>>1;
        build(p<<1,l,mid);
        build((p<<1)|1,mid+1,r);
        push_up(p);
    }
}
 
void modify(int p,int l,int r,long long v){
    if(l<=tree[p].l && tree[p].r<=r){
        tree[p].tag+=v;
        tree[p].cnt+=(tree[p].r-tree[p].l+1)*v;
        return;
    }
    push_down(p);
    int mid=(tree[p].l+tree[p].r)>>1;
    if(l<=mid) modify(p<<1,l,r,v);
    if(mid<r)  modify((p<<1)|1,l,r,v);
    push_up(p);
}
 
long long query(int p,int l,int r){
    if(l<=tree[p].l && tree[p].r<=r) return tree[p].cnt;
    push_down(p);
    int mid=(tree[p].l+tree[p].r)>>1;
    long long res=0;
    if(l<=mid) res+=query(p<<1,l,r);
    if(mid<r)  res+=query((p<<1)|1,l,r);
    return res;
}
 
struct line{
    int l,r,c;
    line(int l_=1000000007,int r_=1000000007,int c_=-1):l(l_),r(r_),c(c_) {}
};
bool operator<(const line& a,const line& b){ return a.l<b.l; }
 
set<line> Chtholly;
long long tagc[1000005];
 
// split at pos, return iterator to segment whose l==pos
set<line>::iterator split(int pos){
    if(pos>tree[1].r) return Chtholly.end();
    auto it = prev(Chtholly.upper_bound(line(pos)));
    if(it->l==pos) return it;
    int L=it->l, R=it->r, C=it->c;
    Chtholly.erase(it);
    Chtholly.insert(line(L,pos-1,C));
    return Chtholly.insert(line(pos,R,C)).first;
}
 
int get_color(int x){
    auto it = prev(Chtholly.upper_bound(line(x)));
    return it->c;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q; 
    cin>>n>>q;
    Chtholly.clear();
    Chtholly.insert(line(1,n,1));
    build(1,1,n);
 
    string opt; int x,y,z;
    while(q--){
        cin>>opt;
        if(opt=="Color"){
            cin>>x>>y>>z;
            auto itR = split(y+1);
            auto itL = split(x);
            // 对 [x,y] 里的每段先兑现老颜色增量
            for(auto it=itL; it!=itR; ){
                modify(1,it->l,it->r, tagc[it->c]);
                it = Chtholly.erase(it);
            }
            // 插入新颜色段，并扣回新颜色的增量
            Chtholly.insert(line(x,y,z));
            modify(1,x,y,-tagc[z]);
        }else if(opt=="Add"){
            cin>>x>>y;
            tagc[x]+=y;
        }else{ // Query
            cin>>x;
            cout<< query(1,x,x) + tagc[get_color(x)] << '\n';
        }
    }
    return 0;
}
