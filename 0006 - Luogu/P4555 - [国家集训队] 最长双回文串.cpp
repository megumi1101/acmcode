#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    const int N = 2e5 + 10;
    vector<int> d(N), tl(N, 0), tr(N, 0);
    void get_d (string s) {
        int n = (int)s.size();
        d[1] = 1;
        for (int i = 2, l, r = 1; i < s.size(); i++) {
            if (i <= r) d[i] = min(d[r + l - i], r - i + 1);
            while (s[i + d[i]] == s[i - d[i]]) d[i]++;
            if (i + d[i] - 1 > r) r = i + d[i] - 1, l = i - d[i] + 1;
            tl[i - d[i] + 1] = max(tl[i - d[i] + 1], d[i] - 1);
            tr[i + d[i] - 1] = max(tr[i + d[i] - 1], d[i] - 1);
        } 
    }
    void sol() {
        string s = "&#";
        string tmp; cin >> tmp;
        for (char c : tmp) {
            s += c;
            s += "#";
        }
        get_d(s);
        for (int i = 3; i < s.size(); i += 2) tl[i] = max(tl[i], tl[i - 2] - 2); 
        for (int i = s.size() - 3; i >= 1; i -= 2) tr[i] = max(tr[i], tr[i + 2] - 2); 
        int ans = 0;
        for (int i = 1; i < s.size(); i += 2) {
            if (tl[i] && tr[i]) {
                ans = max (ans, tl[i] + tr[i]);
            }
        }
        cout << ans;
    }

    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
        // init();
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}