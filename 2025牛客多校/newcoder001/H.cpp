#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    struct Bit {
        int n;
        vector<int> a, tun, qian, hou, c, ts;
        Bit (int n_ = 0) {
            n = n_;
            init(n);
        }
        void init(int n) {
            a.assign(n / 20 + 5, 0);
            ts.assign(n / 20 + 5, 0);
            tun.assign(1 << 20, 0);
            qian.assign(1 << 20, 0);
            hou.assign(1 << 20, 0);
            c.assign(1 << 20, 0);
            for (int i = 0; i < (1 << 20); i++) {
                for (int j = 0; j < 20; j++) {
    
                }
            }
        }
    };

    void sol() {
        

    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}