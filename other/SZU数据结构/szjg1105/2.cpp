#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
    void sol() {
        int n;
        cin >> n;
        map<string, int> mp;
        vector<int> vis(n);
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            mp[s[i]] = i;
        }
        priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<>> q;
        

        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            string su, sv;
            int w;
            cin >> su >> sv >> w;
            if (mp[su] > mp[sv]) swap(su, sv);
            q.emplace(w, su, sv);
        }
        DSU dsu(n);
        vector<tuple<string, string, int>> ans;
        int sum = 0;
        int cnt = 1;
        while (!q.empty()) {
            auto[w, su, sv] = q.top();
            q.pop();
            int x = mp[su];
            int y = mp[sv];
            if (!dsu.merge(x, y)) continue;
            ans.emplace_back(su, sv, w);
            sum += w;
            cnt++;
        }
        if (cnt < n) {
            cout << "-1\n";
            return;
        }
        cout << sum << "\n";
        for (auto[u, v, w] : ans) cout << u << " " << v << " " << w << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}