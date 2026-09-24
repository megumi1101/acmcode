#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> id(t), parent(t);

    for (int i = 0; i < t; ++i) cin >> id[i];
    for (int i = 0; i < t; ++i) cin >> parent[i];

    vector<vector<int>> g(t);
    for (int i = 0; i < t; ++i) {
        if (parent[i] != -1) {
            g[parent[i]].push_back(i);
        }
    }

    for (int i = 0; i < t; ++i) {
        cout << id[i] << '-';
        for (int v : g[i]) cout << v << '-';
        cout << "^\n";
    }

    return 0;
}
