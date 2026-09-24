#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n; 
        cin >> n;
        int b[n + 5];
        int a[n + 5];
        for (int i = 1; i < n; i++) {
            cin >> b[i];
        }
        b[0] = b[1];
        b[n] = b[n - 1];
        for (int i = 1;i <= n; i++) {
            a[i] = min(b[i], b[i - 1]);
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
