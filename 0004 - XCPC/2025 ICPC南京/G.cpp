#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
struct node {
    ll v, l;
    node(ll v_ = 0ll, ll l_ = 0ll) : v(v_), l(l_) {}
};
void solution() {
    int n, q;
    ll sum=0ll,cntv = 0ll, cntl = 0ll, t,im=0ll;
    vector<ll> v, l;
    map<ll, node> p;
    cin >> n, v.resize(n), l.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i], cntv += v[i],sum+=v[i];
    for (int i = 0; i < n; ++i) cin >> l[i], cntl += l[i];
    sort(v.begin(), v.end()), sort(l.begin(), l.end(), greater<ll>());
    for (int i = 0; i < n; ++i) {
        if (l[i]) {
            if(!p.count(v[i]/l[i])) p[v[i] / l[i]] = node(cntv, cntl);
            cntv -= v[i], cntl -= l[i];
        } else {
            im+=v[i];
        }
    }
    // for(map<ll,node>::iterator it = p.begin();it!=p.end();++it){
    //     cout<<"it->first = "<<it->first<<" it->second.v = "<<it->second.v<<" it->second.l = "<<it->second.l<<'\n';
    // }
    cin >> q;
    for (; q--;) {
        cin >> t;
        if(!t){
            cout<<sum<<' ';
            continue;
        }
        map<ll, node>::iterator it = p.lower_bound(t);
        // cout << "t = " << t << " it->first = " << ixt->first << '\n';
        if (it != p.end()) {
            cout << it->second.v - it->second.l * t << ' ';
        } else
            cout << im<<' ';
    }
    cout << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
2
4
5 4 7 6
2 1 3 2
3
3 1 2
4
19 47 21 13
5 14 2 3
5
5 2 6 1 4

1
5
5 5 4 7 6
2 2 1 2 2
3
3 1 2

1
4
5 4 3 2
0 0 0 1
3
3 1 0
*/