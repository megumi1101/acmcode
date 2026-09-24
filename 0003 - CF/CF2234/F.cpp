#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    int pos = 1;
    for (int i = 2; i <= n; i++) {
        if (h[i] > h[pos]) pos = i;
    }

    auto old = [&](int i) {
        return (pos + i - 1) % n + 1;
    };

    vector<int> a(n);
    for (int i = 1; i <= n - 1; i++) {
        a[i] = h[old(i)];
    }

    vector<int> cur(n + 1, 0), ans(n + 1, 0);

    {
        vector<pair<int, int>> st;
        int sum = 0;

        for (int i = 1; i <= n - 1; i++) {
            int cnt = 1;
            while (!st.empty() && st.back().first < a[i]) {
                auto [val, num] = st.back();
                st.pop_back();
                sum -= val * num;
                cnt += num;
            }
            st.push_back({a[i], cnt});
            sum += a[i] * cnt;
            cur[i + 1] += sum;
        }
    }

    {
        vector<pair<int, int>> st;
        int sum = 0;

        for (int i = n - 1; i >= 1; i--) {
            int cnt = 1;
            while (!st.empty() && st.back().first < a[i]) {
                auto [val, num] = st.back();
                st.pop_back();
                sum -= val * num;
                cnt += num;
            }
            st.push_back({a[i], cnt});
            sum += a[i] * cnt;
            cur[i] += sum;
        }
    }

    for (int i = 1; i <= n; i++) {
        ans[old(i)] = cur[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
