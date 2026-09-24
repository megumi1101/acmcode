#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    const int N = 1e6;
    vector<int> pr, vis(N + 1), tr(N + 1);
    int cnt = 0;
    void init() {
        for (int i = 2; i <= N; i++) {
            if (!vis[i]) {pr.push_back(i); tr[i] = 1;}
            for (auto j : pr) {
                if (i * j > N) break;
                vis[i * j] = 1;
                tr[i * j] = tr[i] ^ 1;
                if (i % j == 0) break;
            }
        }
    }
    void sol() {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 2, j = n / 2; i <= n, j >= 1; i++) {
            if (tr[i]) {
                cout << i << " ";
                j--;
            }
        }
        cout << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        init();
        while (T--) {
            sol();
        }
    }
}

int main() {
    return Xbbbz::main(), 0;
}