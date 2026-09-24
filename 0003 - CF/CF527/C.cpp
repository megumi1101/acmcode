#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    int n, m, q;
    set<int> sx, sy;
    multiset<int> msx, msy;
    void cutx (int x) {
        auto itr = sx.lower_bound(x);
        auto itl = prev(itr);
        int l = *itl;
        int r = *itr;
        sx.insert(x);
        msx.erase(msx.find(r - l));
        msx.insert(r - x);
        msx.insert(x - l);
    }
    void cuty (int y) {
        auto itr = sy.lower_bound(y);
        int r = *itr;
        auto itl = prev(itr);
        int l = *itl;
        sy.insert(y);
        msy.erase(msy.find(r - l));
        msy.insert(r - y);
        msy.insert(y - l);
    }
    int getans() {
        auto itx = msx.end();
        auto ity = msy.end();
        return (*prev(itx)) * (*prev(ity));
    }
    void sol() {
        cin >> n >> m >> q;
        sx.insert(0);
        sx.insert(n);
        sy.insert(0);
        sy.insert(m);
        msx.insert(n);
        msy.insert(m);
        while (q--) {
            char c;
            int x;
            cin >> c >> x;
            if (c == 'H') {
                cuty(x);
            }
            else {
                cutx(x);
            }
            cout << getans() << "\n";
            // cout.flush();
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}

int main() {
    return Xbbbz :: main(), 0;
}
