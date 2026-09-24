#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() { 
        string s;
        cin >> s;
        for (auto x : s) {
            if (x == 'T') cout << x;
        }
        for (auto x : s) {
            if (x != 'T') cout << x;
        }
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
 
int main() {
    return Xbbbz::main(), 0;
}
