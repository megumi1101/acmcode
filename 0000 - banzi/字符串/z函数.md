## Z 函数（扩展 KMP）

`z[i]` 表示字符串 `s` 与后缀 `s[i..n-1]` 的最长公共前缀长度，下标从 0 开始。这里约定 `z[0] = 0`；若题目要求它表示整个字符串的长度，可在非空时改为 `z[0] = n`。

例如，`s = "ababa"` 时，`z = [0, 0, 3, 0, 1]`，因为从下标 2 开始的 `aba` 与字符串前缀相同。

### C++ 模板

```cpp
vector<int> get_z(const string& s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    // [l, r) 是已处理位置中右端点最远的匹配区间，满足 s[l..r) = s[0..r-l)。
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
```

维护左闭右开的匹配区间 `[l, r)`：

1. 若 `i < r`，利用区间与前缀相同的性质，先令 `z[i] = min(r - i, z[i - l])`。不能直接照搬 `z[i - l]`，因为超出 `r` 的部分还没有确认。
2. 从已知匹配长度开始继续比较，求出完整的 `z[i]`。
3. 若 `i + z[i] > r`，用当前匹配更新 `[l, r)`。

需要逐个比较的成功扩展只会将右边界向右推进，每个位置至多再有一次失配比较，因此总时间复杂度为 `O(n)`，空间复杂度为 `O(n)`。空串返回空数组。

### 应用：字符串匹配

设文本串为 `s`，模式串为 `t`，拼接 `a = t + '#' + s`，其中 `#` 必须是模式串和文本中都没有出现的字符。设 `m = t.size()`，若某个文本位置对应的 `z[i] >= m`，就找到了一个完整匹配，起点为 `i - m - 1`。

```cpp
// 返回所有匹配起点，下标从 0 开始，允许重叠。
// 要求 s 和 t 都不包含 '#'；此处约定不匹配空模式串。
vector<int> z_search(const string& s, const string& t) {
    if (t.empty()) return {};
    int m = (int)t.size();
    auto z = get_z(t + '#' + s);
    vector<int> ans;
    for (int i = m + 1; i < (int)z.size(); ++i) {
        if (z[i] >= m) ans.push_back(i - m - 1);
    }
    return ans;
}
```

例如，`z_search("ababa", "aba")` 返回 `[0, 2]`。匹配的时间和空间复杂度均为 `O(|t| + |s|)`。
