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
        int n,k;
        cin>>n>>k;
        if(k&1){
            cout<<"YES"<<"\n";
            for(int i=1;i<=n;i++) {
                if(i&1)cout<<i<<" ";
                else cout<<i<<"\n";
            }
        }
        else {
            for(int i=2;i<=n;i+=4) {
                if((i+k)%4){cout<<"NO"<<"\n";return;}
            }
            cout<<"YES"<<"\n";
            for(int i=1;i<=n;i++) {
                if(i%4==1){cout<<i+1<<" ";}
                if(i%4==2){cout<<i-1<<"\n";}
                if(i%4==3){cout<<i<<" ";}
                if(i%4==0){cout<<i<<"\n";}
            }
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
