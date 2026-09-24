#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct Cus {
    int st, tim, vp, vis;
};
struct Window {
    int ed, num; 
};

int main() {
    int n;
    cin >> n;
    vector<Cus> cus(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        cus[i] = {x, min(60, y), z, 0};
    }

    int K, vipid;
    cin >> K >> vipid;

    vector<Window> wins(K);
    for (int i = 0; i < K; i++) {
        wins[i].ed = 0;
        wins[i].num = 0;
    }

    int sumwait = 0;
    int mxwait = 0;
    int lasttime = 0;
    int cnt = 0;

    int now = 0;
    while (cnt < n) {
        vector<int> nowwins;
        for (int i = 0; i < K; i++) {
            if (wins[i].ed <= now) {
                nowwins.push_back(i);
            }
        }

        if (nowwins.empty()) {
            now++;
            continue;
        }

        int fstvip = -1;
        for (int i = 0; i < n; i++) {
            if (!cus[i].vis && cus[i].st <= now && cus[i].vp == 1) {
                fstvip = i;
                break;
            }
        }

        if (find(nowwins.begin(), nowwins.end(), vipid) != nowwins.end() && fstvip != -1) {
            Cus &cusnow = cus[fstvip];
            int wait = now - cusnow.st;
            sumwait += wait;
            if (wait > mxwait) {
                mxwait = wait;
            }
            wins[vipid].ed = now + cusnow.tim;
            wins[vipid].num++;
            cusnow.vis = 1;
            cnt++;
            if (wins[vipid].ed > lasttime) {
                lasttime = wins[vipid].ed;
            }
            continue;
        }

        int fstcus = -1;
        for (int i = 0; i < n; i++) {
            if (!cus[i].vis && cus[i].st <= now) {
                fstcus = i;
                break;
            }
        }

        if (fstcus == -1) {
            now++;
            continue;
        }

        Cus &cusnow = cus[fstcus];
        int wind = *min_element(nowwins.begin(), nowwins.end());
        int wait = now - cusnow.st;
        sumwait += wait;
        if (wait > mxwait) {
            mxwait = wait;
        }
        wins[wind].ed = now + cusnow.tim;
        wins[wind].num++;
        cusnow.vis = 1;
        cnt++;
        if (wins[wind].ed > lasttime) {
            lasttime = wins[wind].ed;
        }
    }

    cout << fixed << setprecision(1) << double(sumwait) / (double)n << " " << mxwait << " " << lasttime << "\n";

    for (int i = 0; i < K; i++) {
        if (i > 0) cout << " ";
        cout << wins[i].num;
    }
    return 0;
}