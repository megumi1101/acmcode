#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    vector<int> p(k + 1);
    for (int i = 1; i <= k; i++) cin >> p[i];
    int t1 = 0, t2 = 0;
    for (int j = p[1] - 1; j >= 1; j--) {
        if (a[j] != a[j + 1]) t1++;
    }
    for (int j = p[1] + 1; j <= n; j++) {
        if (a[j] != a[j - 1]) t2++;
    }
 
    if (t1 == 0 && t2 == 0) {
        cout << "0\n";
        return;
    } else if (t1 == 0) {
        if (t2 % 2 == 0) t2--;
    } else if (t2 == 0) {
        if (t1 % 2 == 0) t1--;
    } else {
        if (t2 % 2 == 0) t2--;
        if (t1 % 2 == 0) t1--;
    }
    cout << t1 + t2 - min(t1, t2) + 1 << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
