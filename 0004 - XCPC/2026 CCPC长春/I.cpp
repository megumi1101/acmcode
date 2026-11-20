#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const string t[] = {"", "001", "010", "011", "100", "101", "110"};
string g[7][7];
map<string, int> mark[7];
void link(int u, int v, string w) {
    g[u][v] = w;
    if (w != "10") mark[u][w] = v;
}
void init() {
    link(1, 1, "00"), link(1, 2, "01"), link(1, 3, "10");
    link(1, 4, "10"), link(1, 5, "11");

    link(2, 2, "00"), link(2, 3, "10"), link(2, 4, "10");
    link(2, 5, "01"), link(2, 6, "11");

    link(3, 1, "00"), link(3, 2, "01"), link(4, 5, "10"), link(4, 6, "11");

    link(5, 1, "00"), link(5, 2, "01"), link(5, 3, "10");
    link(5, 4, "10"), link(5, 5, "11");

    link(6, 2, "00"), link(6, 3, "10"), link(6, 4, "10");
    link(6, 5, "01"), link(6, 6, "11");
}
void solution1() {
    int n, cur = 2;
    string s, res = "";
    cin >> n >> s;
    if (n & 1) {
        if (s[0] == '0') res += '0';
        if (s[0] == '1') res += '1', cur = 1;
    }
    for (int i = (n & 1); i < n; i += 2) {
        string nxt;
        nxt += s[i], nxt += s[i + 1];
        if (nxt != "10") {
            res += t[mark[cur][nxt]], cur = mark[cur][nxt];
        } else {
            if (cur == 4)
                res += t[5], cur = 5;
            else {
                string temp;
                if (i < n - 2) temp += s[i + 2], temp += s[i + 3];
                if (i == n - 2 || temp == "00" || temp == "01")
                    res += t[3], cur = 3;
                else
                    res += t[4], cur = 4;
            }
        }
    }
    cout << res.length() << endl << res << endl;
}
void solution2() {
    int m, cur = 2;
    string s, res = "";
    cin >> m >> s;
    if (m % 3) {
        res += s[0];
        if (s[0] == '1') cur = 1;
    }
    for (int i = m % 3; i < m; i += 3) {
        string nxt;
        nxt += s[i], nxt += s[i + 1], nxt += s[i + 2];
        int p = -1;
        for (int j = 1; j <= 6; ++j)
            if (t[j] == nxt) {
                p = j;
                break;
            }
        // cout<<"i = "<<i<<" nxt = "<<nxt<<" cur = "<<cur<<" p = "<<p<<"
        // g[cur][p] = "<<g[cur][p]<<endl;
        res += g[cur][p];
        cur = p;
    }
    cout << res.length() << endl << res << endl;
}
int main() {
    int T, r;
    // freopen("I.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T >> r;
    init();
    if (r == 1)
        while (T--) solution1();
    if (r == 2)
        while (T--) solution2();
    return 0;
}
/*
3 1
1
0
3
111
6
001100

3 2
1
0
4
1101
9
010110010

3 1
4
0010
7
0101010
1
0

3 2
6
010011
10
0100101011
1
0
*/