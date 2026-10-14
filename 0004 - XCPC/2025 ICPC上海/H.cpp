#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> t(30);
    vector<int> a(2 * n + 1);

    int res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        res ^= a[i];
        // for (int bit = 0; bit < 30; bit++) {
        //     if ((a[i] >> bit) & 1) t[bit]++;
        // }
    }

    cout << "\n";
    cout << res << "\n";
    // for (int i = 0; i < 30; i++) {
    //     if (t[i] % 4 == 2) {
    //         cout << "Bot\n";
    //         return;
    //     }
    //     if (t[i] == 0) t[i] = -1;
    //     t[i] %= 4;
    // }

    // // cout << t[1] << " " << t[3] << "\n";
    // int ct9 = 0, ct10 = 0;

    // for (int i = 1; i <= 2 * n; i++) {
    //     int fg = 0;
    //     for (int bit = 0; bit < 30; bit++) {
    //         if ((a[i] >> bit) & 1) {
    //             if (t[bit] == 1) {
    //                 fg ^= 1;
    //             } else if (t[bit] == 3) {
    //                 fg ^= 2;
    //             }
    //             if (t[bit] == 0) {
    //                 fg ^= 4;
    //             }
    //         }
    //     }
    //     if (fg == 3) {
    //         cout << "Bot\n";
    //         return;
    //     }
    //     if (fg == 9) {
    //         ct9++;
    //     } 
    //     if (fg == 10) {
    //         ct10++;
    //     }
    // }

    // if (ct9 >= 2 || ct10 >= 2) {
    //     cout << "Bot\n";
    //     return;
    // }

    // cout << "Menji\n";
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
5
2
1 1 3 3
2
1 1 1 3
3
1 1 4 5 1 4
3
1 9 1 9 8 10
6
1 1 4 5 1 4 1 9 1 9 8 10
*/