// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÊù≠Â∑ûÁ´?// Problem: #9726. AUS (9726)
// Submission: https://qoj.ac/submission/1482618
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
    void sol() {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (s1.size() != s2.size()) {
            cout << "NO\n";
            return;
        }
        if (s3.size() != s1.size()) {
            cout << "YES\n";
            return;
        }
        DSU dsu(30);
        for (int i = 0; i < s1.size(); i++) {
            dsu.merge(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < s1.size(); i++) {
            s1[i] = dsu.find(s1[i] - 'a');
            s2[i] = dsu.find(s2[i] - 'a');
            s3[i] = dsu.find(s3[i] - 'a');
        }

        if (s1 == s3) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
/*
4
abab
cdcd
abce
abab
cdcd
abcd
abab
cdcd
abc
x
yz
def
*/
</code>