#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void sol(){
        int n;
        cin>>n;
        vector<int> a(n+10);
        for(int i=1;i<=n;i++)cin>>a[i];
        int res=0;
        for(int i=1;i<=n;i++){
            a[i]%=2;
            if(i>1&&a[i]==a[i-1])res++;
        }
        cout << res << "\n";
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T=1;
        cin>>T;
        while(T--)sol();
    }
}
int main(){
    return xbbbz::main(),0;
}
