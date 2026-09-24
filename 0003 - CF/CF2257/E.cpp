#include <bits/stdc++.h>

using namespace std;

#define int long long

template <typename T, auto op = [](T a, T b) { return max(a, b); }>
struct ST {
    int n;
    vector<vector<T>> t;

    ST() {}
    ST(const vector<T>& a) { build(a); }

    void build(const vector<T>& a) {
        n = a.size() - 1;
        int K = __lg(n) + 1;
        t.assign(n + 1, vector<T>(K));

        for (int i = 1; i <= n; i++)
            t[i][0] = a[i];

        for (int j = 1; j < K; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                t[i][j] = op(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return op(t[l][k], t[r - (1 << k) + 1][k]);
    }

    int getp(int l, int t) {
        int pos = -1;
        int r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (query(l, mid) >= t) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }
};

void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> hei(n + 1);
    vector<vector<int>> a(n + 1), b(n + 1), pre(n + 1), need(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> hei[i];
        a[i].resize(hei[i] + 1);
        b[i].resize(hei[i] + 1);
        pre[i].resize(hei[i] + 1);
        need[i].resize(hei[i] + 1);

        for (int j = 1; j <= hei[i]; j++) {
            cin >> a[i][j];
        }
        for (int j = 1; j <= hei[i]; j++) {
            cin >> b[i][j];
        }
        for (int j = 1; j <= hei[i]; j++) {
            pre[i][j] = pre[i][j - 1] - a[i][j] + b[i][j];
            need[i][j] = a[i][j] - pre[i][j - 1];
        }
    }

    vector<int> earn(n + 1), epos(n + 1);
    vector<ST<int>> stp(n + 1), stn(n + 1);

    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        stp[i].build(pre[i]);
        stn[i].build(need[i]);
        int pos = stp[i].getp(epos[i] + 1, earn[i]);
        if (pos != -1) {
            pq.push({stn[i].query(epos[i] + 1, pos) + earn[i],
                pre[i][pos] - earn[i], i, pos});
        }
    }

    while (!pq.empty()) {
        auto [tneed, tearn, i, tpos] = pq.top();
        pq.pop();
        if (x < tneed) {
            continue;
        }

        x += tearn;
        earn[i] += tearn;
        epos[i] = tpos;

        int pos = stp[i].getp(epos[i] + 1, earn[i]);
        if (pos != -1) {
            pq.push({stn[i].query(epos[i] + 1, pos) + earn[i],
                pre[i][pos] - earn[i], i, pos});
        }
    }

    vector<int> mx(n + 1);
    int mxid = 1;
    for (int i = 1; i <= n; i++) {
        mx[i] = epos[i];
        int tx = x;
        for (int j = epos[i] + 1; j <= hei[i]; j++) {
            if (tx >= a[i][j]) {
                tx -= a[i][j];
                tx += b[i][j];
                mx[i] = j;
            } else {
                break;
            }
        }
        if (mx[i] > mx[mxid]) {
            mxid = i;
        }
    }

    cout << mx[mxid] << " " << mxid << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
1
2 0
1
2
1
1
0
0
*/
