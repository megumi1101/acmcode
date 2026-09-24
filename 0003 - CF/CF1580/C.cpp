#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    // #define int long long
    // const int inf = 1e18;
    const int N = 2e5 + 10;
    int n, m;
    int a[N], b[N], las[N], c[N];
    int sum[500][500];
    void sol() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            a[i] = min(a[i], m);
            b[i] = min(b[i], m);
        }
        int B = sqrt(m);
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int op, k;
            cin >> op >> k;
            op = 3 - op * 2;
            if (op == 1) las[k] = i;
            if (a[k] + b[k] > B) {
                for (int j = las[k]; j <= m; j += a[k] + b[k]) {
                    if(j + a[k] <= m) c[max(j + a[k], i)] += op; 
                    if(j + a[k] + b[k] <= m) c[max(j + a[k] + b[k], i)] -= op; 
                }
            }
            else {
                for (int j = las[k] + a[k]; j < las[k] + a[k] + b[k]; j++) {
                    sum[a[k] + b[k]][j % (a[k] + b[k])] += op;
                }
            }
            ans += c[i];
            int res = 0;
            for (int j = 1; j <= B; j++) {
                res += sum[j][i % j];
            }
            cout << ans + res << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin>>T;
        while(T--) sol();
    }
    // #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
