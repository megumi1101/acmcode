#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 1), L(n + 1), R(n + 1);
    vector<int> stk;
    stk.reserve(n);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && p[stk.back()] > p[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        
        if (!stk.empty()) {
            R[stk.back()] = i; 
        }
        L[i] = lst;   
        stk.push_back(i);
    }

    int ansL = 0, ansR = 0;
    for (int i = 1; i <= n; i++) {
        ansL ^= 1LL * i * (L[i] + 1);
        ansR ^= 1LL * i * (R[i] + 1);
    }

    cout << ansL << " " << ansR << endl;
}