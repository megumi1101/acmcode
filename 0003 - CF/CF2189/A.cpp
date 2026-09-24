#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int cnt1 = 0, cnt2 = 0;
    if (h > l) swap(h, l);
    for (auto &i : a) {
        if (i <= h) cnt1++;
        if (i <= l) cnt2++;
    }
    cout << min(cnt1, cnt2 / 2) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
