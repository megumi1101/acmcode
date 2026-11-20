#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e18;
const int N = 1e6 + 10;
int ch[N][26], cnt = 0;
vector<vector<int>> vis(N);
vector<int> fa(N), pos(N);

void ins(string s, int id) {
    int u = 0;
    for (auto c : s) {
        int x = c - 'a';
        if (ch[u][x] == -1) {
            ch[u][x] = ++cnt;
            fa[cnt] = u;
        }
        u = ch[u][x];
        vis[u].push_back(id);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    memset(ch, -1, sizeof(ch));
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ins(s[i], i);
    }

    auto nxt = [&](int u) -> int {
        if (pos[u] == vis[u].size()) return inf;
        else return vis[u][pos[u]];
    };

    priority_queue<pair<int, int>> q;

    vector<int> in(N);
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (auto c : s[i]) {
            int x = c - 'a';
            u = ch[u][x];
            pos[u]++;
            q.push({nxt(u), u});
            if (!in[u]) {
                in[u] = 1;
                cnt++;
                ans++;
            }
        }


        while (cnt > m) {
            while (!q.empty()) {
                auto[tim, v] = q.top();
                q.pop();
                if (in[v]) {
                    in[v] = 0;
                    cnt--;
                    break;
                }
            }
        }
    }
    
    cout << ans << "\n";
}