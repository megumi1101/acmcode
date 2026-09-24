#include <bits/stdc++.h>
 
using namespace std;
const int mod = 998244353;
 
void sol() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cout << "? " << i << " " << i + 1 <<endl;
        cin >> p[i];
    }
    int lst = -1;
    for (int i = 1; i + 1 < n; i++) {
        if (p[i] && !p[i + 1]) {
            lst = i;
        }
    }
    if (lst == -1) {
        cout << "! -1" << endl;
        return;
    }
 
    vector<int> a, b;
    int tt = n;
    for (int i = lst + 1; i < n; i++) {
        if (!p[i]) a.push_back(i);
        else {
            tt = i;
            break;
        }
    }
    for (int i = tt; i <= n; i++) b.push_back(i);
    reverse(a.begin(), a.end());
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
 
 
    int ta = -1, tb = -1;
    for (int i = 0; i < a.size(); i++) {
        cout << "? " << lst << " " << a[i] << endl;
        int x;
        cin >> x;
        if (x) {
            ta = i;
            break;
        }
    }
    
    for (int i = 0; i < b.size(); i++) {
        cout << "? " << lst << " " << b[i] << endl;
        int x;
        cin >> x;
        if (x) {
            tb = i;
            break;
        }
    }
 
    if (tb != -1) {
        cout << "? " << a[ta] << " " << b[tb] << endl;
        int x;
        cin >> x;
        if (x == 1) {
            ans[lst] = a[ta];
            a[ta] = lst;
        } else {
            ans[lst] = b[tb];
            b[tb] = lst;
        }
    } else {
        ans[lst] = a[ta];
        a[ta] = lst;
    }
    
    int l = 0, r = 0;
    int now = lst + 1;
    while (1) {
        if (l == a.size() && r == b.size()) break;
        else if (l == a.size()) {
            ans[now++] = b[r++];
        } else if (r == b.size()) {
            ans[now++] = a[l++];
        } else {
            cout << "? " << a[l] << " " << b[r] << endl;
            int x;
            cin >> x;
            if (x) {
                ans[now++] = a[l++];
            } else {
                ans[now++] = b[r++];
            }
        }
    }
 
 
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
