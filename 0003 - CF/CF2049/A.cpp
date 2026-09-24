#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,sum=0;
        cin>>n;
        int a[n+10];
        a[0]=0;
        for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        if(sum==0) {cout<<"0\n"; return ;}
        int res=0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=0&&a[i-1]==0)res++;
            if(a[i-1]!=0&&a[i]==0)res++;
        }
        if(res<=2)cout<<"1\n";
        else cout<<"2\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    } 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
