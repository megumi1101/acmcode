#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> HT(N);
    for (int i = 0; i < N; ++i) cin >> HT[i];
    vector<int> vals;
    for (int x : HT)
        if (x >= 0)
            vals.push_back(x);
    vector<int> used(N, 0); 
    vector<int> ans;
    for (int step = 0; step < (int)vals.size(); ++step) {
        int best = INT_MAX, best_pos = -1;
        for (int i = 0; i < N; ++i) {
            if (HT[i] < 0) continue;
            int val = HT[i];
            if (used[i]) continue; 
            int h = val % N;
            bool ok = true;
            int pos = h;
            while (pos != i) {
                if (!used[pos] && HT[pos] >= 0)
                    { ok = false; break; }
                pos = (pos + 1) % N;
            }
            if (ok && val < best) {
                best = val;
                best_pos = i;
            }
        }
        ans.push_back(best);
        used[best_pos] = 1;
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
