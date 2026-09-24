#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    priority_queue<int, vector<int>, greater<int>> q1,q2;
    void sol() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int res=0;
        s='1'+s+'1';
        for(int i=1;i<s.size();i++) {
            if(s[i]=='1'&&s[i-1]=='1')res++;
        }
        if(res)cout<<"YES\n";
        else cout<<"NO\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
}
int main() {
    return xbbbz::main(), 0;
}
