#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> stk;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (stk.empty()) stk.push_back(a[i]);
        else {
            if (stk.back() == a[i]) stk.pop_back();
            else stk.push_back(a[i]);
        }
    }
    if (stk.size() <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}