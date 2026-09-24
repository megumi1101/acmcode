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
        s = " " + s;
        int a[n + 5];
        bool vis[n + 5];
        memset(vis, 0 ,sizeof(vis));
        int l = 1, r = n;
        for (int i = n - 1; i >= 1; i--) {
            if (s[i] == '>') {
                a[i + 1] = r--;
            }
            else {
                a[i + 1] = l++;
            }
        }
        a[1] = l;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
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
