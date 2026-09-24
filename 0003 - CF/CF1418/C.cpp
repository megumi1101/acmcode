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
    void solve(){
        int n;cin>>n;
        vector<int>a(n+3),b(n+3);
        for(int i=1;i<=n;i++)cin>>a[i];
        bool op=0;
        int ans=0;
        for(int i=1;i<=n;){
            op^=1;
            if(op==1){
                if(a[i]==0&&a[i+1]==0&&a[i+2]==0){i+=1;continue;}
                else if(a[i]==0&&a[i+1]==0&&a[i+2]==1){i+=2;}
                else if(a[i]==1&&a[i+1]==0&&a[i+2]==0){i+=1;ans++;continue;}
                else if(a[i]==1&&a[i+1]==0&&a[i+2]==1){i+=2;ans++;continue;}
                else if(a[i]==1&&a[i+1]==1)i++,ans++;
                else i++;
            }
            else{
                if(a[i]==0&&a[i+1]==0)i++;
                else if(a[i]==1&&a[i+1]==1)i+=2;
                else if(a[i]==1&&a[i+1]==0)i++;
                else i+=2;
            }
        }
        cout<<ans<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;cin>>T;
        while(T--)solve();
    }
}
/*
1 5
1 0 0 1 1
1 8
1 0 1 1 0 1 1 1
*/
