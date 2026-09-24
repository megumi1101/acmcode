#include <bits/stdc++.h>
 
using namespace std;
 
void sol_a() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<bool> vis(n + m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
 
    vector<int> st;
    for (int i = 1; i <= n + m; i++) {
        if (vis[i]) {
            st.push_back(i);
        } else {
            if (!st.empty()) {
                st.pop_back();
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (a[i] != st[0]) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
 
void sol_b() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n - 1);
    vector<bool> vis(n + m + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
 
    vector<int> st;
    int ans = 0;
    for (int i = 1; i <= n + m; i++) {
        if (vis[i]) {
            st.push_back(i);
        } else {
            if (!st.empty()) {
                st.pop_back();
            } else {
                ans = i;
            }
        }
    }
 
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string rol;
    int t = 1;
    cin >> rol >> t;
    
    if (rol == "Alice") {
        while (t--) sol_a();
    } else if (rol == "Bob") {
        while (t--) sol_b();
    }
    
}
 
/*
Bob
2
4 2
1 4 5
3 1
2 3
*/
