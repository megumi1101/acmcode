#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rng(random_device{}());

int get(const vector<int> &p) {
    int n = p.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (2 * i - n + 1) * p[i];
        res %= n;
    }
    return (res + n) % n;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> p(n);
    for (int &v : p) cin >> v;

    int target = get(p);
    for (int T = 0; T < 100; T++) {
        vector<int> q(n);
        iota(q.begin(), q.end(), 0);
        shuffle(q.begin(), q.end(), rng);
        int pos = find(q.begin(), q.end(), x) - q.begin();
        swap(q[pos], q[k]);

        int cur = get(q);
        if (cur == target) {
            for (int v : q) cout << v << " ";
            cout << "\n";
            return 0;
        }
        for (int i = 0; i + 1 < n; i++) {
            if (i == k || i + 1 == k) continue;

            int nxt = cur + 2 * (q[i] - q[i + 1]);
            nxt %= n;
            nxt = (nxt + n) % n;

            if (nxt == target) {
                swap(q[i], q[i + 1]);
                for (int v : q) cout << v << " ";
                cout << "\n";
                return 0;
            }
        }
    }
}