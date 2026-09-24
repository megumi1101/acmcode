#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
const ll inf=0x3f3f3f3f3f3f3f3f;
int T,m;
ll a0,a1,a2,a3,cost[N],f[N][16];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T>>a0>>a1>>a2>>a3;
    cost[0]=min(min(min(4*a0,2*a1),2*a2),a3);
    cost[14]=cost[13]=cost[11]=cost[7]=a0;
    cost[5]=cost[10]=min(2*a0,a2);
    cost[3]=cost[12]=min(2*a0,a1);
    cost[9]=cost[6]=min(2*a0,a1+a2);
    cost[8]=cost[4]=cost[2]=cost[1]=min(3*a0,min(a3+a0,a0+min(a1,a2)));
    cost[15]=2*min(min(min(a0,a1),a2),a3);
    memset(f,0x3f,sizeof(f));
 
    for (int i=0;i<16;i++) f[(1<<i)][i]=cost[i];
    for (int i=1;i<65536;i++)
        for (int j=0;j<16;j++) if((i&(1<<j))>0)
            for (int k=0;k<16;k++) if((i&(1<<k))==0)
            {
                int t=k;
                for (int l=0;l<4;l++)
                    if((j&(1<<l))==0)
                        t^=(1<<l);
                f[i+(1<<k)][k]=min(f[i+(1<<k)][k],f[i][j]+cost[t]);
            }
    while (T--)
    {
        cin>>m;
        int zt=0;
        ll ans=inf;
        for (int i=1;i<=m;i++)
        {
            int t=0;
            cin>>s;if(s[0]=='1') t+=1;if(s[1]=='1') t+=2;
            cin>>s;if(s[0]=='1') t+=4;if(s[1]=='1') t+=8;
            zt+=(1<<t);
        }
        // cout<<"zt="<<zt<<"\n";
        for (int i=0;i<=15;i++) ans=min(ans,f[zt][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
