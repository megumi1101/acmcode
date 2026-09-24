// QOJ user: xbbbz
// Contest: 2022 Á¨?7Â±äICPCÊù≠Â∑ûÁ´?// Problem: #5306. Da Mi Lao Shi Ai Kan De (5306)
// Submission: https://qoj.ac/submission/1445854
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod1 = 998244389;
const int mod2 = 998244391;
const int B = 241;
set<long long> se;
    void sol() {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            bool fg1 = 0, fg2 = 0, fg3 = 0;
            long long res1 = 0;
            long long res2 = 0;
            long long res = 0;
            string s;
            cin >> s;
            for (int i = 0; i < s.size(); i++) {
                if (i + 2 < s.size()) {
                    if (s[i] == 'b' && s[i + 1] == 'i' && s[i + 2] == 'e') fg3 = 1;
                }
                // if (s[i] == 'b') fg1 = 1;
                // if (s[i]== 'i' && fg1) fg2 = 1;
                // if (s[i] == 'e' && fg2) fg3 = 1;
                res1 *= B;
                res1 += s[i] - 'a' + 1;
                res1 %= mod1;
                res2 *= B;
                res2 += s[i] - 'a' + 1;
                res2 %= mod2;
                res = res1 << 31 | res2;
            }
            // cerr << fg3 << "\n";
            if (fg3 && se.find(res) == se.end()) se.insert(res), cout << s << "\n", cnt++;
        }
        if (cnt == 0) cout << "Time to play Genshin Impact, Teacher Rice!\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
/*
6
1
biebie
1
adwlknafdoaihfawofd
3
ap
ql
biebie
2
pbpbpbpbpbpbpbpb
bbbbbbbbbbie
0
3
abie
bbie
cbie
*/
</code>