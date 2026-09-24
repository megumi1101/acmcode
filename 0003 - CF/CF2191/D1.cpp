#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = n / 2 - 1;
    for (int i = 0; i < x; i++) {
        if (s[i] == ')') {
            cout << x * 2 << "\n";
            return;
        }
    }
 
    cout << "-1\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
