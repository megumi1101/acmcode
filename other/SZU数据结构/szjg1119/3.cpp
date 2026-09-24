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
    int k;
    cin >> k;
    vector<int> idx(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> idx[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int cmp = 0;      
        int block = 0;    

        for (int i = 1; i <= k; ++i) {
            ++cmp;                
            if (x <= idx[i]) {
                block = i;
                break;
            }
        }

        if (block == 0) {
            cout << "error\n";
            continue;
        }
        int base = n / k;  
        int start, end;
        if (block < k) {
            start = (block - 1) * base + 1;
            end   = block * base;
        } else {
            start = (k - 1) * base + 1;
            end   = n;
        }
        int pos = 0;
        for (int i = start; i <= end; ++i) {
            ++cmp;                
            if (a[i] == x) {
                pos = i;
                break;
            }
        }
        if (pos == 0) {
            cout << "error\n";
        } else {
            cout << pos << "-" << cmp << "\n";
        }
    }

    return 0;
}
