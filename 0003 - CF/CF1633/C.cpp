#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int hc, dc, hm, dm;
        cin >> hc >> dc >> hm >> dm;
        hm--;hc--;
        int k, w, a;
        cin >> k >> w >> a;
        for (int i = 0; i <= k; i++) {
            int x = hc + i * a;
            int y = dc + (k - i) * w;
            if (hm / y <= x / dm) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
 
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
