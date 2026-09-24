#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e18;
 
    void sol() {
        map<int, int> mpr, mpc;
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        int r = 0, c = 0;
        int mnr = 0, mnc = 0, mxr = 0, mxc = 0;
        // mpr[0] = 1, mpc[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'A') r--, mnr = min(mnr, r), mpr[r]++;
            if (s[i] == 'D') r++, mxr = max(mxr, r), mpr[r]++;
            if (s[i] == 'S') c--, mnc = min(mnc, c), mpc[c]++;
            if (s[i] == 'W') c++, mxc = max(mxc, c), mpc[c]++;
        }
        int dr = mxr - mnr + 1;
        int dc = mxc - mnc + 1;
        int br = 0, bc = 0;
        r = 0, c = 0;
        mnr = 0, mnc = 0, mxr = 0, mxc = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'A') r--, mnr = min(mnr, r), mpr[r]--;
            if (s[i] == 'D') r++, mxr = max(mxr, r), mpr[r]--;
            if (s[i] == 'S') c--, mnc = min(mnc, c), mpc[c]--;
            if (s[i] == 'W') c++, mxc = max(mxc, c), mpc[c]--;
            while (mpr.size() && mpr.begin()->second == 0) {
                mpr.erase(mpr.begin());
            }
            while (mpc.size() && mpc.begin()->second == 0) {
                mpc.erase(mpc.begin());
            }
            while (mpr.size() && prev(mpr.end())->second == 0) {
                mpr.erase(prev(mpr.end()));
            }
            while (mpc.size() && prev(mpc.end())->second == 0) {
                mpc.erase(prev(mpc.end()));
            }
            if (s[i] == 'A' || s[i] == 'D' || i == 0) {
                if (!mpr.size()) continue;
                auto it1 = mpr.begin();
                auto it2 = mpr.end();
                it2 = prev(it2);
                int tmn = it1->first;
                int tmx = it2->first;
                int tmp1, tmp2;
                r--;
                tmp1 = min(mnr, r);
                tmp2 = max(mxr, r);
                tmp1 = min(tmn - 1, tmp1);
                tmp2 = max(tmp2, tmx - 1);
                tmp2 = max(tmp2, (int)0);
                if (tmp2 - tmp1 + 1 < dr) br = 1;
                r += 2;
                tmp1 = min(mnr, r);
                tmp2 = max(mxr, r);
                tmp1 = min(tmn + 1, tmp1);
                tmp1 = min((int)0, tmp1);
                tmp2 = max(tmp2, tmx + 1);
                if (tmp2 - tmp1 + 1 < dr) br = 1;
                r--;
            }
            if (s[i] == 'W' || s[i] == 'S' || i == 0) {
                if (!mpc.size()) continue;
                auto it1 = mpc.begin();
                auto it2 = mpc.end();
                it2 = prev(it2);
                int tmn = it1->first;
                int tmx = it2->first;
                int tmp1, tmp2;
                c--;
                tmp1 = min(mnc, c);
                tmp2 = max(mxc, c);
                tmp1 = min(tmn - 1, tmp1);
                tmp2 = max(tmp2, tmx - 1);
                tmp2 = max(tmp2, (int)0);
                if (tmp2 - tmp1 + 1 < dc) bc = 1;
                c += 2;
                tmp1 = min(mnc, c);
                tmp2 = max(mxc, c);
                tmp1 = min(tmn + 1, tmp1);
                tmp1 = min((int)0, tmp1);
                tmp2 = max(tmp2, tmx + 1);
                if (tmp2 - tmp1 + 1 < dc) bc = 1;
                c--;
            }  
        }
        // cout << dr << dc << "\n";
        // cout << br << bc << "\n";
        cout << min(dr * dc - br * dc, dr * dc - bc * dr) << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
