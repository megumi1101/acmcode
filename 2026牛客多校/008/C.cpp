#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int fp(int a, int b, int mod) {
    int res = 1;
    for(; b; b >>= 1, a = (long long)a * a % mod) if(b & 1) res = (long long)res * a % mod;
    return res;
}
int inv(int a, int mod) {
    return fp(a, mod - 2, mod);
}
int main() {
    int T, mod = 17;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int b = 2; b < mod; ++b) {
        for(int a = 1; a < b; ++a) {
            if((double)a / b > (double)(a * inv(b, mod) % mod) / mod && gcd(a, b) == 1) 
                cout << "a = " << a << " b = " << b << "  ab^-1 = " << a * inv(b, mod) % mod << '\n';
        }
    }
    return 0;
}