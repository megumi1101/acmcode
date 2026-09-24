#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> in(n + 5), out(n + 5);
    vector<pair<int,int>> segs(m);
    for (auto &[x, y] : segs) {
        cin >> x >> y;
        in[x]++;
        out[y + 1]++;
    }
    int res = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        res += in[i] - out[i];
        if (res == 0) cnt++;
    }
    sort(segs.begin(), segs.end());
    set<pair<int, int>> s;
    vector<vector<int>> mxs(m + 1);
    mxs[0].push_back(0);
    for (int i = 1; i <= m; i++) {
        auto[l, r] = segs[i - 1];
        s.insert({r, i});
        auto it = s.rbegin();
        int lst = -1;
        for (int j = 0; j <= k; j++) {
            if (it == s.rend()) {
                mxs[i].push_back(0);
                break;
            } else {
                if (it->first != lst) mxs[i].push_back(it->first);
                lst = it->first;
            }
            it = next(it);
        }
    }
    
    vector f(m + 1, vector(k + 1, vector(k + 1, inf)));
    f[0][0][0] = 0;
    for (int i = 0; i < m; i++) {
        auto[l, r] = segs[i];
        for (int de = 0; de <= k; de++) {
            for (int j = 0; j < mxs[i].size(); j++) {
                int nowr = mxs[i][j];
                int r1 = max(nowr, r);
                for (int toj = 0; toj < mxs[i + 1].size(); toj++) {
                    if (r1 == mxs[i + 1][toj]) {
                        f[i + 1][de][toj] = min(f[i + 1][de][toj], f[i][de][j] + max(0, min(r - nowr, r - l + 1)));
                        break;
                    }
                }
                
                if (de + 1 <= k) {
                    for (int toj = 0; toj < mxs[i + 1].size(); toj++) {
                        if (nowr == mxs[i + 1][toj]) {
                            f[i + 1][de + 1][toj] =min(f[i + 1][de + 1][toj], f[i][de][j]); 
                            break;
                        }
                    } 
                }
                
            }
        }
    }
    int ans = inf;
    for (int de = 0; de <= k; de++) {
        for (int u = 0; u < mxs[m].size(); u++) {
            ans = min(ans, f[m][de][u]);
        }
    }
    
    cout << n - ans << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
