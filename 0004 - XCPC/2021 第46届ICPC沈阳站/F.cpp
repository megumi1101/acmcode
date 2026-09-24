// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCæ²ˆé˜³ç«?// Problem: #6617. Encoded Strings I (6617)
// Submission: https://qoj.ac/submission/1710636
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        string s;
        cin >> n >> s;
        vector<int> lst(26, -1);
        vector<int> tun(26, -1);
        vector vis(26, vector(26, 0));
        vector<string> a;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            lst[x] = i;
            tun[x] = 0;
            fill(vis[x].begin(), vis[x].end(), 0);
            for (int c = 0; c < 26; c++) if (c != x) {
                if (lst[c] != -1) {
                    if (!vis[c][x]) {
                        vis[c][x] = 1;
                        tun[c]++;
                    }
                }
            }
            string t;
            for (int j = 0; j <= i; j++) {
                t += tun[s[j] - 'a'] + 'a';
            }
            a.push_back(t);
        }
        // cerr << tun[0] << " " << tun[2] << "\n";
        sort(a.rbegin(), a.rend());
        cout << a[0] << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>