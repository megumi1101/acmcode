#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp> 

using namespace std;
using namespace __gnu_pbds; 

namespace Xbbbz {
    void sol() {
        __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> q;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }

        cout << q.size() << " ";
        while (!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
    }