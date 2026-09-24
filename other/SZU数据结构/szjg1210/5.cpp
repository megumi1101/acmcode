#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            int pos = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[pos]) pos = j;
            }
            if (pos != i) {
                swap(a[i], a[pos]);
            }
            for (int j = 0; j < n; j++) {
                cout << a[j];
                if (j < n - 1) cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
