#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);

    int mnodd = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            mnodd = min(mnodd, a[i]);
        }
    }
    sort(a.begin(), a.end());


    vector<int> p;
    p.reserve(n);
    int ans = 0;
    while (1) {
        ans++;
        int nod = 1e9;
        bool first = 1;
        for (auto x : a) {
            if ((x & 1) && x == mnodd && first) {
                first = 0;
                int t = x / 2;
                if (t) p.push_back(t);
                if (t & 1) nod = min(nod, t);
            } else {
                int t = (x + 1) / 2;
                if (t) p.push_back(t);
                if (t & 1) nod = min(nod, t);
            } 
        }
        if (p.empty() || p.back() == 1) {
            ans += p.size();
            break;
        }
        swap(a, p);
        p.clear();
        mnodd = nod;
    }
    cout << ans << "\n";
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}