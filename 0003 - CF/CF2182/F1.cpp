#include<bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    while (m--) {
        int op;
        long long x;
        cin >> op >> x;
        if (op == 1) {
            a.push_back(x);
            sort(a.rbegin(), a.rend());
        } else if (op == 2) {
            a.erase(find(a.begin(), a.end(), x));
        } else {
            vector<int> bits;
            for (int i = 60; i >= 0; i--) {
                if ((x >> i) & 1) bits.push_back(i);
            }
            vector f(bits.size() + 1, array<int, 61>{{}});
            f[0][0] = 1;
            auto nf = f;
            long long ans = 0;
            for (auto ci : a) {
                ans = (ans + ans) %mod;
                for (int i = 0; i <= bits.size(); i++) {
                    for (int num = 0; num <= 60; num++) {
                        if (f[i][num]) {
                            if (ci - num > bits[i])
                                (ans += f[i][num]) %= mod;
                            else if (ci - num == bits[i]) {
                                if (i + 1 < bits.size()) (nf[i + 1][min(num + 1, 60)] += f[i][num]) %= mod;
                                else (ans += f[i][num]) %= mod;
                            }
                        }
                    }
                }
                f = nf;                
            }
 
            cout << ans << "\n";
        }
    }
}
