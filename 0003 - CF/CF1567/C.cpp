#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 3e5 + 10;
    int a[12];
    int f[12][2][2];
 
    int dfs(int len, int now, int last) {
        if (f[len][now][last] != -1) return f[len][now][last];
        int res = 0;
        if (len == 0) {
            if (now == 0 && last == 0) return 1;
            else return 0;
        }
        if (now) {
            int down = a[len] + 1;
            for (int i = down; i <= 9; i++) {
                res += dfs(len - 1, last, 0);
            }
            down--;
            for (int i = down; i <= 9; i++) {
                res += dfs(len - 1, last, 1);
            }
        }
        else {
            int up = a[len];
            for (int i = 0; i <= up; i++) {
                res += dfs(len - 1, last, 0);
            }
            up--;
            for (int i = 0; i <= up; i++) {
                res += dfs(len - 1, last, 1);
            }
        }
        return f[len][now][last] = res;
    }
 
    void sol() {
        int n;
        int cnt = 0;
        cin >> n;
        while (n) {
            a[++cnt] = n % 10;
            n /= 10;
        }
        memset(f, -1, sizeof(f));
        cout << dfs(cnt, 0, 0) - 2 << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
