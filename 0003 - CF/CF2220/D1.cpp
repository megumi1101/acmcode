#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    int alln = n * 2 + 1;
    int Mxbit = log2(alln);
    auto ask = [&](vector<int> &b, int op) -> pair<int, int> {
        vector<int> v;
        for (int i = 1; i <= alln; i++) {
            bool fg = 1;
            for (int bit = 0; bit <= Mxbit; bit++) {
                int t = (i >> bit) & 1;
                if (b[bit] != -1 && b[bit] != t) fg = 0;
            }
            if (fg) v.push_back(i);
        }
 
        if (op == 0) {
            vector<int> vis(alln + 1);
            for (auto x : v) vis[x] = 1;
            v.clear();
            for (int i = 1; i <= alln; i++) {
                if (vis[i] == 0) v.push_back(i);
            }
        }
        
        cout << "? " << v.size() << " ";
        for (auto x : v) cout << x << " ";
        cout << endl;
 
        int tt;
        cin >> tt;
        return {tt, v.size()};
    };
    
 
    vector<int> ans;
    vector<int> b(Mxbit + 1, -1);
    [&](this auto &&self, vector<int> &b, int cnt) -> void {
        if (cnt == 0) return;
        bool fg = 1;
        
        vector<int> v;
        for (int i = 1; i <= alln; i++) {
            bool fg = 1;
            for (int bit = 0; bit <= Mxbit; bit++) {
                int t = (i >> bit) & 1;
                if (b[bit] != -1 && b[bit] != t) fg = 0;
            }
            if (fg) v.push_back(i);
        }
        if (v.size() == 1 && cnt == 1) {
            ans.push_back(v[0]);
            return;
        }
        // cout << "    !!!!!!    " << v.size() << " ";
        // for (auto x : v) cout << x << " ";
        // cout << "\n";
        // cout << "    !!!!!!    " << cnt << " \n";
 
 
        for (int bit = 0; bit <= Mxbit; bit++) {
            if (b[bit] == -1) {
                fg = 0;
                auto c = b;
                c[bit] = 0;
                auto[t1, siz1] = ask(c, 1);
                auto[t2, siz2] = ask(c, 0);
                if (t1 > t2) {
                    self(c, 1);
                    c[bit] ^= 1;
                    self(c, cnt - 1);
                } else if (t2 > t1) {
                    self(c, 2);
                    c[bit] ^= 1;
                    self(c, cnt - 2);
                } else {
                    if ((siz1 - t1) & 1) {
                        self(c, 3);
                    }
                    else {
                        c[bit] ^= 1;
                        self(c, cnt);
                    }
                }
                break;
            }
        }
        // if (fg) {
        //     int res = 0;
        //     for (int bit = 0; bit <= Mxbit; bit++) {
        //         res += (1 << b[bit]);
        //     }
        //     ans.push_back(res);
        // }
    }(b, 3);
    // vector<array<int, 2>> f(11, {0, 0});
    // for (int bit = 0; bit < 11; bit++) {
    //     auto[op0, size0] = ask(bit, 0);
    //     auto[op1, size1] = ask(bit, 1);
    //     if (op0 != op1) f[bit][0] = f[bit][1] = 1;
    //     else {
    //         if ((size0 - op0) & 1) f[bit][0] = 1;
    //         else f[bit][1] = 1;
    //     }
    // }   
 
    // vector<int> ans;
    // for (int i = 1; i <= alln; i++) {
    //     bool fg = 1;
    //     for (int bit = 0; bit < Mxbit; bit++) {
    //         if (f[bit][(i >> bit) & 1] == 0) fg = 0;
    //     }
    //     if (fg) ans.push_back(i);
    // }
    sort(ans.begin(), ans.end());
    cout << "! ";
    for (auto x : ans) cout << x << " ";
    cout << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
 
/*
1
2
? 2 2 4 
2
? 3 1 3 5 
1
? 1 4 
1
? 4 1 2 3 5 
0
? 0 
0
? 5 1 2 3 4 5 
0
? 2 1 5 
2
? 3 2 3 4 
1
? 1 1 
1
? 4 2 3 4 5 
1
? 1 3 
2
? 4 1 2 4 5 
0
*/
