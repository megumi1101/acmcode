#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    #define ull unsigned long long
    constexpr int mod = 998244353;
    constexpr int Bas = 257;
 
    void sol() {
        int n;
        cin >> n; 
        vector<int> a(n + 5), f(n + 5), rd(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; 
            rd[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!rd[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            if (f[u]) {
                f[a[u]] = 0;
            }
            rd[a[u]]--;
            if (!rd[a[u]]) {
                q.push(a[u]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (rd[i] && !f[i]) {
                int x = !f[i], t = i;
                rd[i]--;
                while (1) {
                    t = a[t];
                    if (x != f[t]) {
                        if (x == 1) {
                            x = f[t];
                        } else {
                            f[t] = x;
                        }
                    } 
                    rd[t]--; 
                    x ^= 1;
                    if (t == i) break;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (rd[i] == 1) {
                rd[i]--; 
                int x = 0;
                for (int t = a[i]; t != i; t = a[t], x ^= 1) {
                    rd[t]--; 
                    f[t] = x;
                } 
                if (f[i] != x) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += (f[i] == 1);
        }
        
        cout << cnt << "\n";
        for (int i = 1; i <= n; i++) {
            if (f[i] == 1) {
                cout << a[i] << " ";
            }
        } 
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        // cin >> T;
        while (T--) sol();
        
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
