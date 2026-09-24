#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 3e5 + 10;
    int a[N];
 
    void init() {
        for (int i = 1; i <= (int)3e5; i++) {
            a[i] = a[i-1] ^ i;
        }
    }
 
    void sol() {
        int n, k;
        cin >> n >> k;
        int res = a[n-1];
        if ((k ^ res) == 0) {
            cout << n;
        }
        else if ((k ^ res) == n) {
            cout << n + 2;
        }
        else {
            cout << n + 1;
        }
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        init();
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
