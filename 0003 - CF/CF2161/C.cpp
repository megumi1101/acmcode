#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9 + 10000;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        deque<int> q;
        int sum = 0;
        for (auto &x : a) {
            q.push_back(x);
            sum += x;
        }
        
        int ans = 0;
        vector<int> tmp;
        while (!q.empty()) {
            int u = q.front();
            int v = q.back();
            if (sum / k != ((sum - v) / k)) {
                ans += v;
                sum -= v;
                q.pop_back();
                tmp.push_back(v);
            }
            else {
                sum -= u;
                q.pop_front();
                tmp.push_back(u);
 
            }
        }
        cout << ans << '\n';
        reverse(tmp.begin(), tmp.end());
        for (auto &x : tmp) cout << x << " ";
        cout << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
