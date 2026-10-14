#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;

void sol() {
    int n, L, k;
    cin >> n >> L >> k;

    vector<int> l(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        l[i]++;
        mx = max(mx, l[i] + L);
    }

    auto get = [&](int up) -> int {
        int siz = up;
        vector<int> c(siz + 5), d(siz + 5), a(siz + 5), sd(siz + 5), sa(siz + 5);
        vector<int> vis(siz + 5);
        for (int i = 1; i <= n; i++) {
            c[l[i]]++;
            vis[l[i]] = 1;
            c[l[i] + L]--;
        }

        int ans = 0;
        for (int i = 1; i < siz; i++) {
            c[i] += c[i - 1];
            ans += (c[i] == k);
            d[i] = (c[i] == k + 1) - (c[i] == k);
            a[i] = (c[i] == k - 1) - (c[i] == k);
            sd[i] = d[i] + sd[i - 1];
            sa[i] = a[i] + sa[i - 1];
        }

        vector<int> pre(siz, -inf);
        for (int i = 0; i + L < siz; i++) {
            if (vis[i + 1]) {
                pre[i] = sd[i + L] - sd[i]; 
            }
            if (i) {
                pre[i] = max(pre[i], pre[i - 1]);
            }
        }

        int del = 0;
        for (int j = L; j + L < siz; j++) {
            del = max(pre[j - L] + sa[j + L] - sa[j], del);
        }

        deque<pair<int, int>> q;
        for (int j = 0; j + L < siz; j++) {
            int t = sd[j] + sa[j + L];
            while (!q.empty()) {
                auto [i, x] = q.front();
                if (i <= j - L) {
                    q.pop_front();
                } else {
                    break;
                }
            }
            
            if (!q.empty()) del = max(del, t - q.front().second);

            if (vis[j + 1]) {
                while (!q.empty()) {
                    auto [i, x] = q.back();
                    if (t <= x) {
                        q.pop_back();
                    } else {
                        break;
                    }
                }
                q.push_back({j, t});
            }
        }
        return ans + del;
    };

    int ans = 0;
    ans = max(ans, get(4 * n + 10));
    for (int i = 1; i <= n; i++) {
        l[i] = mx - (l[i] + L - 1);
    }
    // cout << ans << "\n";
    ans = max(ans, get(mx));
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
5 5 2
2 1 13 19 11
12 18 19 7 8
*/