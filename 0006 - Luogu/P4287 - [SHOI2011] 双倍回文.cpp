#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    vector<int> get_d (string s) {
        int n = (int)s.size();
        vector<int> d(n);
        d[1] = 1;
        for (int i = 2, l, r = 1; i < s.size(); i++) {
            if (i <= r) d[i] = min(d[r + l - i], r - i + 1);
            while (s[i + d[i]] == s[i - d[i]]) d[i]++;
            if (i + d[i] - 1 > r) r = i + d[i] - 1, l = i - d[i] + 1;
        } 
        return d;
    }
    
    struct node {
        int id, x;
        friend bool operator<(const node &a, const node &b) {
            return a.x > b.x ;
        }
    };
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string tmp = "&#";
        for (char c : s) {
            tmp += c;
            tmp += "#";
        }
        vector<int> d = get_d(tmp);
        vector<node> a(n);
        s = " " + s;
        for (int i = 1; i <= n; i++) a[i - 1] = {i, (d[i * 2 + 1] - 1) / 2 + i};
        sort(a.begin(), a.end());
        set<int> st;
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) b[i] = i - (d[i * 2 + 1] - 1) / 4;
        int pos = 0;
        int ans = 0;
        a.emplace_back();
        for (int i = n; i >= 1; i--) {
            while (a[pos].x >= i && pos < n) {
                st.insert(a[pos].id);
                pos++;
            }
            auto it = st.lower_bound(b[i]);
            if (it != st.end()) {
                int x = *it;
                if (x < i) {
                    ans = max(ans, (i - x) * 4);
                }
            }
        }
        cout << ans;
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}