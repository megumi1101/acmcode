#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> up(n + 1, n), dn(n + 1, 1);
    
    auto ask = [&](int i) -> int {
        cout << "? " << i << endl;
        string s;
        cin >> s;
        if (s == ">") return 1;
        else if (s == "<") return -1;
        else return 0;
    };
    
    int rst = 0;
    for (int i = 1; i <= n; i++) {
        while (1) {
            int op = ask(i);
            if (op == -1) {
                if (rst) ask(rst);
            } else {
                rst = i;
            }
            if (op != 1) {
                break;
            }
        }
    }
    up[rst] = dn[rst] = n;
 
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        while (1) {
            int op = ask(i);
            if (op == 1) {
                if (lst) ask(lst);
            } else {
                lst = i;
            }
            if (op != -1) {
                break;
            }
        }
    }
    up[lst] = dn[lst] = 1;
    int x = 1;
    auto de = [&]() -> void {
        // cerr << "x == " << x << endl;
    };
    auto get = [&](int mid) {
        // cerr << "mid == " << mid << endl;
        de();
        while (x < mid) ask(rst), x++, de();
        while (x > mid) ask(lst), x--, de();
        for (int i = 1; i <= n; i++) {
            if (dn[i] < up[i] && dn[i] <= mid && mid <= up[i]) {
                int op = ask(i);
                x += op;
                if (op == 1) {
                    dn[i] = x;
                } else if (op == -1) {
                    up[i] = x;
                } else {
                    dn[i] = up[i] = x;
                }
            }
            while (x < mid) ask(rst), x++;
            while (x > mid) ask(lst), x--;
        }
    };
 
    auto tt = [&] (auto &&tt, int l, int r) ->void {
        int mid = (l + r) >> 1;
        get(mid);
        if (l == r) {
            return;
        }
        tt(tt, l, mid);
        tt(tt, mid + 1, r);
    };
    tt(tt, 1, n);
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << dn[i] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) sol();
}
/*
1
5
<
>
>
+
<
>
>
+
<
>
<
<
<
+
>
<
<
+
>
<
>
<*/
