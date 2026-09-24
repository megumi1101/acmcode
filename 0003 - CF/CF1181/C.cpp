#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    #define int long long
    const int N=1004;
    int n,m;
    string s[N];
    int f[N][N];
    int ans=0;
    int a,b,c,d,pa,pb,pc,pd,cnt;
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>s[i],s[i]='0'+s[i];
        for(int j=1;j<=m;j++)f[n][j]=1;
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(s[i][j]!=s[i+1][j])f[i][j]=1;
                else f[i][j]=f[i+1][j]+1;
            }
        }
        for(int i=1;i<=n;i++){
            cnt=0;
            pa=-1,pb=-1,pc=-1,pd=-1;
            for(int j=1;j<=m;j++){
                a=i,b=a+f[a][j],c=b+f[b][j],d=c+f[c][j];
                //cout<<a<<" "<<b<<" "<<c<<"  "<<d<<"\n";
                if(c<=n&&b-a==c-b&&b-a<=d-c){
                    //cout<<"dfs";
                    if(pc<=n&&pa==a&&pb==b&&pc==c&&pb-pa<=pd-pc&&s[a][j-1]==s[a][j]&&s[b][j-1]==s[b][j]&&s[c][j-1]==s[c][j]){
                        cnt++;
                       // cout<<"xx";
                    }
                    else{
                        ans+=cnt*(cnt+1)/2;
                        cnt=1;
                    }
                }
                pa=a;pb=b;pc=c;pd=d;
            }
            ans+=cnt*(cnt+1)/2;
        }
        cout<<ans;
    }
}
