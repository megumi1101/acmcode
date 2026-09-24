#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
    }
 
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            vector<int> ans;
            cout << "Alice\n";
            for (int j = 0; j < cnt; j++) {
                if (s[j] == '1') ans.push_back(j);
            }
            for (int j = cnt; j < n; j++) {
                if (s[j] == '0') ans.push_back(j);
            }
            cout << ans.size() << "\n";
            for (auto x : ans) cout << x + 1 << " ";
            cout << "\n";
            return;
        }
    }
 
    cout << "Bob\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
