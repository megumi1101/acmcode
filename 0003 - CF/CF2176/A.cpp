#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] > a[i]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
