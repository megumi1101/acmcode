#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
using u64 = unsigned long long;
    struct Bit {
        int n;
        vector<u64> a;
        Bit (int n_ = 0) {
            n = n_;
            init(n);
        }
        void init(int n) {
            a.assign(n / 64 + 5, 0);
        }
        void add(int x) {
            if (x > 64) {
                for (int i = 0; i <= n; i += x) {
                    a[i >> 6] |= 1ull << (i % 64);
                }
            }
            else {
                int now = lcm(x, 64);
                vector<u64> tmp(now);
                for (int i = 0; i <= n && (i >> 6) < now; i += x) {
                    tmp[i >> 6] |= 1ull << (i % 64);
                }
                for (int i = 0; i < a.size(); i++) {
                    a[i] |= tmp[i % now];
                }
            }
        }
        int getans() {
            int ans = 0;
            a[0] ^= 1;
            for (int i = n + 1; i < 64 * a.size(); i++) {
                a[i >> 6] |= 1ull << (i % 64);
                a[i >> 6] ^= 1ull << (i % 64);
            }
            for (int i = 0; i <= n / 64; i++) {
                u64 x = a[i] & (a[i] >> 1) & (a[i] >> 2);
                ans +=  __builtin_popcountll(x);
                ans += (a[i] & (1ull << 62)) && (a[i] & (1ull << 63)) && (a[i + 1] & (1ull << 0));
                ans += (a[i] & (1ull << 63)) && (a[i + 1] & (1ull << 0)) && (a[i + 1] & (1ull << 1));
            }
            return ans;
        }
    };

    void sol() {
        int n, s;
        cin >> n >> s;
        Bit bit(n);
        for (int i = 0; i < s; i++) {
            int x;
            cin >> x;
            bit.add(x);
        }
        cout << bit.getans();

    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}