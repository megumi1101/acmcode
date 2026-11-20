#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n, a1, a2, a3;
    cin >> n >> a1 >> a2 >> a3;
    vector<pair<int, int>> prs;
    if (a1 >= 2) {
        prs.push_back({1, 2});
        prs.push_back({2, 3});
        int pt = 3;
        while (a2--) {
            pt++;
            prs.push_back({2, pt});
        }

        int op = 0;
        while (a3--) {
            op ^= 1;
            pt++;
            if (op & 1) prs.push_back({1, pt});
            else prs.push_back({2, pt});
        }

        while (pt + 1 <= n) {
            pt++;
            prs.push_back({pt - 1, pt});
        }
    } else if (a1 == 1 && a2 >= 2){
        prs.push_back({1, 2});
        prs.push_back({1, 3});
        int pt = 3;
        a2--;
        while (a2--) {
            pt++;
            prs.push_back({1, pt});
        }

        int op = 0;
        while (a3--) {
            op ^= 1;
            pt++;
            if (op & 1) prs.push_back({2, pt});
            else prs.push_back({1, pt});
        }
    } else if (a1 == 1 && a2 == 1) {
        prs.push_back({8, 2});
        prs.push_back({8, 3});
        prs.push_back({8, 5});
        prs.push_back({8, 7});
        prs.push_back({1, 5});
        prs.push_back({7, 4});
        prs.push_back({3, 6});
        int pt = 8;
        int op = 0;

        while (pt + 1 <= n) {
            op ^= 1;
            pt++;
            if (op & 1) prs.push_back({4, pt});
            else prs.push_back({7, pt});
        }
    } else if (a1 == 1) {
        prs.push_back({5, 2});
        prs.push_back({5, 6});
        prs.push_back({1, 6});
        prs.push_back({3, 6});
        prs.push_back({1, 4});
        int pt = 6;
        int op = 0;

        while (pt + 1 <= n) {
            op ^= 1;
            pt++;
            if (op & 1) prs.push_back({4, pt});
            else prs.push_back({1, pt});
        }
    } else if (a2 >= 2 && a3 >= 2) {
        a2 -= 2;
        a3 -= 2;
        prs.push_back({3, 5});
        prs.push_back({3, 1});
        prs.push_back({5, 2});
        prs.push_back({2, 4});

        int pt = 5;
        int op = 0;
        while (a2--) {
            pt++;
            prs.push_back({3, pt});
        }

        while (a3--) {
            pt++;
            op ^= 1;
            if (op & 1) prs.push_back({1, pt});
            else prs.push_back({3, pt});
        }
    } else if (a2 == 1) {
        prs.push_back({1, 4});
        prs.push_back({1, 6});
        prs.push_back({2, 5});
        prs.push_back({3, 7});
        prs.push_back({5, 7});
        prs.push_back({1, 7});
        prs.push_back({4, 8});

        int pt = 8;
        int op = 0;
        while (pt + 1 <= n) {
            pt++;
            op ^= 1;
            if (op & 1) prs.push_back({1, pt});
            else prs.push_back({4, pt});
        }
    } else if (a3 == 1) {
        prs.push_back({1, 3});
        prs.push_back({1, 4});
        prs.push_back({2, 4});

        int pt = 4;
        while (pt + 1 <= n) {
            pt++;
            prs.push_back({1, pt});
        }
    } else if (a3 == n - 1) {
        prs.push_back({1, 4});
        prs.push_back({1, 6});
        prs.push_back({1, 8});
        prs.push_back({3, 8});
        prs.push_back({5, 8});
        prs.push_back({2, 5});
        prs.push_back({4, 7});
        int pt = 8;
        int op = 0;
        while (pt + 1 <= n) {
            pt++;
            op ^= 1;
            if (op & 1) prs.push_back({2, pt});
            else prs.push_back({5, pt});
        }
    } else {
        cout << "-1\n";
        return;
    }

    for (auto[x, y] : prs) {
        cout << x << " " << y << "\n";
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}