// LUOGU_RID: 93305244
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a;
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&a);
    printf("%lld",((n-1)/a+1)*((m-1)/a+1));
    return 0;
}
