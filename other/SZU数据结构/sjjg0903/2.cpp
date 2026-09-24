#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    struct Vec {
        vector<int> a;
        Vec (int n_) {
            init(n_);
        }
        
        void init(int n) {
            a.assign(n, 0);
        }

        void get() {
            for (int i = 0; i < a.size(); i++) cin >> a[i];
        }

        void multiinsert(int i, int n, vector<int> &item) {
            vector<int> tmp;
            for (int k = 0; k < i; k++) {
                tmp.emplace_back(a[k]);
            }
            for (auto x : item) tmp.emplace_back(x);
            for (int k = i; k < a.size(); k++) {
                tmp.emplace_back(a[k]);
            }
            a = tmp;
        }

        void multidel(int i, int n) {
            vector<int> tmp;
            for (int k = 0; k < a.size(); k++) if(k < i || k >= i + n) {
                tmp.emplace_back(a[k]);
            }
            a = tmp;
        }
        
        void pr() {
            cout << a.size() << " ";
            for (auto x : a) cout << x << " ";
            cout << "\n";
        }
    };
    void sol() {
        int n;
        cin >> n;
        Vec v(n);
        v.get();
        v.pr();

        int x, y;
        cin >> x >> y;
        vector<int> b(y);
        for (int i = 0; i < y; i++) cin >> b[i];

        v.multiinsert(x - 1, y, b);
        v.pr();

        cin >> x >> y;
        v.multidel(x - 1, y);
        v.pr();
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