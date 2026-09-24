#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1); // 1-based indexing
        ordered_set s;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }

        int threshold = n / 2; // ceil((n-1)/2)

        auto get_numb = [&]() -> int {
            if (s.size() == 0) return 0;
            int median_pos = (s.size() - 1) / 2;
            auto it = s.find_by_order(median_pos);
            int median = *it;
            return s.order_of_key(median);
        };

        cout << get_numb() << '\n';

        while (q--) {
            int p, v;
            cin >> p >> v;
            s.erase(a[p]);
            a[p] += v;
            s.insert(a[p]);
            cout << get_numb() << '\n';
        }
    }

    return 0;
}