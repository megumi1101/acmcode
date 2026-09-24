// QOJ user: xbbbz
// Contest: 2025 ç¬?0å±ŠICPCæ­¦æ±‰ç«?// Problem: #14729. Organize the Bookshelf (14729)
// Submission: https://qoj.ac/submission/1640458
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9 + 10000;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> vis(n + 1);
        vector<set<int>> sup(n + 1), sdn(n + 1);
        for (auto &i : a) cin >> i, vis[i]++;
        for (auto &i : b) cin >> i, vis[i]++;
        for (int i = 1; i <= n; i++) {
            if (vis[i] & 1) {
                cout << "-1\n";
                return;
            }
        }
        
        for (int i = 0; i < n; i++) {
            sup[a[i]].insert(i);
            sdn[b[i]].insert(i);
        }

        for (int i = 0; i <= n; i++) {
            sup[i].insert(n);
            sdn[i].insert(n);
        }
        vector<pair<int, int>> ans;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            int y = b[i];
            if (x != y) {
                int xu = *next(sup[x].begin());
                int yu = *sup[y].begin();
                int xd = *sdn[x].begin();
                int yd = *next(sdn[y].begin());

                if (xu <= yu && xu <= xd && xu <= yd) {
                    cost += xu - i;
                    ans.emplace_back(xu, i);
                    swap(a[xu], b[i]);
                    sdn[y].erase(sdn[y].find(i));
                    sup[x].erase(sup[x].find(xu));
                    sup[x].erase(sup[x].find(i));
                    sup[y].insert(xu);
                    
                } 
                else if (yu <= xd && yu <= yd) {
                    ans.emplace_back(yu, yu);
                    xd = yu;
                    sup[a[xd]].erase(sup[a[xd]].find(xd));
                    sdn[b[xd]].erase(sdn[b[xd]].find(xd));
                    sdn[a[xd]].insert(xd);
                    sup[b[xd]].insert(xd);
                    swap(a[xd], b[xd]);
                    yd = yu;
                    cost += yd - i;
                    ans.emplace_back(i, yd);
                    swap(a[i], b[yd]);
                    sup[x].erase(sup[x].find(i));
                    
                    sdn[y].erase(sdn[y].find(yd));
                    sdn[y].erase(sdn[y].find(i));
                    sdn[x].insert(yd);
                } else if (xd <= yd) {
                    ans.emplace_back(xd, xd);
                    sup[a[xd]].erase(sup[a[xd]].find(xd));
                    sdn[b[xd]].erase(sdn[b[xd]].find(xd));
                    sdn[a[xd]].insert(xd);
                    sup[b[xd]].insert(xd);
                    swap(a[xd], b[xd]);

                    xu = xd;
                    cost += xu - i;
                    ans.emplace_back(xu, i);
                    swap(a[xu], b[i]);
                    sdn[y].erase(sdn[y].find(i));
                    
                    sup[x].erase(sup[x].find(xu));
                    sup[x].erase(sup[x].find(i));
                    sup[y].insert(xu);
                } else {
                    cost += yd - i;
                    ans.emplace_back(i, yd);
                    swap(a[i], b[yd]);
                    sup[x].erase(sup[x].find(i));
                    sdn[y].erase(sdn[y].find(yd));
                    sdn[y].erase(sdn[y].find(i));
                    sdn[x].insert(yd);
                } 
            } else {
                sup[x].erase(sup[x].find(i));
                sdn[y].erase(sdn[y].find(i));
            }
        }

        cout << cost << " " << ans.size() << "\n";
        for (auto [x, y] : ans) {
            cout << x + 1 << " " << y + 1<< "\n";
        }
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
</code>