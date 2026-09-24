#include <bits/stdc++.h>
using namespace std;
 
bool solve() {
    int x; cin >> x;
    string s = to_string(x);
 
    int sum = 0;
    for(auto& c : s) sum += c - '0';
 
    auto issq = [&](int x) -> bool {
        int sq = sqrtl(x);
        while ((sq + 1) * (sq + 1) < x)
            ++sq;
        return sq * sq == x;
    };
 
    return issq(x) && issq(sum);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    cout << (solve() ? "Yes\n" : "No\n");
    return 0;
}
