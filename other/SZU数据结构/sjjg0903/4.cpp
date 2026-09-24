#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        deque<int> q;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.emplace_back(x);
        }
        
        auto out = [&]() -> void {
            vector<int> a;
            while (!q.empty()) {
                int u = q.front();
                q.pop_front();
                cout << u << " ";
                a.emplace_back(u);
            }
            cout << "\n";
            for (auto x : a) q.emplace_back(x);
        };
        
        auto cc = [&]() -> void {
            int op, x;
            cin >> op >> x;
            if (op == 0) {
                while (x--) {
                    int u = q.front();
                    q.pop_front();
                    q.emplace_back(u);
                }
            }
            else {
                while (x--) {
                    int u = q.back();
                    q.pop_back();
                    q.emplace_front(u);
                }
            }
            out();
        }; 
        
        out();
        cc(); cc();

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