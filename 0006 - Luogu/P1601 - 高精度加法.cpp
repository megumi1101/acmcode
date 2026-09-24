#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    string add(string a,string b){
        int l1=a.size();
        int l2=b.size();
        if(l1<l2){
            for(int i=1;i<=l2-l1;i++){
                a='0'+a;
            }
        }
        else if(l2<l1){
            for(int i=1;i<=l1-l2;i++){
                b='0'+b;
            }
        }
        int x=max(l1,l2)-1;
        int xx,yy=0;
        string s;
        for(int i=x;i>=0;i--){
            xx=a[i]-'0'+b[i]-'0'+yy;
            yy=xx/10;
            xx%=10;
            s=char(xx+'0')+s;
        }
        if(yy)s=char(yy+'0')+s;
        return s;
    }

    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        string a,b;
        cin>>a>>b;
        cout<<add(a,b);
        return;
    }
}
