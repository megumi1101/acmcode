#include <bits/stdc++.h>

using namespace std;

#define int long long

// 1
// 证明 B 是偶数
// 令 S 为数位和
// S + S + C - BC = S && S = B (B - 1) / 2
// => C = B / 2
// B 为偶数 且 进位数为 B / 2

// 2
// 找一个特殊的 q
// !! 不妨令 q = p + t (mod B); t in [1, B - 1]
// r = p + q + c_p(输入进位) = 2p + t + c_p (mod B)


// 3
// 使得 r 是排列
// 令 k = B / 2
// gcd(B, 2) = 2, 2p + t (mod B) 每隔 k 位会循环, 要使 r 是排列 => c_p != c_{p + k}

// 4
// 使得 p != q != r

// 4.1 假设 p = r
// p = 2p + t + c_p (mod B)
// <=> p + t + c_p = 0 (mod B)
// c_p = 0 / 1
// 所以 p + t = 0 / -1 时 上面才会成立
// 4.1.1 假设 p + t = 0(mod B) => p = B - t => c_{B - t} = 1
// 4.1.2 假设 p + t = -1(mod B) => p = B - t - 1 => c_{B - t - 1} = 0

// 4.2 假设 q = r
// p + t = 2p + t + c_p (mod B)
// <=> p + c_p = 0 (mod B)
// c_p = 0 / 1
// 所以 p = 0 / -1 时 上面才会成立
// 4.2.1 假设 p = 0(mod B) => p = 0 => c_{0} = 1 (使得 q != r)
// 4.2.2 假设 p = -1(mod B) => p = B - 1 => c_{B - 1} = 0

// 现在的条件
// c_p ^ 1 = c_{p + k}
// c_{0} = 1
// c_{B - 1} = 0
// c_{B - t} = 1
// c_{B - t - 1} = 0
// 简单些 我们直接令 t = 2
// c_{0} = 1, c_{B - 3} = 0, c_{B - 2} = 1, c_{B - 1} = 0
// B = 4 单独构造
// B >= 6 都满足 c_p ^ 1 = c_{p + k}


// 设 d_p 为输出进位
// d_p 应该有 B / 2 个位置是 1
// 那么 c_p -> d_p 是当前输入进位到下一位输入进位的转化
// 满足条件的排列应该是最低位输入进位 为 0
//                   最高位输出进位 为 0
// 就是 从 0 开始的欧拉回路
// 我们不需要真正的跑欧拉回路 可以这样构造
// 0 -> 0 -> 0 -> 0 全部的 0 -> 0 (若存在)
// 0 -> 1
// 1 -> 1 -> 1 -> 1 全部的 1 -> 1 (若存在)
// 1 -> 0
// 0 -> 1
// ...
// 1 -> 0


const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int B;
    cin >> B;

    if (B == 4) {
        cout << "0 3 2 1\n";
        cout << "2 1 0 3\n";
        cout << "3 0 2 1\n";
        return 0;
    }

    if ((B & 1) || B < 4) {
        cout << "-1\n";
        return 0;
    }

    vector<int> c(B, -1);
    c[0] = 1, c[B - 3] = 0, c[B - 2] = 1, c[B - 1] = 0;
    int k = B / 2;
    for (int i = 0; i < k; i++) {
        if (c[i] != -1 && c[i + k] != -1) {
            // 无事发生
        } else if (c[i] == -1 && c[i + k] == -1) {
            c[i] = 1, c[i + k] = 0;
        } else if (c[i] != -1) {
            c[i + k] = c[i] ^ 1;
        } else {
            c[i] = c[i + k] ^ 1;
        }
    }

    vector<array<int, 3>> e[2][2];

    for (int i = 0; i < B; i++) {
        int q = (i + 2) % B;
        int r = (i + q + c[i]) % B;
        int d = (i + q + c[i]) / B;
        e[c[i]][d].push_back({i, q, r});
    }

    vector<int> P(B), Q(B), R(B);
    int b = 0;
    
    auto set = [&] (int p, int q, int r) {
        P[b] = p;
        Q[b] = q;
        R[b] = r;
        b++;
    };

    for (auto[p, q, r] : e[0][0]) {
        set(p, q, r);
    }
    
    {
        auto [p, q, r] = e[0][1].back();
        e[0][1].pop_back();
        set(p, q, r);
    }

    for (auto[p, q, r] : e[1][1]) {
        set(p, q, r);
    }

    while (e[0][1].size() || e[1][0].size()) {
        if (e[1][0].size()) {
            auto [p, q, r] = e[1][0].back();
            e[1][0].pop_back();
            set(p, q, r);
        }

        if (e[0][1].size()) {
            auto [p, q, r] = e[0][1].back();
            e[0][1].pop_back();
            set(p, q, r);
        }
    }

    for (int i = B - 1; i >= 0; i--) cout << P[i] << " ";
    cout << "\n";
    for (int i = B - 1; i >= 0; i--) cout << Q[i] << " ";
    cout << "\n";
    for (int i = B - 1; i >= 0; i--) cout << R[i] << " ";
    cout << "\n";
}
