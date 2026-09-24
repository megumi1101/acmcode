#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    priority_queue<int, vector<int>, greater<int>> q1,q2;
    void sol() {
        int n;
        cin>>n;
        vector<int>a(n+10,0);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        sort(a.begin()+1,a.begin()+1+n);
        int x;
        for(int i=1;i<=n;i++) {
            if(i==1)x=a[i];
            else x=(x+a[i])/2;
        }
        cout<<x<<"\n";
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
