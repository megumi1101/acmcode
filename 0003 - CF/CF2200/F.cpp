#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    int has = 0;
    multiset<pair<int, int>>s1, s0; 
    multiset<pair<int, int>, greater<>> S; 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second++;
        S.insert(a[i]);
    }
    sort(a.begin(), a.end(), [&](pair<int, int> i, pair<int,int> j){return i.second < j.second;});
 
    int pos = 0;
    int sum = 0;
    vector<int> sum1(n + 5), sum0(n + 5);
    for (int i = 1; i <= n + 1; i++) {
        if (S.empty()) continue;
        auto it = S.begin();
        while (s1.size() < i && it != S.end()) {
            s1.insert(*it);
            sum += it->first;
            auto deit = it;
            it = next(it);
            S.extract(deit);
        }
        
        sum1[i] = sum;
 
        while (pos < n && a[pos].second == i) {            
            S.extract(a[pos]);
            if (s1.find(a[pos]) != s1.end()) {
                s1.extract(a[pos]);
                sum -= a[pos].first;
            }
            pos++;
        }
        
    }
    
    S.clear();
    pos = 0;
    sum = 0;
    for (auto &i : a) S.insert(i); 
    for (int i = 1; i <= n + 1; i++) {
        if (S.empty()) continue;
        auto it = S.begin();
        while (s0.size() < i - 1 && it != S.end()) {
            s0.insert(*it);
            sum += it->first;
            auto deit = it;
            it = next(it);
            S.extract(deit);
        }
 
        sum0[i] = sum;
 
        while (pos < n && a[pos].second == i) {            
            S.extract(a[pos]);
            if (s0.find(a[pos]) != s0.end()) {
                s0.extract(a[pos]);
                sum -= a[pos].first;
            }
            pos++;
        }
    }
 
    for (int i = 1; i <= n + 1; i++) {
        sum1[i] = max(sum1[i - 1], sum1[i]);
        sum0[i] = max(sum0[i - 1], sum0[i]);
    }
 
    int now = sum1[n + 1];
    while (m--) {
        int x, y;
        cin >> x >> y;
        y++;
        cout << max(now, sum0[y] + x) << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
