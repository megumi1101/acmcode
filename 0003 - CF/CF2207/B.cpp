#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n, m, l;
    cin >> n >> m >> l;
    multiset<int> s;
    for (int i = 0; i < min(m, n + 1); i++) s.insert(0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int lst = 1;
    for (int i = 0; i < n; i++) {
        for (int j = lst; j <= a[i]; j++) {
            auto it = s.begin();
            int x = *it + 1;
            s.erase(it);
            s.insert(x);
        }
        lst = a[i] + 1;
        auto it = s.rbegin();
        s.extract(*it);
        if (s.size() < n - i) s.insert(0);
    }
    int x = *s.rbegin();
    cout << x + l - a[n - 1] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
