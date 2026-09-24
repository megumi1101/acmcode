#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> na;
        int now = 0;
        vector<pair<int, int>> ans; 
        vector<int> ans2; 
        auto del = [&]() -> bool {
            na.clear();
            int x;
            for (int i = 0; i < a.size(); i++) {
                if (i == 0) x = a[i];
                if (i == 0) continue;
                if (a[i] == x) {
                    for (int j = 1; j < i; j++) {
                        ans.emplace_back(now + i + j, a[j]);
                    }
                    
                    for (int j = i - 1; j > 0; j--) {
                        na.push_back(a[j]);
                    }
                    for (int j = i + 1; j < a.size(); j++) {
                        na.push_back(a[j]);
                    }
                    now += i * 2;
                    a = na;
                    ans2.push_back(i * 2);
                    return 1;          
                }
            }
            return 0;
        };
 
        while (del()){;}
        if (a.size()) {
            cout << -1 << "\n";
            return;
        }
        cout << ans.size() << "\n";
        for (auto[x, y] : ans) cout << x  << " " << y << "\n";
        cout << ans2.size() << "\n";
        for (auto x : ans2) cout << x << " ";
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
