#include <bits/stdc++.h>

using namespace std;

const vector<int> p3 = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 
    4782969, 14348907, 43046721, 129140163, 387420489};
const int mod = 998244353;

void addself(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int getbit(int x, int pos) {
    return (x / p3[pos]) % p3[1];
}
vector<int> getbits(int x, int m) {
    vector<int> bits(m);
    for (int i = 0; i < m; i++) {
        bits[i] = x % p3[1];
        x /= p3[1];
    }
    return bits;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < s.size(); i++) cin >> s[i];
    if (n < m) {
        vector<string> t(m);
        for (int i = 0; i < m; i++) {
            t[i].resize(n);
            for (int j = 0; j < n; j++) {
                t[i][j] = s[j][i];
            }
        }
        s = move(t);
        swap(n, m);
    }

    vector a(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '?') {
                a[i][j] = -1;
            } else {
                a[i][j] = s[i][j] - '1';
            }
        }
    }

    vector<int> f(p3[m]);
    vector<int> bits(m, -1);

    for (int i = 0; i < n; i++) {
        vector<int> nf(p3[m]);
        auto get = [&](this auto &&self, int j, int sum, int lst, int x) -> void {
            if (j == m) {
                addself(nf[sum], x);
                return;
            }

            for (int op = 0; op < 3; op++) {
                if (a[i][j] == -1 || a[i][j] == op) {
                    if (op != lst && op != bits[j])
                        self(j + 1, sum + op * p3[j], op, x);
                }
            }
        };

        if (i == 0) {
            get(0, 0, -1, 1);
        } else {
            for (int t = 0; t < p3[m]; t++) {
                if (f[t] == 0) continue;
                bits = getbits(t, m);
                get(0, 0, -1, f[t]);
            }
        }
        f = move(nf);
    }

    int ans = 0;
    for (auto i : f) addself(ans, i);
    cout << ans << "\n";
}