#include <bits/stdc++.h>
 
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    struct DynBitset {
        int n;
        std::vector<unsigned long long> a;
 
        DynBitset(int n_ = 0) { init(n_); }
 
        void init(int n_) {
            n = n_;
            a.assign((n + 63) >> 6, 0ull);
        }
 
        void set(int pos) { a[pos >> 6] |= 1ull << (pos & 63); }
        void reset(int pos) { a[pos >> 6] &= ~(1ull << (pos & 63)); }
        bool test(int pos) const { return (a[pos >> 6] >> (pos & 63)) & 1; }
 
        // 按位或
        void operator|=(const DynBitset &o) {
            for (size_t i = 0; i < a.size(); i++) a[i] |= o.a[i];
        }
 
        // popcount 总数
        int count() const {
            int res = 0;
            for (auto x : a) res += __builtin_popcountll(x);
            return res;
        }
 
        // 左移 k 位
        DynBitset& operator<<=(int k) {
            if (k <= 0 || n == 0) return *this;
            int blk = k / 64, off = k % 64;
            int m = (int)a.size();
            if (blk >= m) { // 全部清零
                std::fill(a.begin(), a.end(), 0ull);
                return *this;
            }
            if (off == 0) {
                for (int i = m - 1; i >= 0; i--) {
                    a[i] = (i - blk >= 0) ? a[i - blk] : 0ull;
                }
            } else {
                for (int i = m - 1; i >= 0; i--) {
                    unsigned long long lo = (i - blk >= 0) ? a[i - blk] : 0ull;
                    unsigned long long hi = (i - blk - 1 >= 0) ? a[i - blk - 1] : 0ull;
                    a[i] = (lo << off) | (hi >> (64 - off));
                }
            }
            // 清掉超出 n 的部分
            int r = n & 63;
            if (r) {
                unsigned long long mask = (1ull << r) - 1;
                a.back() &= mask;
            }
            return *this;
        }
        friend DynBitset operator<<(DynBitset x, int k) { return x <<= k; }
    };
 
 
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> ed(n + 1);
        for (int i = 2; i <= n; i++) {
            int x; cin >> x;
            ed[x].emplace_back(i);
        }
        int s = 10000000;
        vector<int> w(n + 1);
        auto dfs = [&] (auto &&dfs, int u, int dep) -> void {
            w[dep]++;
            if (!ed[u].size()) {
                s = min(s, dep);
            }
            for (auto v : ed[u]) {
                dfs(dfs, v, dep + 1);
            }
        };
 
        dfs(dfs, 1, 1);
        int siz = min(k, n - k);
        DynBitset B(siz + 5);
        B.set(0);
        int sum = 0;
        for (int i = 1; i <= s; i++) {
            B |= B << w[i];
            sum += w[i];
        }
        
        int x = k, y = n - k;
        if (x > y) swap(x, y);
        for (int i = 0; i <= x; i++) {
            if (B.test(i) == 1 && sum - i <= y) {
                cout << s << "\n";
                return;
            }
        }
        cout << s - 1 << "\n";
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
