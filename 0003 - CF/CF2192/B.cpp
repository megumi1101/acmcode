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
    int n;
    string s;
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }
    
    if (cnt1 == 0) {
        cout << "0\n";
        return;
    }
    if (cnt1 % 2 == 0) {
        cout << cnt1 << "\n";
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cout << i + 1 << " ";
        }
        cout << "\n";
        return;
    }
    if (cnt0 & 1) {
        cout << cnt0 << "\n";
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cout << i + 1 << " ";
        }
        cout << "\n";
        return;
    }
    cout << "-1\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
