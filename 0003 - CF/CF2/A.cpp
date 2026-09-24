#include <bits/stdc++.h>

using namespace std;

namespace xbbbz {
    const int inf =1e9;
    map <string ,int>mp,vis;
    void sol() {
        int n;
        int ans=-inf;
        string sans;
        string s[1005];
        vector<int> a(1005);
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin >> s[i] >> a[i];
            mp[s[i]] += a[i];
        }
        for(auto it=mp.begin();it!=mp.end();it++) {
            if(ans < it->second)ans=it->second,sans=it->first;
        }
        int res=0;
        for(auto it=mp.begin();it!=mp.end();it++) {
            if(ans == it->second) {
                vis[it->first]=1;
                res++;
            }
            it->second = 0;
        }
        if(res>1) {
            for(int i=1;i<=n;i++) {
                mp[s[i]]+=a[i];
                if(mp[s[i]]>=ans&&vis[s[i]]) {
                    sans=s[i];
                    break;
                }
            }
        }  
        cout<<sans;
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
}

int main() {
    return xbbbz::main(), 0;
}
