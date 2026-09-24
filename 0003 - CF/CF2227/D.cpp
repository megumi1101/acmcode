#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    
 
    auto getmex = [&](vector<int> &v) -> int {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        int now = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == i) now++;
            else {
                break;
            }
        }
        return now;
    };
 
    vector<int> a(2 * n + 1);
 
    int f0 = -1, s0 = -1;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (f0 == -1) {
                f0 = i;
            } else {
                s0 = i;
            }
        }
    }
 
    int ans = 0;
    auto get = [&](int l, int r) -> void {
        vector<int> v;
        while (l >= 1 && r <= 2 * n) {
            if (a[l] == a[r]) {
                v.push_back(a[l]);
            } else {
                break;
            }
            l--; r++;
        }
        ans = max(ans, getmex(v));
    };
 
    get(f0, f0);
    get(s0, s0);
    get((f0 + s0) / 2, (f0 + s0 + 1) / 2);
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
