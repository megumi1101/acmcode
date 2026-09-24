#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int ansA = 0;
    for (int i = 0; i + 1 < a.size(); i++) {
        ansA += (a[i] - a[i + 1] + 1);
    }
    ansA += a.back();


    int ansB = 0;
    for (int i = 0; i + 1 < b.size(); i++) {
        ansB += (b[i] - b[i + 1] + 1);
    }
    ansB += b.back();

    if (ansA >= ansB) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}