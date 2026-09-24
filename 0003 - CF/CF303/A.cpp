#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    void sol() {
        int n;
        cin>>n;
        n--;
        if(n&1)cout<<"-1";
        else {
            for(int i=0;i<=n;i++)cout<<i<<" ";
            cout<<"\n";
            for(int i=1;i<=n;i++)cout<<i<<" ";
            cout<<"0 \n";
            for(int i=0;i<=n;i++)cout<<(i+i+1)%(n+1)<<" ";
            cout<<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int T=1;
        // cin>>T;
        while(T--)sol();
    }
}
int main() {
    return xbbbz::main(), 0;
}
