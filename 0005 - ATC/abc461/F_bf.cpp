#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
signed main() {
    int n;
    cin >> n;

    vector<int> v;

    auto has = [&](int x) -> bool {
        for (auto i : v) if (x == i) return 1;
        return 0;
    };

    auto getf = [](int x){
        vector<int> p;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                p.push_back(i);
                if (i * i != x) {
                    p.push_back(x / i);
                }
            }
        }
        return p;
    };
    
    auto get = [&](this auto&& get, int x) -> pair<int, int> {
        if (x == 1) {
            if (has(x)) {
                return {0, 0};
            } else {
                return {1, 1};
            }
        }

        int sum = 0, cnt = 0;
        auto p = getf(x);
        for (auto i : p) {
            if (!has(i)) {
                v.push_back(i);
                auto[t1, t2] = get(x / i);
                sum += t1 + t2;
                cnt += t2;
                sum %= mod; cnt %= mod;
                v.pop_back();
            }
        }
        if (!has(x)) {
            sum++, cnt++;
        }
        return {sum, cnt};
    };

    int ans = 0;
    auto p = getf(n);
    for (auto i : p) {
        v.push_back(i);
        int t = n / i;
        auto[x, y] = get(t);
        ans += (x + y) * i % mod;
        ans %= mod;
        v.pop_back();        
    }
    ans += n;
    ans %= mod;
    cout << ans << "\n";
}