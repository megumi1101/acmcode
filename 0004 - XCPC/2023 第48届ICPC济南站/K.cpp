// QOJ user: xbbbz
// Contest: 2023 �?8届ICPC济南�?// Problem: #7904. Rainbow Subarray (7904)
// Submission: https://qoj.ac/submission/1528744
// Language: C++23

#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int l,r,cnt;
    long long sum;
    node(int l_=-1,int r_=-1) :l(l_),r(r_),cnt(0),sum(0ll) {}
}tree[30000001];
int cnt=0;
void push_up(int p){
    tree[p].cnt=0,tree[p].sum=0ll;
    if(~tree[p].l) tree[p].cnt+=tree[tree[p].l].cnt,tree[p].sum+=tree[tree[p].l].sum;
    if(~tree[p].r) tree[p].cnt+=tree[tree[p].r].cnt,tree[p].sum+=tree[tree[p].r].sum;
}
void modify(int p,int l,int r,int x,bool opt){ //opt 0/1 -> +/- 
    if(l==r&&l==x){
        if(!opt) tree[p].cnt++,tree[p].sum+=x;
        else tree[p].cnt--,tree[p].sum-=x;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        if(!~tree[p].l) tree[p].l=cnt++,tree[tree[p].l]=node();
        modify(tree[p].l,l,mid,x,opt);
    }
    if(mid<x){
        if(!~tree[p].r) tree[p].r=cnt++,tree[tree[p].r]=node();
        modify(tree[p].r,mid+1,r,x,opt);
    }
    push_up(p);
}
int query(int p,int l,int r,int x){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(!~tree[p].l) return query(tree[p].r,mid+1,r,x);
    if(!~tree[p].r) return query(tree[p].l,l,mid,x);
    if(tree[tree[p].l].cnt>=x) return query(tree[p].l,l,mid,x);
    else return query(tree[p].r,mid+1,r,x-tree[tree[p].l].cnt);
}
int querycnt(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tree[p].cnt;
    int mid=(l+r)>>1, res=0; // 避免和全局 cnt 混名
    if(~tree[p].l&&x<=mid) res+=querycnt(tree[p].l,l,mid,x,y);
    if(~tree[p].r&&y> mid) res+=querycnt(tree[p].r,mid+1,r,x,y); // 右边界用 y>mid 更直�?    return res;
}
long long querysum(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tree[p].sum;
    int mid=(l+r)>>1;
    long long sum=0ll;
    if(~tree[p].l&&x<=mid) sum+=querysum(tree[p].l,l,mid,x,y);
    if(~tree[p].r&&y> mid) sum+=querysum(tree[p].r,mid+1,r,x,y);
    return sum;
}
int a[500001];
const int R=(int)1e9+(int)5e5+1;
int main(){
    int T,n,i,j,ans,mid,p,q;
    long long k,sump,sumq;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>k,cnt=1,tree[0]=node();
        for(int i=1;i<=n;++i) cin>>a[i],a[i]=a[i]-i+n;
        i=1,j=1,ans=1;
        for(;j<=n;++j){
            modify(0,1,R,a[j],false);
            mid=query(0,1,R,(j-i+2)>>1);
            p=querycnt(0,1,R,1,mid),q=(j-i+1)-p;
            sump=querysum(0,1,R,1,mid),sumq=querysum(0,1,R,mid+1,R);
            while(i<=j&& ( (long long)mid*p - sump + (long long)sumq - (long long)mid*q > k )){
                modify(0,1,R,a[i],true),++i;
                int len = j - i + 1;              // �?加上窗口判空
                if(len==0) break;                 // �?为空就停止收缩，避免对空树取中位�?                mid=query(0,1,R,(len+1)>>1);
                p=querycnt(0,1,R,1,mid),q=len-p;
                sump=querysum(0,1,R,1,mid),sumq=querysum(0,1,R,mid+1,R);
            }
            ans=max(j-i+1,ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

</code>