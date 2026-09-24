#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
 
    auto ask = [&](int x, int y) -> bool {
        cout << "? " << x << " " << y << endl;
        int tx, ty;
        cin >> tx >> ty;
        swap(pos[a[tx]], pos[a[ty]]);
        swap(a[tx], a[ty]);
        if (x == tx && y == ty) {
            return 1;
        }
        return 0;
    };
 
    for (int i = 1; i <= n / 2; i++) {
        while (pos[i] != i) {
            ask(pos[i], i);
        }
        while (pos[n - i + 1] != n - i + 1 || pos[i] != i) {
            if (pos[n - i + 1] != n - i + 1) ask(pos[n - i + 1], n - i + 1);
            else ask(pos[i], i);
        }
        
    }
    cout << "!" << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
