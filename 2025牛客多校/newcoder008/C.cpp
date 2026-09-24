#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    struct node {
        int id, h;
        node(int id, int h) : id(id), h(h) {}
    };
    void sol() {
        int n, H;
        cin >> n >> H;
        vector<node> a;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a.emplace_back(i, x);
        }
        sort(a.begin(), a.end(), [&](node i, node j) {return i.h * (H - i.h) < j.h * (H - j.h);});
        for (auto[x,  _] : a) {
            cout << x << " ";
        }
        cout << "\n";
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