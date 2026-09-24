// QOJ user: xbbbz
// Contest: 2022 �?7届ICPC杭州�?// Problem: #5311. Master of Both (5311)
// Submission: https://qoj.ac/submission/1450465
// Language: C++23

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int ALP = 26;

struct Node {
    int ch[ALP];
    int pass_cnt, end_cnt;
    Node() {
        memset(ch, -1, sizeof(ch));
        pass_cnt = end_cnt = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Node> tr;
    tr.reserve(1'100'000 + 5);
    tr.emplace_back(); // root

    static long long cnt[ALP][ALP];
    long long base_inv = 0;

    auto new_node = [&]() {
        tr.emplace_back();
        return (int)tr.size() - 1;
    };

    for (int id = 1; id <= n; ++id) {
        string s; cin >> s;
        int u = 0;
        for (char cc : s) {
            int c = cc - 'a';

            // 枚举所有其它字�?d，看 d 分支是否存在
            for (int d = 0; d < ALP; ++d) if (d != c) {
                int v = tr[u].ch[d];
                if (v != -1 && tr[v].pass_cnt > 0) {
                    cnt[d][c] += tr[v].pass_cnt;
                }
            }

            if (tr[u].ch[c] == -1) tr[u].ch[c] = new_node();
            u = tr[u].ch[c];
            tr[u].pass_cnt += 1;
        }

        // 结束点：固定逆序
        base_inv += (tr[u].pass_cnt - tr[u].end_cnt - 1);
        tr[u].end_cnt += 1;
    }

    while (q--) {
        string t; cin >> t;
        int pos[ALP];
        for (int i = 0; i < ALP; ++i) pos[t[i]-'a'] = i;

        long long ans = base_inv;
        for (int x = 0; x < ALP; ++x)
            for (int y = 0; y < ALP; ++y)
                if (pos[x] > pos[y]) ans += cnt[x][y];

        cout << ans << "\n";
    }
    return 0;
}

</code>