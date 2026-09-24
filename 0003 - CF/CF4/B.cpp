// LUOGU_RID: 146815129
#include<bits/stdc++.h>
using namespace std;
#define int long long
int d,n;
int l[500],r[500],mn,mx;
signed main()
{
    scanf("%lld%lld",&d,&n);
    for(int i=1;i<=d;i++)
    {
        scanf("%lld%lld",&l[i],&r[i]);
        mn+=l[i];mx+=r[i];
    }
    if(n<mn||n>mx)puts("NO");
    else
    {
        puts("YES");
        n-=mn;
        for(int i=1;i<=d;i++)
        {
            if(n==0)printf("%lld ",l[i]);
            else if(n>(r[i]-l[i]))
            {
                printf("%lld ",r[i]);
                n-=(r[i]-l[i]);
            }
            else
            {
                printf("%lld ",l[i]+n);
                n=0;
            }
        }
    }
    return 0;
}
