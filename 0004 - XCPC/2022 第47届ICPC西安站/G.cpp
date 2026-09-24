// QOJ user: lnxbb
// Contest: 2022 �?7届ICPC西安�?// Problem: #5119. Perfect Word (5119)
// Submission: https://qoj.ac/submission/1660009
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int N = 1e5 + 10, B = 247, mod1 = 998244389, mod2 = 998244391;
struct Base {
    array<int, N> pow{};
    Base(int mod) {
        pow[0] = 1;
        for (int i = 1; i < N; ++i) pow[i] = 1LL * pow[i - 1] * B % mod;
    }
    const int operator[](int idx) const { return pow[idx]; }
} p1(mod1), p2(mod2);

struct Hash {
    vector<int> h1, h2; // 前缀哈希，h[0] = 0

    void build(const string& s) {
        int n = (int)s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = ( (long long)h1[i] * B + (s[i] - 'a' + 1) ) % mod1;
            h2[i + 1] = ( (long long)h2[i] * B + (s[i] - 'a' + 1) ) % mod2;
        }
    }

    static int merge(int x, int y) { return (x << 31) | y; } // 若担心溢出可改用 uint64_t

    // 0-based 闭区�?[l, r]
    int calc(int l, int r) const {
        int len = r - l + 1;
        int res1 = ( h1[r + 1] - 1LL * h1[l] * p1[len] % mod1 + mod1 ) % mod1;
        int res2 = ( h2[r + 1] - 1LL * h2[l] * p2[len] % mod2 + mod2 ) % mod2;
        return merge(res1, res2);
    }
};
    void sol() {
        int n;
        cin >> n;
        vector<string> s(n);
        for (auto &i : s) cin >> i;
        sort(s.begin(), s.end(), [&](const string &s1, const string &s2){return s1.size() < s2.size();});
        map<int, int> mp;
        int ans = 0;
        for (auto &t : s) {
            Hash h;
            h.build(t);
            cerr << t.size() << "\n";
            if (t.size() == 1) mp[h.calc(0, 0)] = 1, ans = 1;
            else {
                if (mp.find(h.calc(0, t.size() - 2)) != mp.end() && mp.find(h.calc(1, t.size() - 1)) != mp.end()) {
                    ans = max(ans, (int)t.size());
                    mp[h.calc(0, t.size() - 1)] = 1;
                }
            }
        }
        cout << ans;
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
</code>