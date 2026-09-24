#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + c - b - b) % 3) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
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
/*
1 3
5 4 3
*/
