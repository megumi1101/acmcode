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
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')a++;
            else b++;
        }
        a=min(a,b);
        if((a%2)==1)cout<<"DA"<<"\n";
        else cout<<"NET"<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
