#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0;
        if (c & 1) res = 3;
        if (b) {
            if (res == 3) res = 1;
            else res = 2 * (b & 1);
        }
        if (a <= res) {
            res -= a;
        }
        else {
            a -= res;
            res = a & 1;  
        }
        cout << res << "\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
