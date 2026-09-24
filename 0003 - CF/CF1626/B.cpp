#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define ll long long
    void sol() {
        string s;
        cin >> s;
        int n = s.size();
        int fg = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = (s[i] - '0') * 10 + s[i + 1] - '0';
            int y = (s[i] - '0') + s[i + 1] - '0';
            // cerr << y << "\n";
            if (y >= 10) {
                fg = i;
            }
        }
        // cerr << fg << "  fg \n";
 
        if (fg >= 0) {
            for (int i = 0; i < fg; i++) {
                cout << s[i];
            }
            int y = (s[fg] - '0') + s[fg + 1] - '0';
            cout << y;
            for (int i = fg + 2; i < n; i++) {
                cout << s[i];
            }
        }
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
