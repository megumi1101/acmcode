#include <bits/stdc++.h>

using namespace std;

namespace xbbbz {
    #define int long long
    const int inf =1e9;
    map <char ,int>mp;
    void sol() {
        string s;
        cin>>s;
        int ans=s.size();
        for(char ch : s){
            ans+=mp[ch]*2;
            mp[ch]++;
        }
        cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}
