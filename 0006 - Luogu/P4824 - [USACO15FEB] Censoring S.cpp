#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    string get_pi(string s, int k) {
        int n = (int)s.size();
        vector<int> pi(1);
        string ans;
        for (int i = 1; i < n; i++) {
            int j = pi.back();
            while (j && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi.push_back(j);
            if (i > k) ans.push_back(s[i]);
            if (i > k && j == k) {
                int x = k;
                while (x--) {
                    pi.pop_back();
                    ans.pop_back();
                }
            }
        }
        return ans;
    }


    void sol() {
        string s, t;
        cin >> s >> t;
        s = t + "#" + s;
        cout << get_pi(s, t.size());
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