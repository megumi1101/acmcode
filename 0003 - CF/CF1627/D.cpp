#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 1;
    struct node {
        int x, y, z;
        node (int x, int y, int z) : x(x), y(y), z(z) {}
    };
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    void sol() {
        int n;
        cin >> n;
        vector<bool> f(N);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            f[x] = 1;
        }
        int ans = 0;
        for (int i = N - 1; i >= 1; i--) {
            if (f[i]) continue;
            int cnt = 0;
            int x = 0;
            for (int j = 2; i * j < N; j++) {
                if (f[i * j]) x = gcd(x, j);
                if (x == 1) break;
            }
            if (x == 1) ans++;
        }
        cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
/*
3 3
010
101
010
*/
