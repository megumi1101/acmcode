#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    void sol(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int res=0,ans=0;
        for(int i=0;i<s.size();i++)if(s[i]=='8')res++;
        for(int i=1;i<=9;i++){
            if(res>=i&&n>=i*11)ans=i;
        }
        cout<<ans;
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T=1;
        while(T--)sol();
    }
}
