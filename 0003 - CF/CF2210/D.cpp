#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    auto get = [&](string s) -> pair<int, int> {
        int c0 = 0, c1 = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == '(' && s[i + 1] == ')') {
                c0++;
            }
        }
 
        vector matchr(n, 0);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stk.push_back(i);
            else {
                matchr[stk.back()] = i;
                stk.pop_back();
            }
        }
 
        int l = 0, r = n - 1;
        while (s[l] == '(' && matchr[l] == r) {
            l++;
            r--;
        }
        return {c0, l};
    };
 
    if (get(s) == get(t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
