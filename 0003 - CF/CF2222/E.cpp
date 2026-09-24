#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    
 
    int mask = (1ll << n) - 1;
    cout << mask << endl;
    auto ask = [&](string s, int x) -> int {
        cout << s << " " << x << endl;
        int t;
        cin >> t;
        return t;
    };
 
    auto put = [&](int k, int c) -> void {
        cout << "A" << " " << k << " " << c << endl;
    };
    
    int t = ask("I", mask);
    if (t == 1) {
        if (ask("I", 0) == 1) {
            put(2, mask);
            return;
        }
        int now = 0;
        for (int bit = n - 1; bit >= 0; bit--) {
            if (ask("Q", now + (1ll << bit)) > 1) {
                now += 1ll << bit;
            }
        }
 
        if (now) {
            put(2, now);
        } else {
            put(1, mask);
        }
        return;
    }
 
    int now = 0;
    for (int bit = n - 1; bit >= 0; bit--) {
        if (ask("Q", now + (1ll << bit)) > 1) {
            now += 1ll << bit;
        }
    }
 
    if (now == 0) {
        put(3, mask);
        return;
    }
    ask("I", 0);
    if (ask("Q", 1) == 2) {
        put(1, now);
    } else {
        put(3, mask ^ now);
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
1 
5
1 1 2 2 2
*/
