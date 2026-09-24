#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long y;
        cin >> n >> y;
        vector<int> c(n);
        int M = 0;
        for (int i = 0; i < n; ++i) { cin >> c[i]; M = max(M, c[i]); }
 
        // 原价频次与前缀和
        vector<long long> cntA(M + 1, 0), pref(M + 1, 0);
        for (int v : c) ++cntA[v];
        for (int i = 1; i <= M; ++i) pref[i] = pref[i-1] + cntA[i];
 
        long long best = LLONG_MIN;
 
        // x = 2..M 以及 x = M+1（代表所有更大的 x）
        for (int x = 2; x <= M + 1; ++x) {
            int maxK = (M + x - 1) / x; // ceil(M/x)
            long long income = 0;       // sum k * cntB[k]
            long long reuse  = 0;       // sum min(cntB[k], cntA[k])
 
            for (int k = 1; k <= maxK; ++k) {
                int L = (k - 1) * x + 1;
                int R = min(M, k * x);
                long long cntBk = pref[R] - pref[L - 1]; // in ((k-1)x, kx]
                if (!cntBk) continue;
                income += 1LL * k * cntBk;
                if (k <= M) reuse += min(cntBk, cntA[k]);
            }
            long long need_new = (long long)n - reuse;
            long long total = income - y * need_new;
            best = max(best, total);
        }
 
        cout << best << "\n";
    }
    return 0;
}
