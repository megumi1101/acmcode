#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> cc(n + 1);
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            cin >> cc[i];
        }
        a.push_back(0);
        sort (cc.begin() + 1, cc.end());
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cc[i] == cc[i - 1]) {
                cnt++;
            }
            else {
                if (i != 1) {
                    a.push_back(cnt);
                }
                cnt = 1;
            }
        }
 
        a.push_back(cnt);
        set<int> s;
        s.insert(0);
        for (int i = 0; i <= 18; i++) {
            s.insert((1 << i));
            
        }
        int ans = *s.lower_bound(n) - n + 2;
        // cerr << ans << "\n";
        n = a.size() - 1;
        vector<int> f(n + 5), g(n + 5), sum(n + 5);
        // for (int i = 1; i <= n; i++) cerr << a[i] << " ";
        // cerr << endl;
        f[0] = 1;
        g[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
            f[i] = *s.lower_bound(sum[i]) - sum[i]; 
        }
        for(int i = 1; i <= n; i++) {
            g[i] = *s.lower_bound(sum[n] - sum[i - 1]) - (sum[n] - sum[i - 1]);
        }
        // for (int i = 1; i <= n; i++) cerr << f[i] << " ";
        // cerr << endl;
        // for (int i = 1; i <= n; i++) cerr << g[i] << " ";
        // cerr << endl;
 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 18; j++) {
                auto it = upper_bound(sum.begin() + 1, sum.begin() + n + 1, sum[i] + (1 << j));
                it--;
                int x = it - sum.begin();
                if (x == i) {
                    ans = min (ans, f[i] + 1 + g[x + 1]); 
                }
                else ans = min (ans, f[i] + sum[i] + (1 << j) - sum[x] + g[x + 1]); 
            }
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(), 0;
}
