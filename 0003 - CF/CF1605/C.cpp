#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.find("aa") != string::npos) cout << 2 << "\n";
        else if (s.find("aba") != string::npos || s.find("aca") != string::npos) cout << 3 << "\n";
        else if (s.find("abca") != string::npos || s.find("acba") != string::npos) cout << 4 << "\n";
        else if (s.find("abbacca") != string::npos || s.find("accabba") != string::npos) cout << 7 << "\n";
        else cout << "-1\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
