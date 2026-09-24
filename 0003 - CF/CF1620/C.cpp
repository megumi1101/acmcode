#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        int res = 0;
        vector<int> a;
        vector<int> pos;
        vector<int> vis(n + 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') res++;
            if (s[i] == '*' && res == 1) {
                pos.push_back(i);
            }
            if (s[i] != '*') {
                if (res) a.push_back(res * k);
                res = 0;
            } 
        }
        
        if (res) a.push_back(res * k);
        int m = a.size();
        vector<int> b(m);
        vector<__int128> mul(m + 1);
        int tmp;
         mul[m] = 1;
        
        for (int i = 0; i < m; i++) {
            vis[pos[i]] = i + 1;
        }
 
 
        for (int i = m - 1; i >= 0; i--) {
            mul[i] = (a[i] + 1) * mul[i + 1];
            if (mul[i] >= x) {
                tmp = i;
                break;
            }
        }
 
        int now = 0;
        for (int i = tmp; i < m; i++) {
            for (int j = 1; j <= a[i] + 1; j++) {
                if (now + j * mul[i + 1] >= x) {
                    b[i] = j - 1;
                    now += b[i] * mul[i + 1];
                    break;
                }
            }
        }
        
        // for (int i = 0; i < m; i++) cerr << b[i] << " ";
        // cout << "\n";
 
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') cout << 'a';
            if (vis[i]) {
                for (int j = 1; j <= b[vis[i] - 1]; j++) {
                    cout << 'b';
                }
            }
        }
        cout << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
