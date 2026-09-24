#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int inline rd()
{
    int ans=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans*f;
}
const int N=1e6+10;
int n,m,c,k,a[N],p[N],q[N],p2[65];
bool vs[65],vs2[65];
void wk(int x)
{
    for(int i=0;i<=63;i++)
    {
        if(!x)break;
        if((x&1)&&vs2[i])
        {
            if(!vs[i])vs[i]=1;
        }
        x/=2;
    }
}
signed main()
{
    //freopen("C:\\Users\\xbb\\Desktop\\zoo\\zoo3.in","r",stdin);
    n=rd(),m=rd(),c=rd(),k=rd();p2[0]=1;
    if(n==0&&k==64){printf("18446744073709551616");return 0;}
    for(int i=1;i<=63;i++)p2[i]=2*p2[i-1];
    for(int i=1;i<=n;i++)a[i]=rd();
    for(int i=1;i<=m;i++)p[i]=rd(),q[i]=rd(),vs2[p[i]]=1;
    for(int i=1;i<=n;i++)wk(a[i]);int cnt=0;
    for(int i=0;i<=63;i++)
    {
        if(vs2[i]&&!vs[i])cnt++;
    }
    printf("%llu",p2[k-cnt]-n);
    return 0;
}
