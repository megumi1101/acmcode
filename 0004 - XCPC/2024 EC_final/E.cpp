#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int M, T = 30000;

/* time, tries */
using node = std::pair<std::optional<int>, int>;

std::vector<node> try_parse(std::string s, bool one_try) {
    int n = s.size();
    std::vector<node> ret;
    for (int i = 0; i < n; ++i) {
        std::string t = s.substr(0, i);
        std::string c = s.substr(i);
        if (t.starts_with('0') && t != "0") {
            continue;
        }
        if (c.starts_with('0')) {
            continue;
        }
        if (one_try && c != "1") {
            continue;
        }
        if (!one_try && c == "1") {
            continue;
        }

        node x;
        x.first = t.empty() ? std::nullopt : std::optional(std::atoi(t.c_str()));
        assert(!c.empty());
        x.second = std::atoi(c.c_str());
        if (x.first && *x.first >= 300) continue;
        if (x.second > 100) continue;
        ret.push_back(x);
    }
    return ret;
}

void solve() {
    std::string s;
    std::cin >> s;

    int len = s.size();
    std::vector<std::string> tries;
    std::vector<std::string> a;
    {
        std::string num, ch;
        for (int i = 0; i < len; ++i) {
            if (std::isdigit(s[i])) {
                num += s[i];
                if (!ch.empty()) {
                    tries.push_back(ch);
                    ch.clear();
                }
            } else {
                ch += s[i];
                if (!num.empty()) {
                    a.push_back(num);
                    num.clear();
                }
            }
        }
        if (!num.empty()) a.push_back(num);
        if (!ch.empty()) tries.push_back(ch);
    }
    int n = a.size();
    if (tries.empty()) return std::cout << "0 0\n", void();
    // for (int i = 0; i < n;++i){
    //     cerr<<a[i]<< ' ';
    // }
    // std::cerr <<'\n';
    // for (int i = 0; i < n;++i){
    //     cerr<<tries[i]<< ' ';
    // }
    // std::cerr <<'\n';
    
    std::vector<std::vector<node>> b(n);
    for (int i = 1; i < n; ++i) {
        b[i] = try_parse(a[i], tries[i] == "try");
    }

    for (int i = 1; i <= (n >= 10 ? 2 : 1); ++i) {
        std::string AC = a[0].substr(0, i);
        if (AC.starts_with('0') && AC != "0") continue;
        int ac = std::atoi(AC.c_str());
        std::cerr << i << ' ' << ac << '\n';
        
        for (int j = 1; i + j < (int) a[0].size(); ++j) {
            std::string P = a[0].substr(i, j);
            if (P.starts_with('0') && P != "0") continue;
            int p = std::atoi(P.c_str());
            if (p > T) break;
            std::cerr << j << ' ' << p << '\n';
            
            std::string bak = a[0];
            a[0] = a[0].substr(i + j);
            b[0] = try_parse(a[0], tries[0] == "try");

            for (int cur = 0; cur < n; ++cur) {
                std::cerr << "cur = " << cur << '\n';
                for (const auto& nd : b[cur]) {
                    const auto& [x, y] = nd;
                    int get_ac = x ? 1 : 0;
                    int get_p = x ? *x + 20 * (y - 1) : 0;
                    std::cerr << y << ' ' << get_ac << ' ' << get_p << '\n';
                }
            }

            int ok = 0;
            std::vector<node> stk;
            stk.reserve(n);
            [&](this auto&& dfs, int cur, int ac_, int p_) {
                if (cur == n) {
                    if (ac_ == ac && p_ == p) {
                        ok = 1;
                        std::cout << ac << ' ' << p;
                        for (int k = 0; k < stk.size(); ++k) {
                            const auto& [x, y] = stk[k];
                            std::cout << ' ';
                            if (x) {
                                std::cout << *x << ' ';
                            }
                            std::cout << y << ' ' << (y == 1 ? "try" : "tries");
                        }
                        std::cout << '\n';
                    }
                    return;
                }

                for (const auto& nd : b[cur]) {
                    const auto& [x, y] = nd;
                    int get_ac = x ? 1 : 0;
                    int get_p = x ? *x + 20 * (y - 1) : 0;
                    if (get_ac + ac_ > ac || get_p + p_ > p) {
                        continue;
                    }
                    stk.push_back(nd);
                    dfs(cur + 1, ac_ + get_ac, p_ + get_p);
                    stk.pop_back();
                    if (ok) return;
                }
            }(0, 0, 0);

            if (ok) return;
            a[0] = bak;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    std::cin >> t >> M;
    while (t--) {
        solve();
        // std::cerr << '\n';
    }
    return 0;
}
/*
1 2
2212111tries111try

9 935
158 3 tries 
26 1 try
31 2 tries 
23 1 try
4 tries
43 1 try
241 2 tries
55 1 try
99 1 try
179 1 try
*/