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
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        int siz = s2.size();
        string s = s2 + "#" + s1;
        auto pi = get_pi(s);
        string ans;
        for (int i = siz + 1; i < s.size(); i++) {
            ans += s[i];
            if (pi[i] == siz) {
                for (int j = 0; j < siz; j++) ans.pop_back();
                ans += s3;
            }
        }
        cout << s1 << "\n" << ans << "\n";
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