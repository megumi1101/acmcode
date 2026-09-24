#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
 
        string s;
        cin >> s;
 
        long long x = 0;
        int a = 0;
        int b = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                a++;
                if ((i + 1) % 2 == 0) {
                    b++;
                }
            }
            if (s[i] == 'P') {
                x += a;
            }
        }
 
        int d = abs(a / 2 - b);
        cout << (x + d) / 2 << '\n';
        
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
