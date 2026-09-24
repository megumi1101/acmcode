#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
const int mod = 1e9 + 7, inf = 1e9;
vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}
 
int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
void sol() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> cnt(30);
    for (int i = n; i >= 1; i--) {
        for (int bit = 0; bit < 30; bit++) {
            if ((b[i] >> bit) & 1) {
                cnt[bit] = i;
                for (int j = 1; j <= i; j++) {
                    b[j] -= C(i, j) * (1LL << bit) % mod;
                    if (b[j] < 0) b[j] += mod;
                }
            }
        }
    }
 
    vector<int> a(n + 1);
    for (int bit = 0; bit < 30; bit++) {
        for (int i = 1; i <= cnt[bit]; i++) {
            a[i] |= (1 << bit);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e5);
    int t;
    cin >> t;
    while (t--) sol();
}
