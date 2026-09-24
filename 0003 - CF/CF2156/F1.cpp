#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> p(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int t = 1; t <= n; t++) {
		int mn = n + 1;
		for (int i = 1; i <= n; i++) {
            if ((p[i] & 1) && p[i] < mn) {
                ans[i] = t;
                for (int j = 1; j <= n; j++) {
                    if (p[j] > p[i] && p[j] <= n) p[j]--;
                }
                p[i] = n + 1;
                break;
            }
            mn = min(p[i], mn);
        }
	}
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
