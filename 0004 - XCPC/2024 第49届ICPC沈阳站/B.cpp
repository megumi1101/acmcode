#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
    void sol() {
        int n, m;
        cin >> n >> m;
 
        if (n == 1 && m == 1) {
            cout << "Yes\n";
            cout << "0\n0\n";
            return;
        }
        if (n == 1) {
            cout << "Yes\n";
            cout << 1 << "\n";
            for (int i = 0; i < m; i++) cout << i << " ";
            cout << "\n";
            return;
        }
 
        if (m == 1) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) cout << i << " ";
            cout << "\n";
            cout << 1 << "\n";
            return;
        }
 
        vector<int> a;
        a.reserve(1e6 + 10);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n * m; j += n) {
                if (gcd(m, j) == 1) {
                    a.push_back(j);
                    break;
                }
            }
        }
        if (a.size() == n) {
            vector<int> b;
            b.reserve(1e6 + 10);
            for (int i = 1; i < n * m; i += n) {
                b.push_back(i);
            }
 
            cout << "Yes\n";
            for (auto x : a) cout << x << " ";
            cout << "\n";
            for (auto x : b) cout << x << " ";
            cout << "\n";
            return;
        }
 
 
        swap(n, m);
        a.clear();
        a.reserve(1e6 + 10);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n * m; j += n) {
                if (gcd(m, j) == 1) {
                    a.push_back(j);
                    break;
                }
            }
        }
        if (a.size() == n) {
            vector<int> b;
            b.reserve(1e6 + 10);
            for (int i = 1; i < n * m; i += n) {
                b.push_back(i);
            }
 
            cout << "Yes\n";
            for (auto x : b) cout << x << " ";
            cout << "\n";
            for (auto x : a) cout << x << " ";
            cout << "\n";
            return;
        }
 
        cout << "No\n";
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
