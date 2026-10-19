#include <bits/stdc++.h>

using namespace std;

const int N = 2.5e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1), c(n + 1);
    vector<vector<int>> com(n + 1);
    bitset<N> ini;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> c[i];
        com[c[i]].push_back(i);
        ini.set(x[i]);
    }

    vector<int> bel(n + 1), L(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n;) {
        int up = i * 2;
        ++cnt;
        L[cnt] = i;
        for (int j = i; j <= up && j <= n; j++) {
            bel[j] = cnt;
        }
        i = up + 1;
    }

    vector<bitset<N>> ans(cnt + 1);

    for (int col = 1; col <= n; col++) {
        auto nb = ini;
        for (auto id : com[col]) nb.reset(x[id]);
        for (auto id : com[col]) {
            ans[bel[id]] |= (nb >> x[id]);
        }
    }
    
    while (q--) {
        int d;
        cin >> d;
        bool fg = 0;
        for (int i = 1; i <= cnt; i++) {
            if (ans[i].test(d)) {
                cout << L[i] << "\n";
                fg = 1;
                break;
            }
        }

        if (fg == 0) {
            cout << "0\n";
        }
    }
}

/*
4 5
3 1
1 2
5 1
6 2
1
2
3
4
5
*/