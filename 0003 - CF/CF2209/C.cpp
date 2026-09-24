#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    
 
    auto ask = [&](int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        int t;
        cin >> t;
        return t;
    };
 
    for (int i = 3; i <= 2 * n; i += 2) {
        int t = ask(i, i + 1);
        if (t == 1) {
            cout << "! " << i << endl;
            return;
        }
    }
 
    int x = ask(1, 3) | ask(1, 4);
    if (x) {
        cout << "! 1" << endl;
    } else {
        cout << "! 2" << endl;
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
