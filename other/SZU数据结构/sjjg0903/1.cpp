#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        auto pr = [&]() ->void {
            cout << a.size() << " ";
            for (auto x : a) cout << x << " ";
            cout << "\n";
        };
        auto cc = [&](int op) -> void{
            int x, y;
            if (op == 1) {
                cin >> x >> y;
                x--;
                if (x < 0 || x > a.size()) {cout << "error\n"; return;}
                else a.insert(a.begin() + x, y);
                pr();
            }
            else if (op == 2) {
                cin >> x;
                x--;
                if (x < 0 || x >= a.size()) {cout << "error\n"; return;}
                else a.erase(a.begin() + x);
                pr();
            }
            else {
                cin >> x;
                x--;
                if (x < 0 || x >= a.size()) {cout << "error\n"; return;}
                else cout << a[x] << "\n";
            }
        };
        pr();
        cc(1);cc(1);
        cc(2);cc(2);
        cc(3);cc(3);
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