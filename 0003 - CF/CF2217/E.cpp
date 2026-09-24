#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> p(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
 
    vector<int> S;
    for (int i = n; i >= 1; i--) {
        vector<int> v;
        for (auto x : S) {
            if (p[x] > p[i]) {
                v.push_back(x);
            }
        }
        if (v.size() < d[i]) {
            cout << "-1\n";
            return;
        }
        if (d[i] == 0) {
            S.push_back(i);
        } else {
            int t = v[v.size() - d[i]];
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == t) {
                    S.insert(S.begin() + j, i);
                    break;
                }
            }
        }
    }
 
    vector<int> q(n + 1);
    for (int i = 0; i < S.size(); i++) q[S[i]] = i + 1;
    for (int i = 1; i <= n; i++) cout << q[i] << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
