#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
vector<int> get_pi(string s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
        if (pi[i] > 0) f[i] = f[pi[i] - 1] + f[i - pi[i]]; 
    }
    return f;
}
void sol() {
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;
    while (q--)  {
        int l, r;
        cin >> l >> r;
        string s = t.substr(l - 1, r - l + 1);
        auto f = get_pi(s);
        int sum = 0;
        for (auto x : f) sum += x;
        cout << sum << "\n";
    }
    
 
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
 
/*
aaaaa
bbbb
ccc
 
cacababababc
*/
