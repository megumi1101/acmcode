#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    char ch;
    int cnt;
    node(char ch_ = '\0', int cnt_ = 0) : ch(ch_), cnt(cnt_) {}
};
bool operator<(const node& a, const node& b) { return a.cnt > b.cnt; }
vector<int> C, W, P;
void solution() {
    int n;
    string s;
    cin >> n >> s, s = '#' + s, C.resize(n + 1), W.resize(n + 1),
                   P.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        C[i] = C[i - 1] + (s[i] == 'C');
        W[i] = W[i - 1] + (s[i] == 'W');
        P[i] = P[i - 1] + (s[i] == 'P');
    }
    bool mark = true;
    int lp = -1, rp = -1;
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i + 1]) {
            mark = false;
            if (lp == -1) lp = i;
            rp = i;
        }
    if (mark) {
        cout << "Beautiful\n";
        return;
    }
    if (max(max(C[n], W[n]), P[n]) * 2 > n + 1) {
        cout << "Impossible\n";
        return;
    }
    auto check = [&](int len, int l) -> bool {
        int r = l + len - 1;
        if (l>lp+1||r < rp) return false;
        vector<node> p;
        node a, b, c;
        p.push_back(node('C', C[r] - C[l - 1]));
        p.push_back(node('W', W[r] - W[l - 1]));
        p.push_back(node('P', P[r] - P[l - 1]));
        sort(p.begin(), p.end());
        a = p[0], b = p[1], c = p[2];
        // cout<<"l = "<<l<<" r = "<<r<<" a.cnt = "<<a.cnt<<" b.cnt =
        // "<<b.cnt<<" c.cnt = "<<c.cnt<<'\n';
        if (a.cnt <= b.cnt + c.cnt + 1) {
            if (a.cnt == b.cnt + c.cnt + 1) {
                if (l == 1 && s[r + 1] != a.ch || r == n && s[l - 1] != a.ch ||
                    s[l - 1] != a.ch && s[r + 1] != a.ch)
                    return true;
            } else {
                if (a.cnt == b.cnt + c.cnt) {
                    if (l == 1 || r == n ||
                        (s[l - 1] != a.ch || s[r + 1] != a.ch) && c.cnt > 0 ||
                        ((s[l - 1] != a.ch || s[r + 1] != a.ch)) &&
                            (s[l - 1] != b.ch || s[r + 1] != b.ch))
                        return true;
                } else
                    return true;
            }
        }
        return false;
    };
    auto query = [&](int len) -> bool {
        for (int i = 1; i <= n - len + 1; ++i) {
            if (check(len, i)) return true;
        }
        return false;
    };
    int res;
    for (int l = max(2, rp - lp), r = n, mid; l <= r;) {
        mid = (l + r) >> 1;
        // cout << "l = " << l << " r = " << r << " mid = " << mid << '\n';
        if (query(mid))
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    string ans;
    for (int i = 1; i <= n - res + 1; ++i) {
        if (check(res, i)) {
            int l = i, r = l + res - 1;
            vector<node> p;
            node a, b, c;
            p.push_back(node('C', C[r] - C[l - 1]));
            p.push_back(node('W', W[r] - W[l - 1]));
            p.push_back(node('P', P[r] - P[l - 1]));
            sort(p.begin(), p.end());
            a = p[0], b = p[1], c = p[2];
            // cout << "a.cnt = " << a.cnt << " b.cnt = " << b.cnt
            //      << " c.cnt = " << c.cnt << '\n';
            // cout << "a.ch = " << a.ch << " b.ch = " << b.ch
            //      << " c.ch = " << c.ch << '\n';
            if (a.cnt == b.cnt + c.cnt + 1) {
                for (int i = 0; i < b.cnt; ++i) ans += a.ch, ans += b.ch;
                for (int i = 0; i < c.cnt; ++i) ans += a.ch, ans += c.ch;
                ans += a.ch;
            }
            if (a.cnt == b.cnt + c.cnt) {
                if (c.cnt == 0) {
                    for (int i = 0; i < a.cnt; ++i) ans += a.ch, ans += b.ch;
                    if (l>1&&s[l - 1] == a.ch||r<n&&s[r+1]==b.ch) reverse(ans.begin(), ans.end());
                } else {
                    for (int i = 0; i < b.cnt; ++i) ans += a.ch, ans += b.ch;
                    for (int i = 0; i < c.cnt; ++i) ans += a.ch, ans += c.ch;
                    if (l>1&&s[l - 1] == a.ch)
                        reverse(ans.begin(), ans.end());
                    else if (r<n&&s[r + 1] == c.ch)
                        swap(ans[1], ans[ans.length() - 1]);
                }
            }
            if (a.cnt < b.cnt + c.cnt) {
                int lb = (b.cnt + c.cnt - a.cnt) / 2 +
                         ((b.cnt + c.cnt - a.cnt) & 1),
                    lc = (b.cnt + c.cnt - a.cnt) / 2;
                for (int i = lb; i < b.cnt; ++i) ans += a.ch, ans += b.ch;
                for (int i = lc; i < c.cnt; ++i) ans += a.ch, ans += c.ch;
                for (; lb > 0 && lc > 0; --lb, --lc) ans += b.ch, ans += c.ch;
                if (lb) ans += b.ch;
                // cout << "ans = " << ans << '\n';
                if (1 < l && r < n) {
                    if (s[l - 1] == a.ch && s[r + 1] == a.ch)
                        ans = ans.back() + ans.substr(0, ans.length() - 1);
                    else if (s[l - 1] == a.ch)
                        reverse(ans.begin(), ans.end());
                    else if (s[r + 1] == ans.back()) {
                        ans.clear();
                        lb = (b.cnt + c.cnt - a.cnt) / 2,
                        lc = (b.cnt + c.cnt - a.cnt) / 2 +
                             ((b.cnt + c.cnt - a.cnt) & 1);
                        for (int i = lc; i < c.cnt; ++i)
                            ans += a.ch, ans += c.ch;
                        for (int i = lb; i < b.cnt; ++i)
                            ans += a.ch, ans += b.ch;
                        for (; lb > 0 && lc > 0; --lb, --lc) ans += c.ch, ans += b.ch;
                        if (lc) ans += c.ch;
                    }
                }
                if (l == 1 && s[r + 1] == ans.back() ||
                    r == n && s[l - 1] == ans[0])
                    reverse(ans.begin(), ans.end());
            }
            // cout << "ans = " << ans << '\n';
            cout << "Possible\n"
                 << l << ' ' << r << '\n'
                 << s.substr(1, l - 1) << ans << s.substr(r + 1) << '\n';
            return;
        }
    }
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
