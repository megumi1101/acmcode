#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        int a[n+1],p[n+1];
        for(int i=1;i<=n;i++)cin>>p[i];
        for(int i=1;i<=n;i++)cin>>a[i];
        int res=0,t1=0,t2=0;
        for(int i=1;i<=min(2*n,k);i++) {
            t1=max(t1,res+(k-i+1)*a[x]);
            res+=a[x];
            x=p[x];
            
        }
        res=0;
        for(int i=1;i<=min(2*n,k);i++) {
            t2=max(t2,res+(k-i+1)*a[y]);
            res+=a[y];
            y=p[y];
        }
        if(t1>t2) cout<<"Bodya"<<"\n";
        else if(t1<t2) cout<<"Sasha"<<"\n";
        else cout<<"Draw"<<"\n"; 
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
