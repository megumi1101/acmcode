#include <bits/stdc++.h>

using namespace std;

vector<int> pr, minp;
void init(int n) {
    pr.clear();
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) pr.push_back(i), minp[i] = i;
        for (int p : pr) {
            if (p > n / i) break;
            int m = i * p; minp[m] = p;
            if (i % p == 0) { break; }
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    vector<int> vis(n + 1);
    vector<pair<int, int>> ans;
    

    for (int i = 3; i <= n; i++) {
        if (vis[i]) continue;
        if (i * 2 > n) continue;
        vector<int> p;
        for (int j = i; j <= n; j += i) {
            if (!vis[j]) p.push_back(j);
        }
        int siz = p.size();
        if (siz == 1) continue;
        if (siz & 1) {
            p.erase(p.begin() + 1);
        }
        
        for (auto x : p) vis[x] = 1;
        for (int j = 0; j < p.size(); j += 2) {
            ans.push_back({p[j], p[j + 1]});
        }
    }

    {
        vector<int> p;
        for (int j = 2; j <= n; j += 2) {
            if (!vis[j]) p.push_back(j);
        }
        int siz = p.size();
        if (siz != 1) {
            if (siz & 1) {
                p.erase(p.begin() + 1);
            }
            
            for (int j = 0; j < p.size(); j += 2) {
                ans.push_back({p[j], p[j + 1]});
            }
        } 
    }
    
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << " \n";
    }
}