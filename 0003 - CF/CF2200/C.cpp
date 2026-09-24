#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int t = 1; t <= n; t++) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == s[i + 1]) {
                s.erase(s.begin() + i, s.begin() + i + 2);
                break;
            }
        }
        if (s.empty()) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
