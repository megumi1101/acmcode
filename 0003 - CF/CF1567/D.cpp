#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 3e5 + 10;
 
    void sol() {
        string s;
        int k, n = 0;
        cin >> s >> k;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            n = n * 10 + s[i] - '0';
            res += s[i] - '0';
        }
        if (k <= res) {
            int mi = 1;
            for (int i = 1; i <= s.size(); i++) {
                for (; n % 10 != 0; n--) {
                    if (k == 1) {
                        cout << n * mi << "\n";
                        return;
                    }
                    k--;
                    cout << mi << " ";
                }
                n /= 10;
                mi *= 10;
            }
        }
        else {
            priority_queue<int, vector<int>, greater<int> > a;
            k -= res;
            int mi = 1;
            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= n % 10; j++) {
                   a.push(mi);
                }
                n /= 10;
                mi *= 10;
            }
            while(!a.empty()) {
                int u = a.top();
                a.pop();
                if(u == 1) cout << u << " ";
                else {
                    if(k >= 9) {
                        k -= 9;
                        for(int i = 1; i <= 10; i++) a.push(u / 10);
                    }
                    else {
                        for(int i = 1; i <= k; i++) a.push(u / 10);
                        a.push(u - (k * u / 10));
                        break;
                    }
                }
            }
            while(!a.empty()) cout << a.top() << " ", a.pop();
            cout << "\n";
        }
    }
 
    void main() {   
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
