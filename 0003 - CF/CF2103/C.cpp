#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    bool t1(int *a, int n, int k) {
        int l = 0, r = 0;
        int res1 = 0, res2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 > res2) {
                l = i;
                break;
            }
            if (res1 == res2 &&  res1 > 0) {
                l = i;
                break;
            }
        }
        res1 = 0, res2 = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 > res2) {
                r = i;
                break;
            }
            if (res1 == res2 &&  res1 > 0) {
                r = i;
                break;
            }
        }
        if (l && r && l < r) {
            return 1;
        }
        return 0;
    }
    bool t2(int *a, int n, int k) {
        int l = 0, r = 0;
        int res1 = 0, res2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 == res2 &&  res1 > 0) {
                l = i;
                break;
            }
            if (res1 - res2 == 2 &&  res1 > 0) {
                l = i - 1;
                break;
            }
        }
        res1 = 0, res2 = 0;
        for (int i = l + 1; i <= n; i++) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 > res2 && i < n) {
                return 1;
            }
            if (res1 == res2 &&  res1 > 0 && i < n) {
                return 1;
            }
        }
        return 0;
    }
    bool t3(int *a, int n, int k) {
        int l = 0, r = 0;
        int res1 = 0, res2 = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 == res2 &&  res1 > 0) {
                r = i;
                break;
            }
            if (res1 - res2 == 2 &&  res1 > 0) {
                r = i + 1;
                break;
            }
        }
        res1 = 0, res2 = 0;
        for (int i = r - 1; i >= 1; i--) {
            if (a[i] <= k) res1++;
            else res2++;
            if (res1 > res2 && i > 1) {
                return 1;
            }
            if (res1 == res2 &&  res1 > 0 && i > 1) {
                return 1;
            }
        }
        return 0;
    }
    void sol() {
        int ans = 0;
        int n, k;
        cin >> n >> k;
        int a[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (t1(a, n ,k) || t2(a, n ,k) || t3(a, n ,k)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
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
