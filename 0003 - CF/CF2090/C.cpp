#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
struct pt {
    int x, y;
    pt (int x, int y) : x(x), y(y){}
    int dis() const {
        if (x % 3 == 2 && y % 3 == 2) {
            return x + y + 2;
        } else {
            return x + y;
        }
    }
    friend bool operator < (const pt &a, const pt &b) {
        if (a.dis() != b.dis()) return a.dis() > b.dis();
        else if (a.x != b.x) return a.x > b.x;
        else return a.y > b.y;
    }
};
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
 
        int cnt = 0;
        priority_queue<pt> q0, q1;
 
        int t = 0;
        for (int i = 2; ; i += 3) {
            t = i + 5;
            for (int x = 1; x <= i; x += 3) {
                int y = i - x;
                q0.emplace(x, y);
                q1.emplace(x, y);
                q1.emplace(x + 1, y);
                q1.emplace(x, y + 1);
                q1.emplace(x + 1, y + 1);
                cnt++;
            }
            if (cnt > 2 * n) break;
        }
 
 
        vector vis(t, vector(t, 0));
        for (auto &i : a) {
            if (i == 0) {
                while (!q0.empty()) {
                    auto[x, y] = q0.top();
                    q0.pop();
                    if (vis[x][y]) continue;
                    vis[x][y] = 1;
                    cout << x << " " << y << "\n";
                    break;
                }
            } else {
                while (!q1.empty()) {
                    auto[x, y] = q1.top();
                    q1.pop();
                    if (vis[x][y]) continue;
                    vis[x][y] = 1;
                    cout << x << " " << y << "\n";
                    break;
                }
            }
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
