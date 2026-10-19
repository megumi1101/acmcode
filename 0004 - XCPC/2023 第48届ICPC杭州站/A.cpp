#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct submit {
    string c, p, s;
    int t, cnt;
};
struct node {
    int cnt, penalty;
    string c;
};
bool operator<(const node& a, const node& b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.penalty < b.penalty;
}
bool operator<=(const node& a, const node& b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.penalty <= b.penalty;
}
struct st {
    int pos, cnt;
    st(int pos_ = -1, int cnt_ = 0) : pos(pos_), cnt(cnt_) {}
};
typedef pair<st, st> pii;
void solution() {
    int n, m, cntt = 0;
    map<string, array<pii, 26> > mark;
    map<string, array<int, 26> > subcnt;
    map<string, node> team;
    map<string, int> rnk;
    vector<node> b;
    set<string> res;
    cin >> m;
    vector<submit> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].c >> a[i].p >> a[i].t >> a[i].s;
        if (!team.count(a[i].c))
            team[a[i].c].c = a[i].c, team[a[i].c].cnt = 0,
            team[a[i].c].penalty = 0;
        if (a[i].s == "accepted") {
            if (mark[a[i].c][a[i].p[0] - 'A'].first.pos == -1) {
                mark[a[i].c][a[i].p[0] - 'A'].first =
                    st(i, subcnt[a[i].c][a[i].p[0] - 'A']);
                ++team[a[i].c].cnt;
                team[a[i].c].penalty +=
                    subcnt[a[i].c][a[i].p[0] - 'A'] * 20 + a[i].t;
                ++cntt;
            } else if (mark[a[i].c][a[i].p[0] - 'A'].second.pos == -1)
                mark[a[i].c][a[i].p[0] - 'A'].second =
                    st(i, subcnt[a[i].c][a[i].p[0] - 'A']);
        }
        a[i].cnt = subcnt[a[i].c][a[i].p[0] - 'A']++;
    }
    for (map<string, node>::iterator it = team.begin(); it != team.end();
         ++it) {
        b.push_back(it->second);
    }
    sort(b.begin(), b.end());
    n = b.size();
    for (int i = 0; i < n; ++i) {
        cout << "i = " << i << " b[i].c = " << b[i].c
             << " b[i].cnt = " << b[i].cnt << " b[i].penalty = " << b[i].penalty
             << '\n';
    }
    for (int i = 0; i < n; ++i) rnk[b[i].c] = i;
    cout<<"cntt = "<<cntt<<'\n';
    int gold = min(35, cntt / 10 + (bool)(cntt % 10)) - 1, actgold, pgold;
    for (actgold = gold + 1; actgold < n; ++actgold) {
        if (b[gold] < b[actgold]) {
            --actgold;
            break;
        }
    }
    for (pgold = actgold + 1; pgold < n; ++pgold) {
        if (b[actgold+1] < b[pgold]) {
            --pgold;
            break;
        }
    }
    cout<<"gold = "<<gold<<" actgold = "<<actgold<<" pgold = "<<pgold<<'\n';
    bool flag = true,flag2=true;
    for (int i = 0; i < m; ++i) {
        cout<<"i = "<<i<<" a[i].c = "<<a[i].c<<" rnk[a[i].c] = "<<rnk[a[i].c]<<'\n';
        if (rnk[a[i].c] <= actgold && a[i].s == "rejected") res.insert(a[i].c);
        if (rnk[a[i].c] <= actgold && a[i].s == "accepted") {
            if (i == mark[a[i].c][a[i].p[0] - 'A'].first.pos) {
                node t = b[rnk[a[i].c]];
                st f = mark[a[i].c][a[i].p[0] - 'A'].first,
                   s = mark[a[i].c][a[i].p[0] - 'A'].second;
                if(s.pos==-1) t.penalty-=a[i].t,--t.cnt;
                else t.penalty -= a[i].t, t.penalty += a[s.pos].t + 20;
                if (!flag && b[pgold] < t) {
                    flag = true;
                    for (int i = actgold + 1; i <= pgold; ++i) {
                        res.insert(b[i].c);
                    }
                }
            }
        }
        if (rnk[a[i].c] > actgold && a[i].s == "rejected") {
            if(mark[a[i].c][a[i].p[0] - 'A'].first.pos==-1){
                node t = b[rnk[a[i].c]];
                ++t.cnt;
                t.penalty+=a[i].t;
                if (t <= b[actgold]) res.insert(a[i].c);
            }
            if (i < mark[a[i].c][a[i].p[0] - 'A'].first.pos) {
                node t = b[rnk[a[i].c]];
                st f = mark[a[i].c][a[i].p[0] - 'A'].first;
                t.penalty -= a[f.pos].cnt * 20 + a[f.pos].t,
                    t.penalty += a[i].cnt * 20 + a[i].t;
                if (t <= b[actgold]) res.insert(a[i].c);
            }
        }
    }
    cout << res.size() << '\n';
    for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
2
5
TSxingxing10 G 0 rejected
TSxingxing10 B 83 accepted
aoliaoligeiliao J 98 accepted
TS1 J 118 accepted
TS1 B 263 accepted
12
AllWayTheNorth A 0 rejected
YaoYaoLingXian Y 10 accepted
XuejunXinyoudui1 X 200 rejected
XuejunXinyoudui1 X 200 accepted
LetItRot L 215 accepted
AllWayTheNorth W 250 accepted
ImYourFan I 257 accepted
ImYourFan Y 257 accepted
AllWayTheNorth T 264 accepted
XuejunXinyoudui1 J 294 accepted
LetItRot I 299 accepted
LetItRot I 299 rejected

*/