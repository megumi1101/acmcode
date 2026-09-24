#include <bits/stdc++.h>

using namespace std;

const int mod = 998244391;
const int B = 31415927;
struct Hash {
    vector<int> h, pw;

    void build(const string &s) {
        int n = s.size();
        h.resize(n + 1);
        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 0; i < n; i++) {
            pw[i + 1] = 1LL * pw[i] * B % mod;
            h[i + 1] = (1LL * h[i] * B + s[i]) % mod;
        }
    }

    // 0-based [l, r]
    int calc(int l, int r) {
        return (h[r + 1] - 1LL * h[l] * pw[r - l + 1] % mod + mod) % mod;
    }
};


void sol() {
    int n, k, L;
    cin >> n >> L >> k;
    string s;
    cin >> s;

    Hash hs;
    hs.build(s);

    if (1LL * L * k > n) {
        cout << "NO\n";
        return;
    }

    int ansl = 0, ansr = n - 1 - (k - 1) * L;

    auto upd = [&](int nl, int nr) -> void {
        int len1 = ansr - ansl + 1;
        int len2 = nr - nl + 1;
        int len = min(len1, len2);
        int l = 0, r = len - 1, ans = len;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (hs.calc(ansl, ansl + mid) != hs.calc(nl, nl + mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ans == len) {
            if (len2 > len1) {
                ansl = nl;
                ansr = nr;
            }
        } else {
            if (s[ansl + ans] < s[nl + ans]) {
                ansl = nl;
                ansr = nr;
            }
        }
    };

    for (int i = L; i < n; i++) {
        int ds = k - 1 - max(1, min(k - 1, (i / L)));
        if (ds < 0) continue;
        int r = n - 1 - ds * L;
        if (i + L - 1 <= r) {
            upd(i, r);
        }
    }

    cout << "YES\n";
    for (int i = ansl; i <= ansr; i++) {
        cout << s[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}