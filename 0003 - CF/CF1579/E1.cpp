#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        deque<int> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!q.empty()) {
                if (a[i] < q.front()) {
                    q.push_front(a[i]);
                    continue;
                }
            }
            q.push_back(a[i]);
        }
        while(!q.empty()) {
            cout << q.front() <<" ";
            q.pop_front();
        }
        cout << "\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
