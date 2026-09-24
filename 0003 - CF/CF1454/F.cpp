#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
struct ST {
    vector<vector<int>> t;
    vector<int> lg;
    ST() {}
    ST(const vector<int> &data) {
        build(data);
    }
 
    void build (const vector<int> &data) {
        int n = data.size() - 1;
        int logn = log2(n) + 1;
        t.assign(n + 1, vector<int>(logn, inf));
        for (int i = 1; i <= n; i++) {
            t[i][0] = data[i];
        }
 
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                t[i][j] = min(t[i][j - 1], t[i + (1 << (j-1))][j - 1]);
            }
        }
 
        lg.resize(n + 2);
        lg[0] = lg[1] = 0;
        for (int i = 2; i <= n + 1; i++) {
            lg[i] = lg[i / 2] + 1;
        }
    }
 
    int query(int l, int r) {
        int k = lg[r - l + 1];
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }
};
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), premx(n + 5), sufmx(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            premx[i] = max(a[i], premx[i - 1]);
        }
        for (int i = n; i >= 1; i--) {
            sufmx[i] = max(a[i], sufmx[i + 1]);
        }
        
        ST st(a);
        // cerr << st.query(1, 1) << "\n";
        // cerr << st.query(1, 3) << "\n";
        // cerr << st.query(2, 5) << "\n";
        // cerr << st.query(3, 6) << "\n";
 
        for (int i = 1; i + 2 <= n; i++) {
            // cerr << i << "\n";
            int now = premx[i];
            
            
            int ly = -1;
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
 
                // cerr << "mid == " << mid << "\n";
                if (st.query(i + 1, mid) <= now) ly = mid, r = mid - 1;
                else l = mid + 1;
            }
            // cerr << "ly == " << ly << "\n";
            if (ly == -1 || st.query(i + 1, ly) != now) continue;
            
 
            int ry = n;
            l = ly + 1, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (st.query(i + 1, mid) < now) ry = mid, r = mid - 1;
                else l = mid + 1;
            }
            ry--;            
            // cerr << "ry == " << ry << "\n";
            
            
            int rz = -1;
            l = ly + 1, r = ry + 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                // cerr << "mid == " << mid << "\n";
                if (sufmx[mid] >= now) rz = mid, l = mid + 1;
                else r = mid - 1;
            }
            // cerr << "rz == " << rz << "\n";
            if (rz == -1 || sufmx[rz] != now) continue;
            
            
            cout << "YES\n";
            cout << i << " " << rz - i - 1 << " " << n - rz + 1 << "\n";
            return;
        }
        cout << "NO\n";
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
    return Xbbbz::main(), 0;
}
