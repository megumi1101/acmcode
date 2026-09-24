#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    void output2(int x){
        if(x>=2)output2(x>>1);
        putchar(x%2+'0');
    }
    int n,m;
    string s;
    int a[105],num[(1<<10)];
    vector<int>ed[105];
    bool vis[12];
    int f[2][(1<<10)][(1<<10)];
    void init(){
        for(int i=0;i<(1<<10);i++){
            for(int j=0;j<=9;j++){
                if(i&(1<<j))num[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='H')a[i]+=1;
                if(j==m-1)break;
                a[i]<<=1;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<(1<<m);j++){
                memset(vis,0,sizeof(vis));
                bool flag=0;
                if(!(j&a[i])){
                    for(int k=1;k<=m;k++){
                        int x=1<<(k-1);
                        if(j&x){
                            for(int l=-2;l<=2;l++){
                                if(l==0)continue;
                                if(l+k>=1&&l+k<=m){
                                    vis[l+k]=1;
                                }
                            }
                        }
                    }
                    for(int k=1;k<=m;k++){
                        int x=1<<(k-1);
                        if(j&x){
                            if(vis[k])flag=1;
                        }
                    }
                }
                else flag=1;
                if(!flag)ed[i].push_back(j);
            }
    }
    void main(){
        //ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>n>>m;
        init();
        if(n==1){
            int xx=0;
            for(auto v:ed[1])
                xx=max(num[v],xx);
            cout<<xx;
            return;
        }
        // if(n==2){
        //     int xx=0;
        //     for(auto v2:ed[2])
        //         for(auto v1:ed[1]){
        //             if(!(v1&v2))xx=max(xx,num[v1]+num[v2]);
        //         }
        //     cout<<xx;
        //     return;
        // }
        ed[0].push_back(0);
        int ans=0;
        int op=0;
        for(auto v2:ed[2])
            for(auto v1:ed[1])
                if(!(v1&v2))f[op][v2][v1]=max(f[op][v2][v1],num[v1]+num[v2]);
        for(int i=3;i<=n;i++){
            op^=1;
            for(auto v:ed[i]){
                for(auto v1:ed[i-1]){
                    for(auto v2:ed[i-2]){
                        if(!(v&v1))
                        if(!(v2&v1))
                        if(!(v&v2))
                            f[op][v][v1]=max(f[op][v][v1],f[op^1][v1][v2]+num[v]);
                    }
                }
            }
        }
        for(auto v:ed[n]){
            for(auto v1:ed[n-1])
                ans=max(f[op][v][v1],ans);
        }
        cout<<ans;
    }
}