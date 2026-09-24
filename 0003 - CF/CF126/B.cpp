#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    vector<int> get_pi(string s) {
        int n = (int ) s.size();
        vector<int> pi(n ,0);
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
        vector<int> pi;
        int n = s.size();
        vector<int> cnt(s.size() + 5, 0);
        pi = get_pi(s);
        for (int i = 1; i < s.size() - 1; i++) {
            cnt[pi[i]]++;
        }
        int j = pi[n - 1];
        while (j) {
            if (cnt[j]) {
                break;
            }
            j = pi[j - 1];
        }
        if (j == 0) {
            cout << "Just a legend\n";
        }
        else {
            for (int i = 0; i < j; i++) {
                cout << s[i];
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    #undef int
}

int main() {
    return Xbbbz ::main(), 0;
}
