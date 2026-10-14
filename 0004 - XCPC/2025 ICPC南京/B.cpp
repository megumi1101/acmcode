#include <bits/stdc++.h>

using namespace std;

using f128 = float128_t;
const f128 PI = acos((f128)-1.0);
const f128 eps = 1e-19;
void sol() {
    int n;
    cin >> n;
    vector<f128> ag;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0) continue;
        ag.push_back(atan2((f128)b, (f128)a));
    }

    sort(ag.begin(), ag.end());
    n = ag.size();
    ag.resize(2 * n);
    for (int i = 0; i < n; i++) {
        ag[i + n] = ag[i] + PI * 2;
    }

    int r = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        r = max(i, r);
        while (ag[r + 1] + eps <= ag[i] + PI) r++;
        ans = max(ans, r - i + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
2
4
1 1 1
-1 3 4
0 -2 7
-5 0 10
1
0 0 1
*/