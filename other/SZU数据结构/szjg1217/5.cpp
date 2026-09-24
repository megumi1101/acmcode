#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), cur(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cur = a;
    bool isInsertion = false;
    int pos = 0;

    for (int i = 1; i < n; i++) {
        int x = cur[i], j = i - 1;
        while (j >= 0 && cur[j] > x) {
            cur[j + 1] = cur[j];
            j--;
        }
        cur[j + 1] = x;
        if (cur == b) {
            isInsertion = true;
            pos = i + 1;
            break;
        }
    }

    if (isInsertion) {
        cout << "Insertion Sort\n";
        int x = cur[pos], j = pos - 1;
        while (j >= 0 && cur[j] > x) {
            cur[j + 1] = cur[j];
            j--;
        }
        cur[j + 1] = x;
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << cur[i];
        }
        cout << "\n";
    } else {
        cout << "Merge Sort\n";
        cur = a;
        int len = 1;
        while (true) {
            for (int i = 0; i < n; i += 2 * len) {
                int l = i;
                int m = min(i + len, n);
                int r = min(i + 2 * len, n);
                sort(cur.begin() + l, cur.begin() + r);
            }
            if (cur == b) {
                len <<= 1;
                for (int i = 0; i < n; i += 2 * len) {
                    int l = i;
                    int r = min(i + 2 * len, n);
                    sort(cur.begin() + l, cur.begin() + r);
                }
                break;
            }
            len <<= 1;
        }
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << cur[i];
        }
        cout << "\n";
    }

    return 0;
}
