#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
int lowbit(int x) {
    return x & (-x);
}
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
int gcd(int a, int b) {
    return b ?  gcd(b, a % b): a;
}
void sol() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    int ans = 2;
    int res = 1;
    int cnt = 0;
    int cnt1 = 0;
    if (s[0] == '0' || s[n - 1] == '0') {
        cout << "-1\n";
        return;
    }
    vector<int> p;
    int tmp = 2;
    int cc = c;
    c = c / gcd(c, 2);
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1') ans = ans * 2 % mod, tmp *= 2, c = c / gcd(c, 2);
        else if (s[i] == '0') ans = ans * i % mod, tmp *= i, c = c / gcd(c, i);
        else {
            if (i == 1) continue;
            cnt++;
            if (i & 1) cnt1++, p.push_back(i);
        }
    }
    int cnt0 = cnt - cnt1;
    if (lowbit(c) != c) {
        cout << ans * fap(2, cnt) % mod << "\n";
        return; 
    }
    int x = log2(c);
    if (cnt0 >= x) {
        cout << "-1\n";
        return;
    }
    int nd = x - cnt0 - 1;
    nd = min(nd, cnt1);
    for (int i = 0; i < cnt1 - nd; i++) ans = ans * p[i] % mod;
    cerr << cnt << nd;
    cout << ans * fap(2, cnt - (cnt1 - nd)) % mod << "\n";
    
 
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
