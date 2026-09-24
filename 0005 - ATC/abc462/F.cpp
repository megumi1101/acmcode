#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;
void sol() {
    string s;
    int k;
    cin >> s >> k;
    const int Mx = 12;
    array<array<int, 3>, Mx> f{};
    for (auto &v : f) v.fill(inf);
    f[0][0] = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        array<array<int, 3>, Mx> nf{};
        for (auto &v : nf) v.fill(inf);

            for (int cnt = 0; cnt < Mx; cnt++) {
            for (int op = 0; op < 3; op++) {
                if (f[cnt][op] == inf) continue;
                int tmp = 1;
                if (c == "ABC"[op]) {
                    tmp = 0;
                }
                int nop = op + 1;
                int ncnt = cnt;
                if (nop == 3) {
                    nop = 0;
                    ncnt++;
                }
                if (ncnt < Mx) {
                    nf[ncnt][nop] = min(nf[ncnt][nop], f[cnt][op] + tmp);
                }
                nf[cnt][0] = min(nf[cnt][0], f[cnt][op] + (tmp ^ 1));
                nf[cnt][1] = min(nf[cnt][1], f[cnt][op] + (c != 'A'));
            }
        }

        if (s[i] == 'C' && s[i - 1] == 'B' && s[i - 2] == 'A') {
            for (int cnt = 0; cnt + 1 < Mx; cnt++) {
                nf[cnt] = nf[cnt + 1];
            }
        }
        f = move(nf);
    }
    
    int ans = ranges::min(f[k]);
    if (ans == inf) ans = -1;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}