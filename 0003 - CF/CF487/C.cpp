#include <bits/stdc++.h>

using namespace std;

#define int long long

int fap(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a, int mod) {
    return fap(a, mod - 2, mod);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES\n1";
    } else if (n == 2) {
        cout << "YES\n1\n2";
    } else if (n == 3) {
        cout << "YES\n1\n2\n3";
    } else if (n == 4) {
        cout << "YES\n1\n3\n2\n4";
    } else {
        int fg=0;
        for (int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                fg=1;
        if(fg==1)
        {
            cout<<"NO";
            return 0;
        }
        cout<<"YES\n1\n";
        for (long long i=2;i<=n-1;i++)
        {
            cout<<i*inv(i-1,n)%n<<"\n";
        }
        cout<<n;
    }
}