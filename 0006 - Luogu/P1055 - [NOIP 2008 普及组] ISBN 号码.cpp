#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        string s;
        cin>>s;
        int x=1,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-')continue;
            ans+=x*(s[i]-'0');
            x++;
            if(x==10)break;
        }
        ans%=11;
        x=s.back()-'0';
        if(ans==10){
            x=s.back()-'X';
            if(x==0)puts("Right");
            else{
                s.pop_back();
                s+='X';
                cout<<s;
            }
        }
        else if(x==ans)puts("Right");
        else{
            s.pop_back();
            s+=to_string(ans);
            cout<<s;
        }
        return;
    }
}