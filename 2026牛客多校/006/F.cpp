#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned int;

vector<int> z_f(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main() {
    string s;
    cin >> s;
    auto z = z_f (s);

    vector<int> pre(26);
    for (int i = 1; i < s.size(); i++) {
        int j = z[i];
        if (i + j < s.size()) {
            int fr = s[j] - 'a';
            int to = s[i + j] - 'a';
            pre[to] |= 1 << (fr);
        } else {
            cout << "0\n";
            return 0;
        }
    }

    int all = 1LL << 26;
    vector<u32> f(all);
    f[0] = 1;
    for (int s = 0; s < all; s++) if (f[s]) {
        for (int bit = 0; bit < 26; bit++) {
            if (s >> bit & 1) continue;
            if ((s & pre[bit]) == pre[bit]) {
                f[s | (1LL << bit)] += f[s];
            }
            
        }
    }
    u32 ans = f[all - 1];

    cout << ans << "\n";
}

/*
3
5
bca a zz ab c
4
ba b aa aba
3
az za m
*/