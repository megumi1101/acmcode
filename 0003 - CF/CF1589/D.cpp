#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    map<int, int> mp;
    bool pd(int mid, int n, int sum) {
        cout << "? " << mid << " " << n << endl;
        int x;
        cin >> x;
        if (x == sum) return 1;
        else {
            return 0;
        }
    }
    void sol() {
        mp.clear();
        int n;
        cin >> n;
        cout << "? 1 " << n << endl;
        int sum;
        cin >> sum;
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pd(mid, n, sum)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << "? " << ans + 1 << " " << n << endl;
        int i = ans;
        int x;
        cin >> x;
        int j = i + sum - x + 1;
        cout << "? " << j << " " << n << endl;
        cin >> x;
        int y;
        cout << "? " << j + 1 << " " << n << endl;
        cin >> y;
        int k =  j + x - y;
        cout << "! " << i << " " << j << " " << k << endl;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
