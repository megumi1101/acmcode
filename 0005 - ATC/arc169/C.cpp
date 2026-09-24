#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void norm(int &x) {
    x %= mod;
    if (x < 0) x += mod;
}
signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> lst(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1] && a[i] != -1) {
            lst[a[i]] = 1;
        } else if (a[i] == a[i - 1] && a[i] != -1) {
            lst[a[i]]++;
            if (lst[a[i]] > a[i]) {
                cout << "0\n";
                return 0;
            }
        }
    }

    vector<queue<int>> q(n + 1);
    vector<int> sumi(n + 1);
    int sumall = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> s(n + 1, -1);
        auto get = [&](int pos) {
            s[pos] = (i == 1);
            s[pos] += sumall;
            s[pos] -= sumi[pos];
            norm(s[pos]);
        };
        if (a[i] == -1) {
            for (int j = 1; j <= n; j++) {
                get(j);
            }
        } else {
            get(a[i]);
        }

        auto add = [&](int pos, int x) {
            sumall += x;
            sumi[pos] += x;
            norm(sumall);
            norm(sumi[pos]);
        };
        for (int j = 1; j <= n; j++) {
            if (s[j] != -1) {
                q[j].push(s[j]);
                // cerr << i << " " << j << " " << s[j] << "\n";
                add(j, s[j]);
                // cerr << fen.sum(j) << '\n';
                // cerr << seg.query(1, n).sum << "\n";
                if (q[j].size() > j) {
                    int x = q[j].front();
                    q[j].pop();
                    add(j, -x);
                    // cerr << seg.query(1, n).sum << "\n";
                }
            } else {
                while (!q[j].empty()) {
                    int x = q[j].front();
                    q[j].pop();
                    add(j, -x);
                }
            }
        }
        
    }

    cout << sumall << "\n";
}