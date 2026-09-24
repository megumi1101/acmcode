#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    long long cnt = 0;

    do {
        vector<int> q;
        for (int i = 2; i < n; i += 2) {
            q.push_back(p[i + 1]);
            q.push_back(p[i]);
        }
        q.push_back(p[0]);
        q.push_back(p[1]);

        vector<int> r(n);
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int sum = p[i] + q[i] + carry;
            r[i] = sum % n;
            carry = sum / n;
        }

        if (carry) continue; // 结果超过 n 位

        // r 也必须是排列
        vector<int> vis(n, 0);
        bool ok = true;
        for (int x : r) {
            if (vis[x]) {
                ok = false;
                break;
            }
            vis[x] = 1;
        }
        if (!ok) continue;

        // 新增条件：每一列 p_i, q_i, r_i 两两不同
        for (int i = 0; i < n; i++) {
            if (p[i] == q[i] || p[i] == r[i] || q[i] == r[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        cnt++;

        for (int x : p) cout << x;
        cout << "  ";
        for (int x : q) cout << x;
        cout << "  ";
        for (int x : r) cout << x;
        cout << '\n';

    } while (next_permutation(p.begin(), p.end()));

    cout << "n = " << n << ", cnt = " << cnt << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(4);
    solve(6);
    solve(8);
    return 0;
}