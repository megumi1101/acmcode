#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> ed(n);
        map<char, int> mp;
        vector<char> s(n);
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            mp[x] = i;
            s[i] = x;
        }
        for (int i = 0; i < k; i++) {
            char c, c_;
            cin >> c >> c_;
            int x = mp[c];
            int y = mp[c_];
            ed[x].push_back(y);
        }
        for (int i = 0; i < n; i++) {
            cout << i << " " << s[i] << "-";
            for (auto x : ed[i]) cout << x << "-";
            cout << "^\n";
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