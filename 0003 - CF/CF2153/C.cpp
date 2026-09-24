#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> b;
    int sum = 0;
    int cnt = 0;
    while (!a.empty()) {
        int x = -1, y = -1;
        x = a.back();a.pop_back();
        if (!a.empty()) {
            y = a.back();
        }
        if (x == y) {
            a.pop_back();
            sum += 2 * x;
            cnt += 2;
        } else {
            b.push_back(x);
        }
    }
    
    if (sum == 0) {
        cout << "0\n";
        return;
    }
    
    b.push_back(0);
    sort (b.begin(), b.end());
    int mx = 0;
    for (int i = 0; i < b.size(); i++) {
        int x = b[i];
        auto it = lower_bound(b.begin(), b.end(), b[i] + sum);
        it--;
        int y = *it;
        if (x != y) {
            mx = max(x + y, mx);
        }
        
    }if (cnt == 2 && mx == 0) {
            cout << "0\n";
        } else {
            cout << mx + sum << "\n";
        }
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
