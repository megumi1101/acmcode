#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n, k;
        cin >> n >> k;
        if (n == k) {
            cout << "0\n";
        }
        else if (n % k == 0 || k % n == 0) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
