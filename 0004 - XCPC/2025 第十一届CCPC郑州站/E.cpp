#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 26;
 
void solve() {
    int n; cin >> n;
 
    int m = n * 2;
    vector<string> a(m);
    for (auto& s : a) cin >> s;
    for (auto& s : a) for (auto& c : s) c -= 'a';
 
    struct node {
        int cnt;
        array<int, 26> p; 
    };
    vector<node> tr(2);
    
    auto ch = [&](int x) -> array<int, 26>& { return tr[x].p; };
    auto insert = [&](const string& s) -> void {
        int p = 1;
        for (auto& c : s) {
            if (!tr[p].p[c]) {
                tr[p].p[c] = tr.size();
                tr.push_back({});
            }
            // cerr << "bf p = " << p << endl;
            p = tr[p].p[c];
            // cerr << "af p = " << p << endl;
            tr[p].cnt += 1;
        }
    };
 
    for(auto& s : a) insert(s);
 
    i64 ans = 0;
    // 返回匹配了多少个
    auto dfs = [&](auto&& dfs, int u) -> void {
        // cerr << "u = " <<  u << endl;
        for (auto& v : tr[u].p) {
            if (!v) continue;
            // cerr << "dep = " << tr[u].dep << " to " << v << endl;
            dfs(dfs, v);
        }
 
        if (tr[u].cnt < 2) return;
        i64 cnt = tr[u].cnt;
        i64 base = cnt >> 1, high = (cnt + 1) >> 1;
        ans += base * high;
    };
    dfs(dfs, 1);
 
    cout << ans << "\n";
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    solve();
    return 0;
}
