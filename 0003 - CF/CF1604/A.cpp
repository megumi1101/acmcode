#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e6 + 10;
    void sol() {
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mx = max(x - i, mx);
        }
        cout << mx << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
