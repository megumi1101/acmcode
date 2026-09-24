#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 998244353;
    int f[21][2][1050];
    int g[21][2][1050];
    int a[21];
    int num[1050];
    int p10[21];
    int k;
    struct node {
        int t1,t2;
    };
    node dfs(int len, bool qd, bool lim, int now) {
        if(!lim && f[len][qd][now]!=-1) return (node){f[len][qd][now], g[len][qd][now]};
        if(len==0) {
            return (node) {1,0};
        }
        int r1=0,r2=0;
        int up=9;
        if(lim)up=a[len];
        for(int i=0;i<=up;i++) {
            int tnow;
            if(qd&&i==0)tnow=0;
            else tnow=now|(1<<i);
            if(num[tnow] > k)continue;
            node u = dfs(len-1,qd&&i==0,lim&&i==up,tnow);
            (r1 += u.t1) %=mod;
            (r2 += i * u.t1 %mod * p10[len-1] %mod + u.t2) %=mod; 
        }
        if(!lim)return (node){f[len][qd][now]=r1, g[len][qd][now]=r2};
        else return {r1,r2};
    }
    int sol(int x) {
        memset(f,-1,sizeof(f));
        memset(g,-1,sizeof(g));
        int cnt=0;
        while(x) {
            a[++cnt]=x%10;
            x/=10;
        }
        return dfs(cnt,1,1,0).t2;
    }
    void init() {
        for(int i=0;i<(1<<10);i++) {
            int res=0;
            for(int j=0;j<10;j++) {
                if(i&(1<<j))res++;
            }
            num[i]=res;
        }
        p10[0]=1;
        for(int i=1;i<=19;i++) {
            p10[i]=p10[i-1]*10%mod;
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        init();
        int l, r;
        cin>>l>>r>>k;
        cout<<(sol(r)-sol(l-1) +mod) %mod;
    }
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
