#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

bool is_pal(const string &s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

void sol() {
    int n;
    cin >> n;

    unordered_set<string> st;

    int m = n - 1;              // 删除一个字符后剩下的长度
    int half = (m + 1) / 2;     // 只枚举回文串的前半部分

    string t(m, 'a');

    auto dfs = [&](auto &&self, int pos) -> void {
        if (pos == half) {
            // 根据前半部分生成完整回文串 t
            for (int i = 0; i < m / 2; i++) {
                t[m - 1 - i] = t[i];
            }

            // 枚举插入位置
            for (int p = 0; p <= m; p++) {
                // 枚举插入字符
                for (char c = 'a'; c <= 'z'; c++) {
                    string s;
                    s.reserve(n);

                    for (int i = 0; i < p; i++) s += t[i];
                    s += c;
                    for (int i = p; i < m; i++) s += t[i];

                    // 题目要求 S 本身不是回文串
                    if (!is_pal(s)) {
                        st.insert(s);
                    }
                }
            }

            return;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            t[pos] = c;
            self(self, pos + 1);
        }
    };

    dfs(dfs, 0);

    cout << st.size() % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();

    return 0;
}