#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> L(n), R(n);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back() < a[i]) {
            st.pop_back();
        }
        st.push_back(a[i]);
        L[i] = st.size();
    }
    
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.back() < a[i]) {
            st.pop_back();
        }
        st.push_back(a[i]);
        R[i] = st.size();
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, L[i] + R[i] - 1);
    }
    cout << n - ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
