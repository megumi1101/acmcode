#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
typedef __int128_t i128;
int cmp(long long sum1, long long cnt1, long long sum2, long long cnt2) {
    i128 res1 = (i128)sum1 * cnt2, res2 = (i128)sum2 * cnt1;
    if (res1 > res2) return 1;
    if (res1 < res2) return -1;
    return 0;
}
int a[300001];
void solution() {
    int n, minn = 1e9 + 7, mark = -1;
    long long res = 0ll, cnt = n, res1 = 0ll, cnt1 = 0ll;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < minn) minn = a[i], mark = i;
    }
    // cout<<"minn = "<<minn<<" mark = "<<mark<<'\n';
    for (int i = 1; i <= mark; ++i) res1 += a[i], ++cnt1;
    for (int i = mark + 1; i <= n; ++i) {
        res1 += a[i], ++cnt1;
        if (cmp(res, cnt, res1, cnt1) == -1) res = res1, cnt = cnt1;
    }
    res1 = cnt1 = 0ll;
    for (int i = mark; i <= n; ++i) res1 += a[i], ++cnt1;
    for (int i = mark - 1; i; --i) {
        res1 += a[i], ++cnt1;
        if (cmp(res, cnt, res1, cnt1) == -1) res = res1, cnt = cnt1;
    }
    cout << (double)res / cnt << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    cin >> T;
    while (T--) solution();
}
/*
2
4
8 2 7 10
6
9 6 5 3 4 8
*/