#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    int n = s.size();
    int m;
    cin >> m;

    vector<int> tun(n), to(n + 1), dep(n + 1, -1), tdep(n + 1, -1), vis(n + 1);
    while (m--) {
        int k, d;
        cin >> k >> d;
        fill(tun.begin(), tun.end(), 0);

        int sft = n - k;
        vector<int> p;
        for (int r = 0; r < d; r++) {
            int t = r;
            for (; t < k; t += d) {
                p.push_back(t);
            }
        }

        for (int i = 0; i < sft; i++) {
            to[i] = i + 1;
        }

        for (int i = sft; i < n; i++) {
            int v = p[i - sft] + 1 + sft;
            to[i] = v;
        }

        fill(dep.begin(), dep.end(), -1);
        fill(tdep.begin(), tdep.end(), -1);
        fill(vis.begin(), vis.end(), 0);
        dep[0] = 0;
        tdep[0] = 0;
        vis[0] = 1;
        int u = 0;
        while (u != n) {
            int v = to[u];
            vis[v] = 1;
            dep[v] = dep[u] + 1;
            tdep[dep[v]] = v;
            u = v;
        }
        
        sft++;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int u = i;
            tmp.clear();
            while (1) {
                if (vis[u]) break;
                vis[u] = 1;
                tmp.push_back(u);
                u = to[u];
            }

            int siz = tmp.size();
            for (int j = 0; j < tmp.size(); j++) {
                tun[tmp[j]] = tmp[(j + sft) % siz];
            }
        }
        
        for (int i = 0; i < n; i++) {
            int dis = dep[n] - dep[i];
            if (dep[i] == -1) {
                tun[i] = tun[i] - sft;
            } else if (dis <= sft) {
                tun[i] = n - dis;
            } else {
                tun[i] = tdep[dep[i] + sft] - sft;
            }
        }

        string t;
        t.resize(n);
        for (int i = 0; i < n; i++) {
            t[i] = s[tun[i]];
        }
        s = move(t);
        cout << s << "\n";
    }
}
