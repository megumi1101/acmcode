#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    vector<pair<int, char>> p(3); 
    for (int i = 0; i < 3; i++) cin >> p[i].first;
    p[0].second = 'R';
    p[1].second = 'G';
    p[2].second = 'B';
    sort(p.begin(), p.end());
    if (p[2].first > p[0].first + p[1].first) {
        string s;
        for (int i = 0; i < p[0].first; i++) {
            s.push_back(p[2].second);
            s.push_back(p[0].second);
        }
        for (int i = 0; i < p[1].first; i++) {
            s.push_back(p[2].second);
            s.push_back(p[1].second);
        }
        s.push_back(p[2].second);
        cout << s << "\n";
        return;
    } else {
        int n = p[0].first + p[1].first + p[2].first;
        string s;
        s.assign(n, '0');
        int up = (n + 1) / 2;
        up -= p[1].first;
        p[0].first -= up;
        for (int i = 0; i < up; i++) {
            s[2 * i] = p[0].second;
        }
        for (int i = 0; i < p[1].first; i++) {
            s[(up + i) * 2] = p[1].second;
        }
        for (int i = 0; i < p[2].first; i++) {
            s[i * 2 + 1] = p[2].second;
        }
        for (int i = 0; i < p[0].first; i++) {
            s[(i + p[2].first) * 2 + 1] = p[0].second;
        }
        cout << s << "\n";
    }
    
 
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
 
/*
aaaaa
bbbb
ccc
 
cacababababc
*/
