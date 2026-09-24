#include <iostream>
using namespace std;

void printArray(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void quick(int *a, int L, int R, int totalN) {
    if (L >= R) return;
    int pivot = a[L];
    int low = L, high = R;
    while (low < high) {
        while (low < high && a[high] <= pivot) --high;
        if (low < high) {
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low] > pivot) ++low;
        if (low < high) {
            a[high] = a[low];
            --high;
        }
    }
    a[low] = pivot; 
    printArray(a, totalN);
    quick(a, L, low - 1, totalN);
    quick(a, low + 1, R, totalN);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        quick(a, 0, n - 1, n);
        cout << "\n"; 
    }
    return 0;
}