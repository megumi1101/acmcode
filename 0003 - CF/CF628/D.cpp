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
    const int mod=1e9+7;
    int a[2005];
    int m,d;
    string A,B;
    int f[2005][2005][2];
    string minus(string A){
        A[A.size()-1]-=1;
        for(int i=A.size()-2;i>=0;i--){
            if(A[i+1]<'0')A[i+1]+=10,A[i]-=1;
        }
        return A;
    }
    int dfs(int len,int qm,bool lim,bool qd,bool odd){
        if(!lim&&f[len][qm][odd]!=-1)return f[len][qm][odd]%mod;
        if(len==0)return qm==0;
        int up=lim?a[len]:9;
        int res=0;
        for(int i=0;i<=up;i++){
            if(qd&&(i==0))continue;
            if(odd&&i==d)continue;
            if(!odd&&i!=d)continue;
            res+=dfs(len-1,(qm*10+i)%m,lim&&(i==up),0,odd^1);res%=mod;
        }
        if(!lim)f[len][qm][odd]=res%mod;
        return res%mod;
    }
    int sol(string A){
        memset(a,0,sizeof(a));
        memset(f,-1,sizeof(f));
        int cnt=0;
        for(int i=A.size()-1;i>=0;i--){
            a[++cnt]=A[i]-'0';
        }
        while(a[cnt]==0&&cnt)cnt--;
        return dfs(cnt,0,1,1,1);
    }
    int pd(string A){
        memset(a,0,sizeof(a));
        int cnt=0;
        for(int i=A.size()-1;i>=0;i--){
            a[++cnt]=A[i]-'0';
        }
        while(a[cnt]==0&&cnt)cnt--;
        int odd=0,qm=0;
        for(int i=cnt;i>=1;i--){
            odd^=1;
            if(odd&&a[i]==d)return 0;
            if(!odd&&a[i]!=d)return 0;
            qm=(qm*10+a[i])%m;
        }
        return qm==0;
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T=1;
        cin>>m>>d;
        while(T--){
            string A,B;
            cin>>A>>B;
            //if(A.size()==1&&A[0]==0)cout<<sol(B)<<"\n";
            cout<<(sol(B)-sol(A)+pd(A)+mod)%mod<<"\n";
        }
    }
}
