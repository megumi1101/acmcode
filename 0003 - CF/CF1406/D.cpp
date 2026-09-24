#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    int up2(int x) {
        if(x<=0)return x/2;
        return (x-1)/2+1;
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int n;
        cin>>n;
        int a[n+10],b[n+10];
        int res=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++) {
            b[i]=a[i]-a[i-1];
            res+=abs(b[i]);
        }
        int t1=a[1],t2=a[n];
        cout<<up2((t1+t2+res)/2)<<"\n";
        int q;
        cin>>q;
        while(q--) {
            int l,r,x;
            cin>>l>>r>>x;
            if(l==1) {
                t1+=x;
            }
            else {
                res+=abs(b[l]+x)-abs(b[l]);
                b[l]+=x;
            }
            if(r==n) {
                t2+=x;
            }
            else {
                res+=abs(b[r+1]-x)-abs(b[r+1]);
                b[r+1]-=x;
            }
            cout<<up2((t1+t2+res)/2)<<"\n";
        }
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
