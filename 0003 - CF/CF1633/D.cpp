#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    vector<int> tun;
    void init() {
        int n = 1000;
        tun.assign(n + 5, 1000000);
        tun[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i + i / j <= n) tun[i + i / j] = min(tun[i] + 1, tun[i + i / j]);
            }
        }
    }
 
    void sol() {
        int n, k;
        cin >> n >> k;
        int tmp = 0;
        vector<int> b(n + 1), c(n + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) cin >> c[i], tmp += c[i];
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += tun[b[i]], b[i] = tun[b[i]];
        if (k > sum) {
            cout << tmp << "\n";
        }
        else {
            vector<int> f(k + 5);
            for (int i = 1; i <= n; i++) {
                for (int j = k; j >= b[i]; j--) {
                    f[j] = max(f[j - b[i]] + c[i], f[j]);
                }
            }
            cout << f[k] << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        cin >> T;
        while (T--) sol();
 
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
