#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 11;              
    vector<vector<int>> hashTable(MOD); 

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int h = x % MOD;
        hashTable[h].push_back(x);
    }

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        int h = x % MOD;
        auto &bucket = hashTable[h];

        int cmp = 0;      
        bool found = false;

        for (int val : bucket) {
            ++cmp;
            if (val == x) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << h << ' ' << cmp << "\n";
        } else {
            cout << "error\n";
            bucket.push_back(x);
        }
    }

    return 0;
}
