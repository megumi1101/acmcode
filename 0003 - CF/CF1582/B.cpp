#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n;
        cin >> n;
        int tmp = 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 0) tmp *= 2;
            if (x == 1) res++;
        }
        cout << res * tmp << "\n"   ;
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
