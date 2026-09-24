#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    int a[301][301];
    void sol() {
        int n,k;
        cin>>n>>k;
        if(k%n) cout<<"2\n";
        else cout<<"0\n";
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!k)break;
                a[j][(i+j)%n] = 1;
                k--;
            }
            if(!k)break;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        cin>>T;
        while (T--) {
            sol();
        }
        
    }
}
int main() {
    return xbbbz::main(), 0;
}
