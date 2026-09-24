#include <bits/stdc++.h>
using namespace std;

int n;
string s; 
int dfs(int idx) {
    if (idx > n) return 0;
    char ch = s[idx - 1];
    if (ch == '0') return 0;
    int lh = dfs(idx * 2);
    int rh = dfs(idx * 2 + 1);
    cout << ch << " " << (lh - rh) << "\n";
    return max(lh, rh) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        dfs(1);
    }
    return 0;
}
