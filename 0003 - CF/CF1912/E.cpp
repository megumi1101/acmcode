#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int stoi(string s) {
    int res = 0;
    for (auto c : s) {
        res = res * 10 + c - '0';
    }
    return res;
}
string itos(int x) {
    if (x == 0) return "0";
    string s;
    while (x) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, q;
    cin >> p >> q;
    int t1, t2;
    int tmp = abs(p + q);
    string ans;
    if (tmp & 1) {
        t1 = (p + q - 33) / 2;
        t2 = (p - q + 9) / 2;
        ans = "1*12";
    } else {
        t1 = (p + q) / 2;
        t2 = (p - q) / 2;
        ans = "0";
    }
 
    vector<int> hui;
    for (int res = 1; res < 1e18; res = res * 10 + 1) {
        for (int i = 1; i <= 9; i++) {
            hui.push_back(res * i);
        }
    }
    reverse(hui.begin(), hui.end());
    auto get = [&] (int x) -> vector<int> {
        x = abs(x);
        vector<int> a;
        for (auto i : hui) {
            if (x >= i) a.push_back(i), x -= i;;
            
        }
        return a;
    };
 
    auto pe = get(t1);
    if (t1 < 0) {
        for (auto i :pe) {
            ans += "+0-";
            ans += itos(i);
            ans += "-0";
        }
        
    } else if (t1 > 0) {
        for (auto i :pe) {
            ans += "+";
            ans += itos(i);
        }
    }
    
    pe = get(t2);
    if (t2 < 0) {
        for (auto i :pe) {
            ans += "+0-";
            ans += itos(i);
        }
        
    } else if (t2 > 0) {
        for (auto i :pe) {
            ans += "+";
            ans += itos(i);
            ans += "-0";
        }
    }
    cout << ans << "\n";
}
