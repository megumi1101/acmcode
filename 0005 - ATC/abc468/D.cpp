#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int cnt, ans = 0;
    for (int mid = 0; mid < n; mid++) {
        int l = mid, r = mid;
        cnt = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) cnt++;
            if (cnt <= 1) ans++;
            else {
                break;
            }
            l--, r++;
        }

        l = mid, r = mid + 1;
        cnt = 0;

        while (l >= 0 && r < n) {
            if (s[l] != s[r]) cnt++;
            if (cnt <= 1) ans++;
            else {
                break;
            }
            l--, r++;
        }

    }

    cout << ans << "\n";
}
/*
vector<vector<int>> tab;

// x 表示当前要插入的数，row 表示当前正在尝试插入的行号
void insert(int x, int row) {
    // 如果第 row 行还不存在，就新开一行并放入 x
    if (row == (int)tab.size()) {
        tab.push_back({x});
        return;
    }

    // pos 指向第 row 行中第一个大于 x 的位置
    auto pos = upper_bound(tab[row].begin(), tab[row].end(), x);

    // 如果没有元素大于 x，说明 x 可以直接接在这一行末尾
    if (pos == tab[row].end()) {
        tab[row].push_back(x);
        return;
    }

    // bumped 是被 x 挤出的数，需要继续插入下一行
    int bumped = *pos;
    *pos = x;
    insert(bumped, row + 1);
}

int main() {
    // seq 表示待插入序列
    vector<int> seq = {4, 1, 3, 2, 6, 5, 7};

    for (int x : seq) {
        insert(x, 0); // 每个数都从第 0 行开始插入
    }

    // 输出最终杨表；tab[0].size() 就是 LIS 长度
    for (auto &line : tab) {
        for (int x : line) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
*/