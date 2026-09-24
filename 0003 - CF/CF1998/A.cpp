#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    void sol() {
        int x, y, k;
        cin >> x >> y >> k;
        if(k & 1) {
            cout << x << " " << y << "\n" ;
        }
        for(int i=1;i<=k/2;i++) {
            cout << x - i <<  " " << y << "\n";
            cout << x + i <<  " " << y << "\n";
        }
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
