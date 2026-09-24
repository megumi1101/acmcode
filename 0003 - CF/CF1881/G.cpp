#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    vector<int> a(n + 5), b(n + 5);
    set<int> seta, setb;
    for (int i = 2; i <= n; i++) {
        a[i] = s[i] - s[i - 1];
        a[i] = (a[i] + 26) % 26;
        if (!a[i]) seta.insert(i);
    }
    for (int i = 3; i <= n; i++) {
        b[i] = s[i] - s[i - 2];
        b[i] = (b[i] + 26) % 26;
        if (!b[i]) setb.insert(i);
    }
    
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 2) {
            if (l + 1 <= r) {
                auto it = seta.lower_bound(l + 1);
                if (it != seta.end() && *it <= r) {
                    cout << "NO\n";
                    continue;
                }
            }
            if (l + 2 <= r) {
                auto it = setb.lower_bound(l + 2);
                if (it != setb.end() && *it <= r) {
                    cout << "NO\n";
                    continue;
                }
            }
            cout << "YES\n";
        } else {
            cin >> x;
            if (a[l] == 0) seta.erase(l);
            a[l] = (a[l] + x) % 26;
            if (a[l] == 0) seta.insert(l);            
            if (r + 1 <= n) {
                if (a[r + 1] == 0) seta.erase(r + 1);
                a[r + 1] = ((a[r + 1] - x) % 26 + 26) % 26;
                if (a[r + 1] == 0) seta.insert(r + 1); 
            }
 
            if (b[l] == 0) setb.erase(l);
            b[l] = (b[l] + x) % 26;
            if (b[l] == 0) setb.insert(l);
            if (l + 1 <= r) {
                if (b[l + 1] == 0) setb.erase(l + 1);
                b[l + 1] = (b[l + 1] + x) % 26;
                if (b[l + 1] == 0) setb.insert(l + 1);
            }
 
            if (r + 2 <= n) {
                if (b[r + 2] == 0) setb.erase(r + 2);
                b[r + 2] = ((b[r + 2] - x) % 26 + 26) % 26;
                if (b[r + 2] == 0) setb.insert(r + 2); 
            }
 
            if (r + 1 <= n && l + 1 <= r) {
                if (b[r + 1] == 0) setb.erase(r + 1);
                b[r + 1] = ((b[r + 1] - x) % 26 + 26) % 26;
                if (b[r + 1] == 0) setb.insert(r + 1);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
