#include <bits/stdc++.h>
using namespace std;
using Score = pair<int, int>;  // {-过题数, 罚时}，越小越好
struct Problem {
    int cnt = 0, ac = -1, nxt = -1;
    vector<int> cand;
};
void sol() {
    int m, n = 0;
    cin >> m;
    map<pair<string, char>, Problem> problems;
    map<string, Score> score;
    set<string> ans;
    while (m--) {
        string name, status;
        char p;
        int t;
        cin >> name >> p >> t >> status;
        auto& q = problems[{name, p}];
        int val = t + 20 * q.cnt++;
        if (q.ac == -1) q.cand.push_back(val);
        if (status == "accepted" && q.ac == -1)
            q.ac = val;
        else if (status == "accepted" && q.nxt == -1)
            q.nxt = val;
    }
    for (auto& [key, q] : problems) {
        auto& s = score[key.first];
        if (q.ac != -1) --s.first, s.second += q.ac;
    }
    multiset<Score> ranking;
    for (auto& [name, s] : score) {
        ranking.insert(s);
        n += s.first < 0;
    }
    Score bound = n ? *next(ranking.begin(), min(35, (n + 9) / 10) - 1)
                    : Score{INT_MIN, 0};
    for (auto& [key, q] : problems) {
        Score old = score[key.first];
        for (int val : q.cand) {
            if (val == q.ac) val = q.nxt;
            Score cur = old;
            if (q.ac != -1) ++cur.first, cur.second -= q.ac;
            if (val != -1) --cur.first, cur.second += val;
            ranking.erase(ranking.find(old));
            ranking.insert(cur);
            int k = min(35, (n + (cur.first < 0) - (old.first < 0) + 9) / 10);
            if (k) {
                Score cut = *next(ranking.begin(), k - 1);
                bound = max(bound, cut);
                if (cur <= cut) ans.insert(key.first);
            }
            ranking.erase(ranking.find(cur));
            ranking.insert(old);
        }
    }
    for (auto& [name, s] : score)
        if (s <= bound) ans.insert(name);
    cout << ans.size() << '\n';
    for (auto& name : ans) cout << name << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) sol();
}