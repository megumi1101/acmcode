// LUOGU_RID: 93306854
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int x;
    scanf("%lld",&x);
    if(x&1||x<=3)puts("NO");
    else puts("YES");
    return 0;
}
