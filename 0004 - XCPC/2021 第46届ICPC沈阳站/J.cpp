// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCæ²ˆé˜³ç«?// Problem: #6621. Luggage Lock (6621)
// Submission: https://qoj.ac/submission/1711005
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
vector<int> dis(10000, 100000000);
void init () {
    int n = 1e4;
    vector<vector<int>> ed(n);
    array<int, 4> a;
    for (int i = 0; i < n; i++) {
        a = {i / 1000, i / 100 % 10, i / 10 % 10, i % 10};
        for (int l = 0; l < 4; l++) {
            for (int r = 0; r < 4; r++) {
                for (int op = 0; op < 2; op++) {
                    int t = op;
                    if (!t) t--;
                    auto b = a;
                    for (int k = l; k <= r; k++) {
                        b[k] = (a[k] + 10 + t) % 10;
                    }
                    int x = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
                    ed[i].push_back(x);
                }
            }
        }
    }

    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> q;
    q.emplace(dis[0], 0);
    while (!q.empty()) {
        auto[cost, u] = q.top();
        q.pop();
        if (dis[u] == cost) {
            for (auto v : ed[u]) {
                if (dis[u] + 1 < dis[v]) {
                    dis[v] = dis[u] + 1;
                    q.emplace(dis[v], v);
                }
            }
        }
    }
}
    void sol() {
        array<int, 4> t1, t2;
        int x, y;
        cin >> x >> y;
        t1 = {x / 1000, x / 100 % 10, x / 10 % 10, x % 10};
        t2 = {y / 1000, y / 100 % 10, y / 10 % 10, y % 10};
        for (int i = 0; i < 4; i++) {
            t2[i] = (t2[i] - t1[i] + 10) % 10;
        }
        x = t2[0] * 1000 + t2[1] * 100 + t2[2] * 10 + t2[3];
        cout << dis[x] << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        init();
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>