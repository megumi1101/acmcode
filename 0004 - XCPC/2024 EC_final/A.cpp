#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y, id;
    friend bool operator < (const node &a, const node &b) {
        if (a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    }
};

void sol() {
    int n;
    cin >> n;
    vector<node> p(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    } 
    sort(p.begin(), p.end());

    set<pair<int, int>> t;
    map<pair<int, int>, vector<int>> mp;
    vector<vector<int>> ans;
    for (int i = 0; i < 3 * n; i++) {
        auto [x, y, id] = p[i];
        auto it = t.lower_bound({x, -1});
        if (it == t.end()) {
            t.insert({y, i});
            mp[{y, i}].push_back(id);
        } else {
            mp[*it].push_back(id);
            auto v = mp[*it];
            if (v.size() == 3) {
                ans.push_back(v);
                t.erase(*it);
                mp.erase(*it);
            }
        }
    }

    if (ans.size() == n) {
        cout << "Yes\n";
        for (auto v : ans) {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
    
    
}

/*
2
2
1 2
2 2
2 3
3 5
4 4
4 5
1
1 1
1 1000000000
1000000000 1000000000
*/