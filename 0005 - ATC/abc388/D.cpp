// AtCoder user: lnxbb
// Contest: abc388
// Problem: abc388_d
// Submission: https://atcoder.jp/contests/abc388/submissions/61697253
// Language: C++ 20 (gcc 12.2)

#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int a[n+5],d[n+5];
        a[0]=0;d[0]=0;
        for(int i=1;i<=n;i++)cin>>a[i], d[i]=a[i]-a[i-1];
        int x=0;
        for(int i=1;i<=n;i++) {
            x+=d[i];
            if(x>=n-i) {
                cout<<x-n+i<<" ";
                d[i+1]+=1;
            }
            else {
                d[i+1]+=1;
                d[i+x+1]-=1;
                cout<<"0 ";
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
        // init();
        while(T--) {
            sol();
        }
    } 
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}