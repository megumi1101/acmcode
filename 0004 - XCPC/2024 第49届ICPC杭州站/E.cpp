// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÊù≠Â∑ûÁ´?// Problem: #9730. Elevator II (9730)
// Submission: https://qoj.ac/submission/1483248
// Language: C++23

#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define int long long
#define ll long long
int T,n,f,ma,sum,tot,cnt,bz[N],ans[N];
struct node{int l,r,id;}a[N],b[N],c[N];
bool cmp(node a,node b){return a.l<b.l;}
bool cmp1(node a,node b){return a.r>b.r;}
void solve(int x)
{
    int r=b[x+1].id-1;
    if(x==tot) r=n;
    int la=0;
    for (int i=b[x].id;i<=r;i++)
    {
        if(a[i].r>la) la=a[i].r,bz[a[i].id]=1,ans[++cnt]=a[i].id;
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>f;
        ma=sum=tot=cnt=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].l>>a[i].r,a[i].id=i;
            c[i]=a[i];
            ma=max(ma,a[i].r);
            sum+=a[i].r-a[i].l;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            if(a[i].l>b[tot].r) b[++tot]=(node){a[i].l,a[i].r,i};
            else b[tot].r=max(b[tot].r,a[i].r);
        }
        // for (int i=1;i<=n;i++) cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].id<<endl;
        // cerr<<"TIAOSHI   "<<tot<<endl;
        // for (int i=1;i<=tot;i++) cerr<<b[i].l<<" "<<b[i].r<<" "<<b[i].id<<endl;
        int w=0;
        for (int i=1;i<=tot;i++)
        {
            if(f>=b[i].l&&f<=b[i].r) {w=i;break;}
            if(f<b[i].l) {w=i;break;}
        }
        if(w==0) w=tot+1;
        for (int i=w;i<=tot;i++) solve(i);
        sort(a+1,a+n+1,cmp1);
        for (int i=1;i<=n;i++) 
        {
            if(bz[a[i].id]==0) ans[++cnt]=a[i].id;
        }
        for (int i=1;i<=n;i++)
        {
            if(f<c[ans[i]].l) sum+=c[ans[i]].l-f;
            f=c[ans[i]].r;
        }
        cout<<sum<<endl;
        for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
        for (int i=1;i<=n;i++) bz[i]=0;
    }
    return 0;
}
/*
3
3 5 2
1 4 13 6 8 11 14 2 7 10 3 15 9 5 12
2 3 0
1 6 4 3 5 2
2 3 1000000000
1 2 3 4 5 6
*/
</code>