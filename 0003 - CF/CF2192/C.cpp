#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
 
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b /= 2;
    }
    return res;
}
void sol() {
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    int now = h / sum * n;
    now += h / sum * k;
    h %= sum;
    if (h == 0) {
        cout << now - k << "\n";
        return;
    }
 
    vector<int> pre(n + 5, 1e18), suf(n + 5);
    vector<int> s(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = min(pre[i - 1], a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1], a[i]);
    }
    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int t = s[mid];
        if (suf[mid + 1] > pre[mid]) t = t - pre[mid] + suf[mid + 1];
        if (t >= h) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans + now << "\n";
 
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
