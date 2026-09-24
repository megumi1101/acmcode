#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    bool pd (int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    int n;
    int a[105];
    void sol() {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        int cnt[105];
        for (int i = 2; i <= 100; i++) {
            bool flag = 0;
            if (!pd(i)) {
                continue;
            }
            memset(cnt, 0, sizeof(cnt));
            for (int j = 1; j <= n; j++) {
                cnt[a[j] % i]++;
            }
            for (int j = 0; j < i; j++) {
                if (cnt[j] < 2) {
                    flag = 1;
                }
            }
            if (!flag) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return Xbbbz :: main(), 0;
}
