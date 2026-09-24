## mabacher
在O(n)的时间内求出一个字符串的最长回文串
可以在两个字符之间添加 # ,这样可以保证所有的回文串都是奇回文串
d[i]表示回文半径,例如 #a#b#a# 的回文半径为 4, 我们同样可以得知在原字符串中该回文串的长度就是 **回文半径 - 1**
维护当前**右端点最靠右**的最长回文串的l, r (左右端点)
```cpp
vector get_d (string s) {
    int n = (int)s.size();
    vector<int> d(n);
    d[1] = 1;
    for (int i = 2, l, r = 1, i < s.size(); i++) {
        if (i <= r) d[i] = min(d[r + l - i], r - i + 1);
        while (s[i + d[i]] == s[i - d[i]]) d[i]++;
        if (i + d[i] - 1 > r) r = i + d[i] - 1, l = i - d[i] + 1;
    } 
    return d;
}
string s = "&#";
string tmp; cin >> tmp;
for (char c : string tmp) {
    s += c;
    s += "#"
}
```