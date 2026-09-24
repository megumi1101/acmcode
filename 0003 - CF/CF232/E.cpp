// LUOGU_RID: 95064188
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=600005;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,m,t;
bool ans[M];
char s[N][N];
bitset<N>f[N][N],g[N][N];
struct node
{
    int x1,y1,x2,y2,id;
}q[M],q1[M],q2[M];
void wk(int cl,int cr,int l,int r)
{
    if(cl>cr||l>r) return;
    int cnt1=0,cnt2=0,mid=(l+r)>>1;
    for(int i=mid;i>=l;--i)
        for(int j=m;j;--j)
        {
            if(s[i][j]=='#') continue;
            f[i][j].reset(),f[i][j][j]=(i==mid);
            if(i+1<=mid&&s[i+1][j]=='.') f[i][j]|=f[i+1][j];
            if(j+1<=m&&s[i][j+1]=='.') f[i][j]|=f[i][j+1];
        }
    for(int i=mid;i<=r;++i)
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]=='#') continue;
            g[i][j].reset(),g[i][j][j]=(i==mid);
            if(i-1>=mid&&s[i-1][j]=='.') g[i][j]|=g[i-1][j];
            if(j-1>=1&&s[i][j-1]=='.') g[i][j]|=g[i][j-1];
        }
    for(int i=cl;i<=cr;++i)
    {
        if(q[i].x2<mid) q1[++cnt1]=q[i];
        if(q[i].x1>mid) q2[++cnt2]=q[i];
        if(q[i].x1<=mid&&q[i].x2>=mid)
            ans[q[i].id]=(f[q[i].x1][q[i].y1]&g[q[i].x2][q[i].y2]).any();
    }
    for(int i=1;i<=cnt1;++i)q[cl+i-1]=q1[i];
    for(int i=1;i<=cnt2;++i)q[cl+cnt1+i-1]=q2[i];
    wk(cl,cl+cnt1-1,l,mid-1),wk(cl+cnt1,cl+cnt1+cnt2-1,mid+1,r);
}
int main()
{
    n=rid(),m=rid();
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    t=rid();
    for(int i=1;i<=t;++i)q[i]=(node){rid(),rid(),rid(),rid(),i};
    wk(1,t,1,n);
    for(int i=1;i<=t;++i)puts(ans[i]?"Yes":"No");
    return 0;
}
