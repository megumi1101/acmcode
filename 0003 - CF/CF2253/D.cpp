#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int x, y;
    cin >> x >> y;
    int t = 0;
    int pos = 0;
    for (int i = 1;; i++) {
        t += i;
        if (t > x + y) {
            t -= i;
            pos = i - 1;
            break;
        }
    }
    
    int dis = (x + y - t) / 2;
    int tox = x - dis;
    vector<int> vis(pos + 1);
    int now = 0;
    for (int i = pos; i >= 1; i--) {
        if (now + i <= tox) {
            now += i;
            vis[i] = 1;
        }
    }

    string s;
    for (int i = 1; i <= pos; i++) {
        if (vis[i]) {
            s.push_back('X');
        } else {
            s.push_back('Y');
        }
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}