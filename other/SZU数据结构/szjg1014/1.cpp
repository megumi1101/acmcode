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
        string s, t;
        cin >> t >> s;
        string ss = s + "#" + t;
        auto pi = get_pi(ss);
        int sizs = s.size();
        int sizt = t.size();
        cout << "-1 ";
        for (int i = 0; i < sizs - 1; i++) cout << pi[i] << " ";
        cout << "\n";
        for (int i = 1; i <= t.size(); i++) {
            if (pi[i + sizs] == sizs) {
                cout << i - sizs + 1 << "\n";
                return;
            }
        }
        cout << "0\n";
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