#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const vector<int> c = {2, 3, 4, 5, 6, 7, 0};
struct node {
    bool mark;
    string res;
    node(bool mark_ = false, string res_ = "") : mark(mark_), res(res_) {}
};
vector<vector<node> > d;
void init() {
    d.resize(16);
    for (int i = 0; i <= 15; ++i) d[i].resize(121);
    d[0][0] = node(true);
    for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= 120; ++j) {
            for (int k = 0; k < c.size(); ++k)
                if (j >= c[k] + 1 && d[i - 1][j - c[k] - 1].mark) {
                    d[i][j].mark = true;
                    string temp = d[i - 1][j - c[k] - 1].res;
                    if (k != 6)
                        temp += '1', temp += (char)(c[k] + '0');
                    else
                        temp += "1//";
                    if (d[i][j].res.empty() ||
                        d[i][j].res.length() > temp.length())
                        d[i][j].res = temp;
                }
        }
}
string query(int a, int b, int n, int p) {
    for (int i = 0; i <= 15 - (n - 6); ++i) {
        int j = 15 - (n - 6) - i;
        if (a<=120&&d[i][a].mark &&b<=120&& d[j][b].mark)
            if (!p)
                return d[i][a].res + "/" + d[j][b].res + "/";
            else
                return d[i][a].res + "/" + d[j][b].res;
    }
    return "NA";
}
void solution() {
    int a, b, n, p;
    cin >> a >> b >> n >> p;
    if (n < 6) {
        int t = 6 - n;
        for (int mask = 0; mask < (1 << t); ++mask) {
            // cout<<"mask = "<<mask<<'\n';
            vector<bool> f;
            f.resize(t);
            if (t == 6 && ((bool)(mask & (1 << 5)) == p))
                continue;  // 最后一个球只能由当前的先手方打
            int ta = a, tb = b;
            for (int i = 0; i < t; ++i) {
                if (mask & (1 << i))  // 这一位为1表示它属于A
                    ta -= c[i], f[i] = false;
                else
                    tb -= c[i], f[i] = true;
            }
            if (ta > 120 || ta < 0 || tb > 120 || tb < 0) continue;
            // cout<<"mark\n";
            // cout<<"ta = "<<ta<<" tb = "<<tb<<'\n';
            string res = query(ta, tb, 6, 0);
            // cout<<"ta = "<<ta<<" tb = "<<tb<<'\n'<<"res = "<<res<<'\n';
            if (res == "NA")
                continue;
            else {
                bool cur = false;
                for (int i = 0; i < t; ++i) {
                    if (f[i] == cur)
                        res += (char)(c[i] + '0');
                    else
                        res += '/', res += (char)(c[i] + '0');
                    cur = f[i];
                }
                if (f[t - 1] != p) res += '/';
                cout << res << '\n';
                return;
            }
        }
        cout << "NA\n";
    } else {
        cout << query(a, b, n, p) << '\n';
    }
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
7
8 110 1 1
147 0 0 0
0 0 21 0
1 0 20 0
1 1 19 1
0 0 0 0
147 0 0 1

1
147 0 0 0
*/