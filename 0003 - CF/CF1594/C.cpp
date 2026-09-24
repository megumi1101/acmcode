#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 1e9 + 7;
    int d[300005];
    void init() {
        for (int n = 3; n <= 300000; n++){
            int p = 0;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    p = i;
                    break;
                }
            }
            if (!p) p = n;
            d[n] = n / p;
        }
            
    }
    void sol() {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s = ' ' + s;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == c) {
                cnt++;
            }
        }
        if (cnt == n) {
            cout << "0\n";
            return;
        }
        int res = 0;
        
        for (int i = n; i != res; i--) {
            if (s[i] == c) {
                cout <<"1\n" << i << "\n";
                return;
            }
            res = max(res, d[i]);
        }
        cout <<"2\n";
        cout << n - 1 << " " << n << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        init();
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
