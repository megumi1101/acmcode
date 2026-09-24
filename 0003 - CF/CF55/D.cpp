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
    int gcd(int a,int b){return b?gcd(b,a%b):a;}
    int lcm(int a,int b){return a*b/gcd(a,b);}
    const int mod=1e9+7;
    int a[1005];
    int lc[50],numlc[2530];
    string A,B;
    int f[19][2530][48];
    string minus(string A){
        A[A.size()-1]-=1;
        for(int i=A.size()-2;i>=0;i--){
            if(A[i+1]<'0')A[i+1]+=10,A[i]-=1;
        }
        return A;
    }
    int dfs(int len,int qm,int nowlcm,int lim){
        if(!lim&&f[len][qm][nowlcm]!=-1)return f[len][qm][nowlcm];
        if(len==0){
            if(qm%(lc[nowlcm])==0)return 1;
            return 0;
        }
        int up=lim?a[len]:9;
        int res=0;
        for(int i=0;i<=up;i++){
            res+=dfs(len-1,(qm*10+i)%2520,i==0?nowlcm:numlc[lcm(lc[nowlcm],i)],lim&&(i==up));
        }
        if(!lim)f[len][qm][nowlcm]=res;
        return res;
    }
    int sol(string A){
        memset(a,0,sizeof(a));
        int cnt=0;
        for(int i=A.size()-1;i>=0;i--){
            a[++cnt]=A[i]-'0';
        }
        while(a[cnt]==0&&cnt)cnt--;
        return dfs(cnt,0,1,1);
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        memset(f,-1,sizeof(f));
        int cnt=1;lc[1]=numlc[1]=1;
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=9;j++){
                if(numlc[lcm(lc[i],j)]==0){
                    lc[++cnt]=lcm(lc[i],j);
                    numlc[lcm(lc[i],j)]=cnt;
                }
            }
        // for(int i=2;i<=2520;i++){
        //     if(2520%i==0){
        //         lc[++cnt]=i;
        //         numlc[i]=cnt;
        //     }
        // }
        int T;
        cin>>T;
        while(T--){
            string A,B;
            cin>>A>>B;
            if(A.size()==1&&A[0]==0)cout<<sol(B)<<"\n";
            else cout<<sol(B)-sol(minus(A))<<"\n";
        }
    }
}
