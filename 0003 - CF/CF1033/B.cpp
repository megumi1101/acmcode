#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    bool pd (int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    void sol() {
        int a, b;
        cin >> a >> b;
        if (a - b == 1 && pd(a + b)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
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
