#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Basis {
    int LOG;                       
    vector<int> a;                  
    Basis(int LOG_ = 61): LOG(LOG_), a(LOG, 0) {}
    void insert(int x){
        for (int i = LOG - 1; i >= 0; i--){
            if (((x >> i) & 1LL) == 0) continue;
            if (a[i] == 0) { a[i] = x; return; }
            x ^= a[i];
        }
    }

    int getMax() {
        int res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            res = max(res, res ^ a[i]);
        }
        return res;
    }
};

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    int xsum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xsum ^= a[i];
    }
    
    Basis bs;
    for (int i = 1; i <= n; i++) {
        a[i] |= xsum;
        bs.insert(a[i]);
    }

    int ans = bs.getMax();
    ans ^= xsum;
    ans = ans * 2 + xsum;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
4
1
1
3
1 2 3
4
1 1 3 3
4
1 2 2 3
*/