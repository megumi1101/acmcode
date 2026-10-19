#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    for (string s : {"gen", "naive", "a"}) {
        string cmd = "g++ -std=gnu++17 -O2 " + s + ".cpp -o " + s;
        if (system(cmd.c_str()) != 0) {
            cout << "Compile Error: " << s << '\n';
            return 1;
        }
    }
    for (int t = 1; ; t++) {
        if (system("./gen > 1.in") != 0 ||
            system("./naive < 1.in > std.out") != 0 ||
            system("./a < 1.in > 1.out") != 0) {
            cout << "Run Error test=" << t << '\n';
            return 1;
        }
        if (system("diff -u std.out 1.out") != 0) {
            cout << "WA test=" << t << ", input=1.in\n";
            break;
        }
        cout << "AC " << t << endl;
    }
}
