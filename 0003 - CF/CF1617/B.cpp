#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    vector<int> getnxt(string s) {
        int n = s.size();
        vector<int>p(n);
        for(int i=1;i<n;i++) {
            int j = p[i-1];
            while(j&&s[i]!=s[j])j=p[j-1];
            if(s[i]==s[j])j++;
            p[i]=j;
        }
        return p;
    }
    void sol() {
        int a;
        cin>>a;
        if(a&1){
            if((a-1)%4==0)cout<<a/2-1<<" "<<a/2+1<<" 1\n";
            else cout<<a/2-2<<" "<<a/2+2<<" 1\n";
        }
        else {
            cout<<a/2-1<<" "<<a/2<<" 1\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
int main() {
    return xbbbz::main(), 0;
}
