#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    const int N = 2e5 + 10;
    int n, k;
    int a[N], cnt[N];
    struct node {
        int x, id;
        friend bool operator < (node a, node b) {
            return a.x < b.x;
        }
    };
    int f(int i, int p) {
        int res = 0;
        int x = a[i] / p;
        if (!x) return inf;
        int y = a[i] - x * p;
        for (int i = 1; i <= p - y; i++) {
            res += x*x;
        }
        x++;
        for (int i = 1; i <= y; i++) {
            res += x*x;
        }
        return res;
    }
    priority_queue<node> q;
    void sol () {
        cin >> n >> k;
        k -= n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += a[i] * a[i];
            cnt[i] = 1;
            q.push((node){f(i, 1) - f(i, 2), i});
        }
        while(k--) {
            node u = q.top();
            q.pop();
            ans -= u.x;
            int i = u.id;
            cnt[i]++;
            q.push((node){f(i, cnt[i]) - f(i, cnt[i] + 1), i});
        }
        cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(),0;
}
