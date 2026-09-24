#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    int n = rng() % 3 + 1;
    cout << "1";
    for (int i = 1; i < n; i++) {
        cout << rng() % 2;
    }
    cout << "\n";
    return 0;
}