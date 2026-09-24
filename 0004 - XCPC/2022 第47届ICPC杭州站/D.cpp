// QOJ user: xbbbz
// Contest: 2022 Á¨?7Â±äICPCÊù≠Â∑ûÁ´?// Problem: #5304. Money Game (5304)
// Submission: https://qoj.ac/submission/1446141
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
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            double x;
            cin >> x;
            sum += x;
        }
        double res = sum / (n + 1);
        cout << fixed << setprecision(6);
        cout << 2.0 * res << " ";
        for (int i = 1; i < n; i++) cout << res << " ";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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