#include <bits/stdc++.h>
 
using namespace std;

#define int long long
const int mod = 1e9 + 7, inf = 1e9;

void sol() {
    int n;
    cin >> n;
    int t = ceil(log2(n + 1));
    vector<string> s(t);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < t; i++) {
        cin >> s[i];
        int cnt = 0;
        for (auto c : s[i]) {
            if (c == '1') cnt++; 
        }
        v[cnt].push_back(i);
    }

    vector<int> c1(t), c2(n + 1);

    for (int bit = 0; bit < t; bit++) {
        for (int i = 1; i <= n; i++) {
            if ((i >> bit) & 1) c1[bit]++;
        }
        c2[c1[bit]]++;
    }

    for (int i = 0; i <= n; i++) {
        if (c2[i] != v[i].size()) {
            cout << "0\n";
            return;
        }
    }

    {
        vector<string> s2(t);
        for (int i = 0; i < t; i++) {
            int x = c1[i];
            s2[i] = s[v[x].back()];
            v[x].pop_back();
        }
        s = move(s2);
    }

    vector<int> vis(n + 1);
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int bit = 0; bit < t; bit++) {
            res += (s[bit][i] - '0') << bit;
        }
        if (res <= n) {
            vis[res] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "0\n";
            return;
        }
    }
    
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c2[i]; j++) {
            ans *= j;
        }
    }
    cout << ans << "\n";


}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
