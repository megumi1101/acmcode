#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int lowbit(int x) {
    return x & (-x);
}
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[n] = 1;
    vector<int> vis(n + 1);
    for (int i = 1; i < n; i++) a[i] = i ^ 1, vis[a[i]] = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) a[1] = i;
 
    if (n & 1) {
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        return;
    }
    
    if (lowbit(n) == n) {
        cout << "-1\n";
        return;
    }
    swap(a[1], a[lowbit(n)]);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        return;
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
