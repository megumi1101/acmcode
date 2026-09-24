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
    void sol(){
        string s;cin>>s;int n=0;
        for(int i=0;i<s.size();i++)n=n*10+s[i]-'0';
        // cout<<n<<"\n";
        int a=0;
        for(int i=1;i<s.size();i++)a=a*10+9;
        // cout<<a<<"\n";
        int b=n-a,res=0;
        while(b){
            res+=b%10;
            b/=10;
        }
        res+=(s.size()-1)*9;
        cout<<res;
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T=1;
        while(T--)sol();
    }
}
