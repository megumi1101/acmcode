#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v{2, 3, 5};

    v.insert(v.end(), 1);
    for (auto x : v) cout << x << " ";
    cout << "\n";
}

/*
1
5
bca a zz ab c
*/