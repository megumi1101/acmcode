#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
void solution() {
    int n;
    long long res = 0ll, x;
    vector<long long> a;
    map<long long, int> mark;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> x, a.push_back(x), cin >> x, a.push_back(x);
    sort(a.begin(), a.end());
    mark[a[0]] = mark[a[(n << 1) - 1]] = 0;
    for(int i = 1; i + 1 < (n << 1); i += 2) {
        ++mark[a[i]];
        if(a[i] ^ a[i + 1]) ++mark[a[i + 1]];
    }
    for(int i = 0; i < (n << 1); i += 2) res += max(0ll, a[i + 1] - a[i] - 1);
    // cout << "res = " << res << '\n';
    for(map<long long, int>::iterator it = mark.begin(); it != mark.end(); ++it) if(!(it->second & 1)) ++res;
    cout << res << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while(T--) solution();
    return 0;
}