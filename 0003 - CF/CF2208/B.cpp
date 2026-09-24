#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n + 1);
    vector<int> que;
    for (int i = 1; i <= n; i++) cin >> a[i], que.push_back(i);
    
    int now = 0;
    int cnt = 0;
    while (1) {
        bool fg = 0;
        for (int i = 0; i < k; i++) {
            if (que[i] == p) {
                fg = 1;
                if (now + a[que[i]] <= m) {
                    now = now + a[que[i]];
                    cnt++;
                    int x = que[i];
                    que.erase(que.begin() + i, que.begin() + i + 1);
                    que.push_back(x);
                } else {
                    cout << cnt << "\n";
                    return;
                }
                break;
            }
        }
 
        if (!fg) {
            int mnpos = 0;
            for (int i = 0; i < k; i++) {
                if (a[que[i]] < a[que[mnpos]]) {
                    mnpos = i;
                }
            }
            if (now + a[que[mnpos]] <= m) {
                now = now + a[que[mnpos]];
                int x = que[mnpos];
                que.erase(que.begin() + mnpos, que.begin() + mnpos + 1);
                que.push_back(x);
            } else {
                cout << cnt << "\n";
                return;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
