#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
vector<int> get_pi(string &s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
    void sol() {
        string s;
        cin >> s;
        auto pi = get_pi(s);
        int mx = 0;
        int siz = s.size();
        if (pi[siz - 1] == 0) cout << "empty\n";
        else {
            cout << s.substr(siz - pi[siz - 1], pi[siz - 1]) << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}