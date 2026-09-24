#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, w;
    cin >> n >> w;
    if (w == 1) {
        cout << "0\n";
        return;
    } cout << n - n / w << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
