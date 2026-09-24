#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
 
    int now = 0;
    int cnt = 0;
 
    for (int i = 0; i < n; i++) {
        if (now == 0) {
            cnt = 0;
            if (s[i] == ')' || t[i] == ')') {
                cout << "NO\n";
                return;
            }
        }
        if (s[i] == '(') now++;
        else now--;
        if (t[i] == '(') now++;
        else now--;
 
        cnt++;
        if (now < 0) {
            cout << "NO\n";
            return;
        }
        if (now == 0 && (cnt & 1)) {
            cout << "NO\n";
            return;
        }
    }
 
    if (now == 0) {
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
