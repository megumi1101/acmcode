#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(string s) {
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


const int Mx = 1005;
int main() {
    string s;
    cin >> s;
    auto s1 = s;
    reverse(s.begin(), s.end());
    auto s2 = s;

    int n;
    cin >> n;

    auto getpos = [&](string s, string t) -> vector<int> {
        auto pi = get_pi(t);
        vector<int> pos(Mx, -1);
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (j && s[i] != t[j]) j = pi[j - 1];
            if (s[i] == t[j]) j++;
            if (j && pos[j] == -1) pos[j] = i; 
            if (j == t.size()) break;
        }
        return pos;
    };

    int sizs = s.size();
    int ans = 0;
    for (int _ = 1; _ <= n; _++) {
        string t;
        cin >> t;
        auto p1 = getpos(s1, t);
        reverse(t.begin(), t.end());
        auto p2 = getpos(s2, t);
        int siz = t.size();

        for (int i = 1; i < t.size(); i++) {
            if (p1[i] != -1 && p2[siz - i] != -1 && p1[i] + p2[siz - i] + 2 <= sizs) {
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}
/*
ABBA
2
BAAB
ABBA

*/