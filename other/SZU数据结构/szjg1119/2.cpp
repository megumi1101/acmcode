#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int l = 1, r = n;
        int pos = -1;  

        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == x) {
                pos = mid;
                break;
            } else if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (pos == -1) {
            cout << "error\n";
        } else {
            cout << pos << '\n';
        }
    }

    return 0;
}
