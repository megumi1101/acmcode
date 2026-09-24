#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 5e6 + 10;
int lpf[MAX_A]; 

void precompute_lpf() {
    memset(lpf, 0, sizeof(lpf));
    for (int i = 2; i < MAX_A; ++i) {
        if (lpf[i] == 0) { 
            lpf[i] = i;
            for (int j = 2 * i; j < MAX_A; j += i) {
                if (lpf[j] == 0) {
                    lpf[j] = i;
                }
            }
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    if (x == 1) return res;
    while (x != 1) {
        int p = lpf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        res.emplace_back(p, cnt);
    }
    return res;
}

int main() {
    precompute_lpf();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (n & 1) {
            puts("YES");
            continue;
        }
        if (n == 2) {
            if (a[0] == a[1]) puts("YES");
            else puts("NO");
            continue;
        }
        unordered_map<int, int> total_exp; 
        for (int x : a) {
            auto factors = factorize(x);
            for (auto &[p, e] : factors) {
                total_exp[p] += e;
            }
        }
        bool ok = true;
        for (auto &[p, sum_e] : total_exp) {
            if (sum_e % 2 != 0) { 
                ok = false;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}