#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        if (n & 1) cout << "0\n";
        else cout <<  n / 4 + 1 << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
