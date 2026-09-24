#include <bits/stdc++.h>

using namespace std;

#define int long long
void sol() {
    int n, k;
    cin >> n >> k;
    int mx = 0;

    int rt = (n - 1) / 2;
    int lf = n - 1 - rt;
    for (int i = 1; i <= rt; i++) {
        mx += i * 2;
    }
    for (int i = 1; i <= lf; i++) {
        mx += i * 2;
    }

    int mn = (n - 1) * 2;
    if (k >= mn && k <= mx && k % 2 == 0) {
        if (k == mn) {
            for (int i = 1; i < n; i++) {
                cout << i << " " << i + 1 << "\n";
            }
            return;
        }
        vector<int> a(lf + 1, 0);
        vector<int> b(rt + 1, 0);
        int now = mn;
        int nl = lf, nr = rt;
        while (now < k) {
            if (now < k) {
                if (now + nl * 2 <= k) {
                    now += nl * 2 - 2;
                    a[nl--] = 1;
                    
                } else {
                    int dt = (k - now) / 2;
                    a[dt + 1] = 1;
                    break;
                } 
            } 

            if (now < k) {
                if (now + nr * 2 <= k) {
                    now += nr * 2 - 2;
                    b[nr--] = 1;
                } else {
                    int dt = (k - now) / 2;
                    b[dt + 1] = 1;
                    break;
                } 
            }   
        }

        // cout << "-1\n";
        // for (int i = 1; i <= lf; i++) cout << a[i] << "\n";
        // for (int i = 1; i <= rt; i++) cout << b[i] << "\n";
        vector<int> ansl(lf + 2), ansr(rt + 2);
        ansl[0] = ansr[0] = 1;
        nl = 1, nr = 1;
        now = 1;
        int op = 0, tun = 0;
        while (nl <= lf || nr <= rt) {
            if (op == 0) {
                if (a[nl] == 0) {
                    ansl[nl] = ++now;
                    nl++;
                    tun = 0;
                } else {
                    if (tun == 1) {
                        ansl[nl] = ++now;
                        nl++;
                        tun = 0;
                    } else {
                        op ^= 1;
                        tun = 1;
                    }
                }
                if (nl > lf) {
                    op ^= 1;
                    tun = 1;
                }
            } else {
                if (b[nr] == 0) {
                    ansr[nr] = ++now;
                    nr++;
                    tun = 0;
                } else {
                    if (tun == 1) {
                        ansr[nr] = ++now;
                        nr++;
                        tun = 0;
                    } else {
                        op ^= 1;
                        tun = 1;
                    }
                }
                if (nr > rt) {
                    op ^= 1;
                    tun = 1;
                }
            }
        }
        for (int i = 0; i < lf; i++) {
            cout << ansl[i] << " " << ansl[i + 1] << "\n";
        }
        for (int i = 0; i < rt; i++) {
            cout << ansr[i] << " " << ansr[i + 1] << "\n";
        }
    } else {
        cout << "-1\n";
        return;
    }

}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}