#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
int getxor(int x){
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}
int getans(int x,int pos, int k){
    if (x == 0) return 0;
    int t = x>>pos;
    if(x % (1<<pos) >= k) t++;
    return getxor(x) ^ (getxor(t - 1) << pos) ^ ((t & 1) * k);
}
    void sol() {
        int l, r, i, k;
        cin >> l >> r >> i >> k;
        cout << (getans(r, i, k) ^ getans(l - 1, i, k)) << "\n";
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
