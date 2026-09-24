// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCæ­å·ç«?// Problem: #9733. Heavy-light Decomposition (9733)
// Submission: https://qoj.ac/submission/1483616
// Language: C++23

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct node{
    int l,r,cnt;
    node(int l_=-1,int r_=-1) :l(l_),r(r_),cnt(r_-l_+1) {}
}a[100001];
bool operator<(const node& a,const node& b){
    return a.cnt>b.cnt;
}
map<int,int> mark;
int f[100001];
int main(){
    int T,n,k;
    bool flag;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>k,mark.clear(),flag=false;
        for(int i=0,x,y;i<k;++i){
            cin>>x>>y,a[i]=node(x,y),++mark[a[i].cnt];
            for(int j=x+1;j<=y;++j) f[j]=j-1;
        }
        sort(a,a+k);
        f[a[0].l]=0;
        for(int i=1;i<k;++i){
            if(a[i].cnt==a[0].cnt) f[a[i].l]=a[0].l;
            else{
                f[a[i].l]=a[0].r-a[i].cnt;
                if(f[a[i].l]!=a[0].l) flag=true;
            }
        }
        if(mark.rbegin()->second>1&&!flag){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int i=1;i<=n;++i) cout<<f[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
/*
1
9 2
1 5
6 9
*/
</code>