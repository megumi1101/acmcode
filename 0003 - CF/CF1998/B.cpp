#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n+10);
        for(int i=1;i<=n;i++)cin>>a[i],a[i]--;
        for(int i=1;i<=n;i++){
            if(a[i])cout<< a[i] <<" ";
            else cout << n << " ";
        }
        cout<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return xbbbz::main(), 0;
}
