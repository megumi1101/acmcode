#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    
 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x & 1) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    if (!b.size()) {
        for (int i = 1; i <= n; i++) {
            if (i & 1) cout << a[0] << " ";
            else cout << "0 ";
        }
        cout << "\n";
        return;
    }
 
    if (!a.size()) {
        for (int i = 1; i <= n; i++) cout << "0 ";
        cout << "\n";
        return;
    }
    
 
    cout << a[0] << " ";
    int sum = a[0];
    for (int i = 0; i < b.size(); i++) {
        sum = sum + b[i];
        cout << sum << " ";
    }
 
    while (1) {
        if (a.size() == 1) {
            break;
        }
        else if (a.size() == 2) {
            cout << "0 ";
            break;
        }
 
        cout << sum - b[(int)b.size() - (int)1] << " " << sum << " ";
        a.pop_back();
        a.pop_back();
    }
 
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
