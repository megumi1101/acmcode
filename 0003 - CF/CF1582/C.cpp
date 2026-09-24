#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        char a = '0', b = '0';
        for (int i = 1; i <= n / 2; i++) {
            int j = n - i + 1;
            if (s[i] != s[j]) {
                a = s[i];
                b = s[j];
                break;
            }
        }
        if (a == '0') {
            cout << "0\n";
            return;
        }
        int l = 1, r = n;
        int res = 0;
        int ans = 1e9;
        bool fg = 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                if (s[l] == a) {
                    l++;
                    res++;
                } else if (s[r] == a) {
                    r--;
                    res++;
                } else {
                    fg = 0;
                    break;
                }
            }
        }
        if(fg) ans = min (res, ans);
        fg = 1;
        l = 1, r = n;
        res = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                if (s[l] == b) {
                    l++;
                    res++;
                } else if (s[r] == b) {
                    r--;
                    res++;
                } else {
                    fg = 0;
                    break;
                }
            }
        }
        if (fg) ans = min (res, ans);
        if (ans == (int)1e9) ans = -1;
        cout << ans << "\n";
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
