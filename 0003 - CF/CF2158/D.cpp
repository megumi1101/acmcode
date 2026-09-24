#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
void tun (string &s, int l, int r) {
    for (int i = l; i <= r; i++) { 
        if (s[i] == '0') s[i] = '1';
        else if (s[i] == '1') s[i] = '0';
    }
   
}
vector<pair<int, int>> get(string s) {
    vector<pair<int, int>> pi;
    int n = s.size();
    int l = -1, r = -1;
    for (int i = 0; i + 1 < n; i++) if (s[i] == s[i + 1]) {l = i; r = i + 1; break;}
    if (l == -1) {
        tun(s, 1, 3);
        pi.emplace_back(1, 3);
        l = 0, r = 1;
    }
    while (r + 1 < n) {
        if (s[r] == s[r + 1]) {
            r++;
        } else {
            pi.emplace_back(l, r);
            tun(s, l, r);
            r++;
        }
        
    }
 
    while (l) {
        if (s[l] == s[l - 1]) {
            l--;
        } else {
            pi.emplace_back(l, r);
            tun(s, l, r);
            l--;
        }
    }
 
    if (s[0] == '1') pi.emplace_back(l, r);
    return pi;
}
    void sol() {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        auto pi1 = get(s);
        auto pi2 = get(t);
        cout << pi1.size() + pi2.size() << "\n";
        for (auto[x, y] : pi1) cout << x + 1 << " " << y + 1 << "\n";
        reverse(pi2.begin(), pi2.end());
        for (auto[x, y] : pi2) cout << x + 1 << " " << y + 1 << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
