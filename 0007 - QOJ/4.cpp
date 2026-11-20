#include <bits/stdc++.h>
using namespace std;

namespace {
constexpr int max_n = 100'000;
constexpr long long max_value = 1'000'000'000'000'000'000LL;

std::vector<long long> values;
int subtask;
long long cost = 0;
}




void MinMax(long long s, long long t, long long* mn, long long* mx) {
    if (s > t) {
        std::cerr << "MinMax requires s <= t.\n";
        std::exit(EXIT_FAILURE);
    }

    const auto first = std::lower_bound(values.cbegin(), values.cend(), s);
    const auto past_last = std::upper_bound(first, values.cend(), t);

    ++cost;
    if (subtask == 2) {
        cost += past_last - first;
    }

    if (first == past_last) {
        *mn = *mx = -1;
        return;
    }
    *mn = *first;
    *mx = *(past_last - 1);
}

long long findGap(int T, int n) {
    if (T == 1) {
        vector<long long> a(n);
        long long l = 0, r = n - 1;
        long long L = 0, R = 1000000000000000000LL;
        long long mn, mx;
        for (int i = 0; i < (n + 1) / 2; i++) {
            MinMax(L, R, &mn, &mx);
            a[l] = mn;
            a[r] = mx;
            l++, r--;
            L = mn + 1, R = mx - 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, a[i + 1] - a[i]);
        }
        return ans;
    } else if (T == 2) {
        long long L = 0, R = 1000000000000000000LL;
        long long mn, mx;
        MinMax(L, R, &mn, &mx);
        long long ans = (R - L - 1) / (n - 1) + 1;
        L = mn, R = mx;

        int now = L;
        MinMax(L, R, &mn, &mx);
        return ans;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> subtask >> n) || subtask < 1 || subtask > 2 ||
        n < 2 || n > max_n) {
        std::cerr << "Expected T in [1, 2] and N in [2, 100000].\n";
        return EXIT_FAILURE;
    }

    values.resize(n);
    long long previous = -1;
    for (long long& value : values) {
        if (!(std::cin >> value) || value <= previous || value > max_value) {
            std::cerr << "Expected N strictly increasing integers in [0, 10^18].\n";
            return EXIT_FAILURE;
        }
        previous = value;
    }

    const long long answer = findGap(subtask, n);
    std::cout << answer << '\n' << cost << '\n';
}
/*
我想这样写，对于T=1，直接知道最左边那个数最右边那个数，这样是M+1/2次。对于T=2，先花N+1的代价，确定
左右区间，和最大值的最小可能代价是R-L/(N-1),记作m
然后我们已知我们确定的最小的数是a
我先询问 a + 1, a + m左闭右开
如果存在，我们记最大值为b，用b替换a
再询问a+1, a+m不存在，询问a+1,a+2m
询问a+1,a+4m 直到存在
然后用最小值-a替换成m
用最大值替换成a
*/
