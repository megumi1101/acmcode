#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) ans++;
        }
        if (n == 2) {
            cout << "Alice\n";
        }
        else if (n == 3) {
            if (ans == 2) cout << s << "\n";
            else {
                if (s == "Alice") cout << "Bob\n";
                else cout << "Alice\n";
            }
        }
        if (n >= 4) {
            if ((ans == 2 && s == "Alice") || (ans == 0 && s == "Bob")) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
