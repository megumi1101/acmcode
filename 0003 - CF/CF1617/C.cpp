#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        set<int> s;
        vector<int> a(n + 1), b;
        for (int i = 1; i <= n; i++) s.insert(i);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] >= 1 && a[i] <= n) {
                auto it = s.find(a[i]);
                if (it != s.end()) {
                    s.erase(it);
                    continue;
                } 
            }
            b.push_back(a[i]);
        }
        sort(b.rbegin(), b.rend());
        int ans = s.size();
        while (!s.empty()) {
            auto it = s.begin();
            int x = *it;
            int y = b.back();
            if (y > 2 * x) {
                b.pop_back();
                s.erase(it);
            } else {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
