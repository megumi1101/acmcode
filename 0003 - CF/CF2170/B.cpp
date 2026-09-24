#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int ans = 0;
        int cnt = 0;
        for (auto &i : a) {cin >> i; sum += i; if (i) cnt++;}
        ans = min(cnt, sum - n + 1);
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
