#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
#define ld long double
int T,n;
ll xx,yy,x[N],y[N],dis[N];
ld p[N];
const ld pi=acos(-1);
ll cross(ll x_1,ll y_1,ll x_2,ll y_2)
{
    return x_1*y_2-x_2*y_1;
}
ld ab(ld x)
{
    if(x<0) x=-x;
    return x;
}
ll sqr(ll x){return x*x;}
bool cmp(ld x,ld y){return x<y;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n>>xx>>yy;
        for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
        x[n+1]=x[1],y[n+1]=y[1];
        int cnt1=0,cnt2=0;
        for (int i=1;i<=n;i++)
        {
            ll q=cross(x[i] - xx,y[i] - yy,x[i+1] -xx,y[i+1] -yy);
            if(q>0) cnt1++;
            if(q<0) cnt2++;
        }
        if(cnt1==0||cnt2==0)
        {
            ll ma=0;
            ld ans=0;
            int tot=0;
            for (int i=1;i<=n;i++)
            {
                dis[i]=sqr(x[i]-xx)+sqr(y[i]-yy);
                ma=max(ma,dis[i]);
            }
            for (int i=1;i<=n;i++)
                if(dis[i]==ma)
                {
                    p[++tot]=atan2((ld)yy-y[i],(ld)xx-x[i]);
                    if(p[tot]<0) p[tot]+=2*pi;
                }
            sort(p+1,p+tot+1,cmp);
//            for (int i=1;i<=n;i++) printf("p[%d]=%.08Lf\n",i,p[i]);
            for (int i=1;i<tot;i++) ans=max(ans,ab(p[i+1]-p[i]));
            ans=max(ans,2*pi+p[1]-p[tot]);
            printf("%.9Lf\n",ans);
        }
        else printf("%.9Lf\n",2*pi);
    }
    return 0;
}