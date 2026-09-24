#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() { 
        auto getmax = [&] (int x) -> int {
            for (int i = 30; i >= 0; i--) {
                if ((x >> i) & 1) {
                    return i;
                }
            }
            return -1;
        };
        auto getmin = [&] (int x) -> int {
            for (int i = 30; i >= 0; i--) {
                if ((x >> i) & 1) {
                    return i;
                }
            }
            return inf;
        };
        int a, b, c;
        cin >> a >> b >> c;
        int maxa = getmax(a);
        int maxb = getmax(b);
        int maxc = getmax(c);
        int mina = getmin(a);
        vector<int> ans;
        
        if (maxb >= maxa && maxb >= maxc) {
            for (int i = maxb; i >= 0; i--) {
                if (a == b && a == c) break;
                int x = a >> i;
                int y = c >> i;
                if (x != y) {
                    ans.push_back(3);
                    a ^= b;
                }
                if (a == b && a == c) break;
                ans.push_back(2);
                b >>= 1;
            }
            if (a == c && a != b) {
                ans.push_back(4);
                b ^= a;
            }
        }
        else if (maxc >= maxa && maxc >= maxb) {
            if (maxa > maxb) {
                ans.push_back(4);
                b ^= a;
                maxb = maxa;
            // cerr << a << " " << b << " " << c << "\n";

            }
            else if (maxb > maxa) {
                ans.push_back(3);
                a ^= b;
                maxa = maxb;
            // cerr << a << " " << b << " " << c << "\n";

            }
            int tmp = maxc - maxa;
            
            for (int i = 1; i <= tmp; i++) {
                int tmp2 = maxc - i;
                if (a == b && a == c) break;
                ans.push_back(1);
                a <<= 1;
            // cerr << a << " " << b << " " << c << "\n";

                if (a == b && a == c) break;
                int x = a >> (maxa);
                int y = c >> tmp2;
                if (i == tmp) break;
                if (x != y) {
                    ans.push_back(3);
                    a ^= b;
            // cerr << a << " " << b << " " << c << "\n";

                }
            }

            for (int i = maxb; i >= 0; i--) {
                if (a == b && a == c) break;
                int x = a >> i;
                int y = c >> i;
                if (x != y) {
                    ans.push_back(3);
                    a ^= b;
            // cerr << a << " " << b << " " << c << "\n";
                    
                }
                if (a == b && a == c) break;
                ans.push_back(2);
                b >>= 1;
            // cerr << a << " " << b << " " << c << "\n";

            }
            if (a == c && a != b) {
                ans.push_back(4);
            // cerr << a << " " << b << " " << c << "\n";

                b ^= a;
            }
            // cerr << ans.size() << "\n";
            // cerr << a << " " << b << " " << c << "\n";
        }
        else if (maxa >= maxb && maxa >= maxc) {
            if (maxa > maxb) {
                ans.push_back(4);
                b ^= a;
                maxb = maxa;
            // cerr << a << " " << b << " " << c << "\n";
            }
            ans.push_back(3);
            a ^= b;
            for (int i = maxb; i >= 0; i--) {
                if (a == b && a == c) break;
                int x = a >> i;
                int y = c >> i;
                if (x != y) {
                    ans.push_back(3);
                    a ^= b;
                }
                if (a == b && a == c) break;
                ans.push_back(2);
                b >>= 1;
            }
            if (a == c && a != b) {
                ans.push_back(4);
                b ^= a;
            }
        }
        // else if (maxa == maxc && maxb < maxa) {
        //     bool fg = 1;
        //     for (int i = maxa; i > maxb; i--) {
        //          int x = a >> i;
        //          int y = c >> i;
        //          if (x != y) {
        //             fg = 0;
        //          }
        //     }
        //     if (fg) {
        //         for (int i = maxb; i >= 0; i--) {
        //             if (a == b && a == c) break;
        //             int x = a >> i;
        //             int y = c >> i;
        //             if (x != y) {
        //                 ans.push_back(3);
        //                 a ^= b;
        //             }
        //             if (a == b && a == c) break;
        //             ans.push_back(2);
        //             b >>= 1;
        //         }
        //         if (a == c && a != b) {
        //             ans.push_back(4);
        //             b ^= a;
        //         } 
        //     }
        // }
        // else if(maxa <= maxc && mina != inf) {
        //     if (a == b && a == c);
        //     else {
        //         int x = b >> mina;
        //         int y = c >> mina;
        //         if (x != y) {
        //             ans.push_back(4);
        //             b ^= a;
        //         }
        //     }
        //     for (int i = 1; i <= maxc - maxa; i++) {
        //         if (a == b && a == c) break;
        //         ans.push_back(1);
        //         a <<= 1;
        //         if (a == b && a == c) break;
        //         int x = b >> (mina + i);
        //         int y = c >> (mina + i);
        //         if (x != y) {
        //             ans.push_back(4);
        //             b ^= a;
        //         }
        //     }   
        // }

        // cout << 1;
        if (a == b && a == c) {
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << " ";
            cout << endl;
        }
        else {
            cout << "-1\n";
        }
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