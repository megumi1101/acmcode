#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n, k;
        cin >> n >> k;
        int hf = (n + k + 1) / 2;
 
        vector<int> a(n), b, c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
 
        sort(b.begin(), b.end());
        int minp = 0;
        for (int i = 0; i + hf - 1 < n; i++) {
            int j = i + hf - 1;
            c[i] = b[j] - b[i];
            if (c[i] < c[minp]) {
                minp = i;
            }
        }
        
        int low = b[minp];
        int hig = b[minp + hf - 1];
        
        int cnt = 0;
        int bf = 0;
        vector<pair<int, int> > ans;
        for (int i = 0; i < n; i++) {
            if (ans.size() == k - 1) {
                ans.emplace_back(bf + 1, n);
                break;
            }
            if (a[i] >= low && a[i] <= hig) {
                cnt++;
            }
            else cnt--;
            if (cnt == 1) {
                ans.emplace_back(bf + 1, i + 1);
                bf = i + 1;
                cnt = 0;
            }
            
        }
 
        cout << low << " " << hig<< " \n";
        for (auto[l, r] : ans) {
            cout << l << " " << r << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
