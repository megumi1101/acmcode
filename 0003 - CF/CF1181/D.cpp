#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    #define int long long
    const int N=5e5+10;
    int a[N],vis[N];
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            int x;cin>>x;vis[x]++;
            a[i]=(vis[x]-1)*m+x;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)a[i]-=i;
        for(int i=1;i<=n;i++)if(a[i]<0)cout<<"DF";
        for(int i=1;i<=q;i++){
            int k;cin>>k;
            if(k<=a[n]+n)k=k-n+(lower_bound(a+1,a+1+n,k-n)-1-a);
            if(k<0)cout<<k;
            cout<<(k-1)%m+1<<"\n";
        }
    }
}
