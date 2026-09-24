#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main() ;
}
int main(){
    return xbbbz::main() ,0;
}
namespace xbbbz{
    #define int long long
    int c[5],d[5],s,n;
    int f[1000005];
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
        f[0]=1;
        for(int i=1;i<=4;i++){
            for(int j=0;j<=1000000;j++){
                if(j-c[i]>=0)f[j]+=f[j-c[i]];
            }
        }
        for(int i=1;i<=n;i++){
            cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
            int ans=f[s];
            for(int j=1;j<=4;j++){
                int res=s-(d[j]+1)*c[j];
                if(res>=0)ans-=f[res];
            }
            for(int j=1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    int res=s-(d[j]+1)*c[j]-(d[k]+1)*c[k];
                    if(res>=0)ans+=f[res];
                }
            }
            for(int j=1;j<=4;j++){
                int res=s,cnt=0;
                for(int k=1;k<=4;k++){
                    if(k!=j)res-=(d[k]+1)*c[k],cnt++;
                    if(cnt==3&&res>=0){ans-=f[res];break;}
                }
            }
            int res=s;
            for(int k=1;k<=4;k++){
                res-=(d[k]+1)*c[k];
                if(k==4&&res>=0)ans+=f[res];
            }
            if(ans<0)ans=0;
            cout<<ans<<"\n";
        }
    }
}