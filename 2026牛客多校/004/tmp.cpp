#include <bits/stdc++.h>

using namespace std;

struct State {
    vector<int> val;    // 最终的 f(p)
    vector<int> order;  // Alice、Bob 依次选择的顺序，也就是 p
};

vector<int> p;
vector<bool> used;

vector<int> get_f() {
    int n = p.size();
    int pos = find(p.begin(), p.end(), 1) - p.begin();

    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(p[(pos + i) % n]);
    }
    return res;
}

State dfs(int dep, int n) {
    if (dep == n) {
        return {get_f(), p};
    }

    State best;
    bool first = true;

    for (int x = 1; x <= n; x++) {
        if (used[x]) continue;

        used[x] = true;
        p.push_back(x);

        State now = dfs(dep + 1, n);

        p.pop_back();
        used[x] = false;

        if (first) {
            best = now;
            first = false;
        } else if (dep % 2 == 0) {
            // Alice 取字典序最小
            if (now.val < best.val) {
                best = now;
            }
        } else {
            // Bob 取字典序最大
            if (now.val > best.val) {
                best = now;
            }
        }
    }

    return best;
}

void solve() {
    int n;
    cin >> n;

    p.clear();
    used.assign(n + 1, false);

    State ans = dfs(0, n);

    cout << "f(p): ";
    for (int x : ans.val) {
        cout << x << ' ';
    }
    cout << '\n';

    cout << "order: ";
    for (int x : ans.order) {
        cout << x << ' ';
    }
    cout << '\n';

    cout << "Alice: ";
    for (int i = 0; i < n; i += 2) {
        cout << ans.order[i] << ' ';
    }
    cout << '\n';

    cout << "Bob: ";
    for (int i = 1; i < n; i += 2) {
        cout << ans.order[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
        cout << '\n';
    }
}