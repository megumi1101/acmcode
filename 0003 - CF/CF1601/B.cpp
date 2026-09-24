#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 1e9 + 7;
const int inf = 1e9;
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int fap(int a, int b) {
        if (b < 0) return 0;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b >>= 1;
        }
        return res;
    }
    void sol() {
        int n, m;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        queue<int> q;
        vector<int> lst(n + 1, -1);
        if (a[0] == n) {
            cout << "1\n0";
            return;
        }
        for (int i = 1; i <= a[0]; i++) {
            q.push(i);
            lst[i] = 0;
        }
        int r = a[0];
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (lst[u] == -1 || u == 0) continue;
            int t = b[u];
            u -= t;
            if (u + a[u] >= n) {
                lst[n] = u + t;
                break;
            }
            for (int i = r + 1; i <= u + a[u]; i++) {
                lst[i] = u + t;
                q.push(i);
            }
            r = max(r, u + a[u]);
        }
        if (lst[n] == -1) {
            cout << -1 << "\n";
            return;
        }
        int x = n;
        vector<int> ans;
        while (x) {
            ans.push_back(n - x);
            x = lst[x];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x : ans) cout << x << " ";
    }
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
/*
01101
00111
11001
10011
*/
