#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++) cin >> a[i], b.push_back(a[i]);
    sort(b.begin(), b.end());
 
    int mid = b[n / 2];
 
 
    vector<int> sum0(n + 1), sum1(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)  {
        sum[i] = sum[i - 1] + (a[i] == mid);
        sum0[i] = sum0[i - 1] + (a[i] <= mid);
        sum1[i] = sum1[i - 1] + (a[i] > mid);
    }
    
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int len = i - j;
            int x = (sum0[i] - sum0[j]) - (sum[i] - sum[j]); 
            
            if (!(len & 1)) continue;
            if (j != 0 && f[j] == 0) continue;
            if ((sum0[i] - sum0[j] >= sum1[i] - sum1[j]) && (x < (len + 1) / 2) && (sum[i] - sum[j]) && (len & 1)) 
                f[i] = max(f[i], 1 + f[j]);
        }
    }
 
    cout << f[n] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
1 
5
1 1 2 2 2
*/
