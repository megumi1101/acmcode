#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+10);
        map<int,int>mp;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++) {
            mp[(i-1)*(n-i)+n-1]++;
            if(i<n) {
                mp[i*(n-i)]+=a[i+1]-a[i]-1;
            }
        }
        while(q--) {
            int x;
            cin>>x;
            cout<<mp[x]<<" ";
        }
        cout<<"\n";
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
