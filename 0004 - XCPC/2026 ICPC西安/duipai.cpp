#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t = 1; t <= 10000; t++) {
        system("./gen > 1.in");
        system("./Hb < 1.in > Hb.out");
        system("./HH < 1.in > HH.out");

        if (system("diff -u HH.out Hb.out")) {
            cout << "WA\n";
            break;
        }
        cout << "AC\n";
    }
}

/*
2
3 5 2
1 3
10 5
20 2
3 100 1
1 5
2 5
3 5


1
3 5 2
1 3
10 5
20 2


1
3 100 1
1 5
2 5
3 5


*/