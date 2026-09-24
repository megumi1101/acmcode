#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9;
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    void sol() {
        int n;
        cin >> n;
        int d = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int j = 0; j < 30; j++) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if ((a[i] >> j) & 1) cnt++;
            }
            d = gcd(d, cnt);
        }
        for (int i = 1; i <= n; i++) {
            if (d % i == 0) cout << i << " ";
        }
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
/*
01101
00111
11001
10011
*/
