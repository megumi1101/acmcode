#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    ;
    int n, s, x;
    cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    if (sum <= s) {
        if ((s - sum) % x == 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
