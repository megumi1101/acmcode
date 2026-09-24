// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCæ²ˆé˜³ç«?// Problem: #6624. String Problem (6624)
// Submission: https://qoj.ac/submission/1711820
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
// vector<int> get_pi(string s) {
//     int n = (int)s.size();
//     vector<int> pi(n, 0);
//     for (int i = 1; i < n; i++) {
//         int j = pi[i - 1];
//         while (j && s[i] != s[j]) j = pi[j - 1];
//         if (s[i] == s[j]) j++;
//         pi[i] = j;
//     }
//     return pi;
// }
// const int mod1 = 998244389;
// const int mod2 = 998244391;
// const int B = 257;
// struct Base {
//     array<int, 1000005> pow{};
//     Base(int mod) {
//         pow[0] = 1;
//         for (int i = 1; i < 1000005; i++) {
//             pow[i] = pow[i - 1] * B % mod;
//         }
//     }
//     const int operator[](int idx) const {return pow[idx];}
// }p1(mod1), p2(mod2);
// struct Hash {
//     vector<int> h1, h2;
//     void build(const string &s) {
//         int n = (int)s.size();
//         h1.assign(n + 1, 0);
//         h2.assign(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             h1[i + 1] = (h1[i] * B + (s[i] - 'a' + 1)) % mod1;
//             h2[i + 1] = (h2[i] * B + (s[i] - 'a' + 1)) % mod2;
//         }
//     }

//     static int merge(int x, int y)  {return (x << 31) | y;} 
//     int calc(int l, int r) const {
//         int len = r - l + 1;
//         int res1 = (h1[r + 1] - h1[l] * p1[len] % mod1 + mod1) % mod1;
//         int res2 = (h2[r + 1] - h2[l] * p2[len] % mod2 + mod2) % mod2;
//         return merge(res1, res2);
//     }
// };
    void sol() {
        string s;
        cin >> s;
        int n = s.size();
        // Hash h;
        // h.build(s);
        int l = 0;
        int r = 0;
        int lstx = 0;
        int lsty = 0;
        vector<int> pi(n, 0);
        auto get = [&](int x, int y) -> int {
            if (x == lstx) {
                // cerr << 1 << "\n";
                for (int i = lsty + 1; i <= y; i++) {
                    // cerr << i << "\n";
                    int j = pi[i - 1];
                    while (j && s[i] != s[j + lstx]) j = pi[j + lstx - 1];
                    if (s[i] == s[j + lstx]) j++;
                    pi[i] = j;
                }
                lsty = y;
            } else {
                for (int i = lstx; i <= x; i++) {
                    pi[i] = 0;
                } 
                lstx = x;
                for (int i = x + 1; i <= y; i++) {
                    int j = pi[i - 1];
                    while (j && s[i] != s[j + lstx]) j = pi[j + lstx - 1];
                    if (s[i] == s[j + lstx]) j++;
                    pi[i] = j;
                }
                lsty = y;
            }
            return pi[y];
        };
        // auto get = [&](int x, int y) -> int {
        //     int tl = 1, tr = y - x;
        //     int ans = 0;
        //     while (tl <= tr) {
        //         int mid = (tl + tr) >> 1;
        //         if (x == 1 && y == 6) {
        //             cerr << "mid == " << mid << "\n";
        //         }
        //         if (h.calc(x, x + mid - 1) == h.calc(y - mid + 1, y)) tl = mid + 1, ans = mid;
        //         else tr = mid - 1;
        //     }
        //     return ans;
        // };
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {cout << "1 1\n"; continue;}
            if (s[i] > s[l]) {
                l = i;
                r = i;
                cout << l + 1 << " " << r + 1 << "\n";
                continue;
            }
            if (i == l + 1) {
                r = i;
                cout << l + 1 << " " << r + 1 << "\n";
                continue;
            }
            
            while (1) {
                int len = get(l, i - 1);
                // cerr << "l == " << l << " i - 1 == " << i << " len == " << len << "\n"; 
                if (s[i] <= s[l + len]) break;
                l = i - len;
            }
            cout << l + 1 << " " << i + 1 << "\n";
               
        }
        // cerr << get(1, 6) << '\n';
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
    return Xbbbz::main(), 0;
}
</code>