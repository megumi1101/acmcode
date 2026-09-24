#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int siz;
        cin >> siz;
        p[i].resize(siz);
        for (auto &x: p[i]) cin >> x;
    }
    
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];

    auto beat = [&](int x, int y) -> bool {
        for (auto &i : p[y])
            if (x == i)
                return 1;
        return 0;
    };

    vector<pair<int, int>> f;
    int none = 0;

    for (int i = 1; i <= m; i++) {
        vector<pair<int, int>> nf;
        int res = none;
        int nnone = inf;

        auto upd = [&](int id, int val) -> void {
            for (auto &[x, y] : nf) {
                if (x == id) {
                    y = min(y, val);
                    return;
                }
            }
            nf.push_back({id, val});
        };

        for (auto[id, val] : f) {
            if (beat(id, a[i])) {
                upd(id, val);
            } else if (beat(a[i], id)) {
                res = min(res, val);
            } else {
                nnone = min(nnone, val);
            }
        }

        for (auto id : p[a[i]]) {
            upd(id, res + 1);
        }
        nnone = min(nnone, res + 1);
        none = nnone;
        f = move(nf);
    }

    int ans = none;
    for (auto[id, val] : f) ans = min(ans, val);
    cout << ans << "\n";
}