#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[10000];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int gap = n / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int key = a[i];
                int j = i - gap;
                while (j >= 0 && a[j] < key) { 
                    a[j + gap] = a[j];
                    j -= gap;
                }
                a[j + gap] = key;
            }
            for (int i = 0; i < n; i++) {
                cout << a[i];
                if (i < n - 1) cout << " ";
            }
            cout << "\n";
        }

        cout << "\n";
    }
    return 0;
}
