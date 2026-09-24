#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
const int inf = 1e9; 
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
vector<int> vis, pr;
    void init() {
        vis.assign(2e7 + 10, 0);
        int n = 2e7;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr.push_back(i);
            }
            for (int j : pr) {
                if (i * j > n) break;
                int m = i * j;
                vis[m] = 1;
                if (i % j == 0) break; 
            }
        }
    }
    void sol() {
        int n;
        cin >> n >> seed;
        vector<uint> a(n + 1);
        for (int i = 1; i <= n; i++) a[i] = getnext();
        for (int j : pr) {
            for (int i = 1; i * j <= n; i++) {
                a[i * j] += a[i]; 
            }
        }
        uint x = 0;
        for (int i = 1; i <= n; i++) x ^= a[i];
        cout << x; 
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
