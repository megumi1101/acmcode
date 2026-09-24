#include <bits/stdc++.h>

using namespace std;

#define int long long

const int V = 2e5 + 100;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> vis(V);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    vector<int> f(1);

    f[0] = 1;
    int lst = 0;
    for (int i = 1; i < V; i++) {
        int x = vis[i];
        vector<int> suf(lst + x + 1);
        for (int j = 0; j < f.size(); j++) {
            suf[j + x] = f[j];
        }
        for (int j = suf.size() - 2; j >= 0; j--) {
            suf[j] += suf[j + 1];
            suf[j] %= mod;
        } 
        int siz = (lst + x) / 2;
        vector<int> nf(siz + 1);
        for (int j = 0; j <= siz; j++) {
            nf[j] = suf[2 * j];
        }
        lst = siz;
        f = move(nf);
    }

    cout << f[0] << "\n";
}