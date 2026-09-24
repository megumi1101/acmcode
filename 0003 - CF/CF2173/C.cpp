#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int,int> mp;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
            if (a[i] > mx) mx = a[i];
        }
 
 
        vector<int> c;
        for (auto &p : mp) c.push_back(p.first);
        sort(c.begin(), c.end());
        int siz = c.size();
 
        unordered_set<int> st;
        for (int v : c) st.insert(v);
        unordered_map<int, bool> vis;
 
        for (int b : c) {
            int need = k / b;
            if (need > siz) {
                vis[b] = 0;
                continue;
            }
            bool ok = 1;
            for (int m = b; m <= k; m += b) {
                if (st.find(m) == st.end()) { ok = 0; break; }
            }
            vis[b] = ok;
        }
 
 
        unordered_map<int, bool> vis2;
        for (int v : c) vis2[v] = 0;
 
        vector<int> d;
        for (int b : c) {
            if (!vis[b]) continue;
            bool nd = 0;
            for (int m = b; m <= k; m += b) {
                auto it = vis2.find(m);
                if (it != vis2.end() && it->second == 0) { nd = 1; break; }
            }
            if (nd) {
                d.push_back(b);
                for (int m = b; m <= k; m += b) {
                    auto it = vis2.find(m);
                    if (it != vis2.end()) it->second = 1;
                }
            }
        }
 
        bool fg = 1;
        for (int v : c) if (!vis2[v]) { fg = 0; break; }
 
        if (!fg) {
            cout << -1 << "\n";
        } else {
            cout << d.size() << "\n";
            for (int i = 0; i < d.size(); i++) {
                cout << d[i] << " ";
            }
            cout << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
