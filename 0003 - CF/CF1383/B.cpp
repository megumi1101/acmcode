#include <bits/stdc++.h>
using namespace std;
 
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s ^= a[i];
    }
    if (s == 0) { 
        cout << "DRAW" << '\n';
        return;
    }
    for (int b = 30;; b--) {
        if (s >> b & 1) { 
            int ones = 0;
            for (int v: a) if (v >> b & 1) ones++;
            int zeros = n - ones;
            cout << (ones % 4 == 3 && zeros % 2 == 0 ? "LOSE" : "WIN") << '\n';
            return;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)run();
}
