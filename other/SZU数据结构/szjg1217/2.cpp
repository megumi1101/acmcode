#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(const vector<string>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n), tmp(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int len = 1;
        while (len < n) {
            for (int l = 0; l < n; l += 2 * len) {
                int m = min(l + len, n);
                int r = min(l + 2 * len, n);
                int i = l, j = m, k = l;
                while (i < m && j < r) {
                    if (a[i] > a[j]) tmp[k++] = a[i++];
                    else tmp[k++] = a[j++];
                }
                while (i < m) tmp[k++] = a[i++];
                while (j < r) tmp[k++] = a[j++];
            }
            a = tmp;
            print(a);
            len <<= 1;
        }

        if (t) cout << "\n";
    }
    return 0;
}
