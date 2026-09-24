#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 20100403;
vector<int> f;
    void init() {
        int mx = 1e12;
        int res = 1;
        for (int i = 1; i <= 30; i++) {
            res *= i;
            if (res > mx) break;
            f.push_back(res);
        }
    }
 
    void sol() {
        int n;
        cin >> n;
        int ans = 1000000;
        for (int i = 0; i < (1 << f.size()); i++) {
            int res = 0;
            int tmp = 0;
            for (int j = 0; j < f.size(); j++) {
                if ((i >> j) & 1) {
                    res += f[j];
                    tmp++;
                }
            }
            if (res > n) continue;
            for (int k = 0; k < 45; k++) {
                if (((res >> k) & 1) != ((n >> k) & 1)) {
                    tmp++;
                    res += 1LL << k;
                }
            }
            ans = min(tmp, ans);
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
