#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& a) {
    int n = a.size() - 1;
    cout << n;
    for (int i = 1; i <= n; i++) cout << " " << a[i];
    cout << "\n";
}

void siftDown(vector<int>& a, int i, int n) {
    int x = a[i];
    for (int j = i * 2; j <= n; j *= 2) {
        if (j + 1 <= n && a[j + 1] < a[j]) j++;
        if (a[j] < x) {
            a[i] = a[j];
            i = j;
        } else break;
    }
    a[i] = x;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = n / 2; i >= 1; i--) siftDown(a, i, n);
    print(a);

    for (int i = n; i >= 2; i--) {
        swap(a[1], a[i]);
        siftDown(a, 1, i - 1);
        print(a);
    }
    return 0;
}
