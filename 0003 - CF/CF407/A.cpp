#include <bits/stdc++.h>
using namespace std;

namespace xbbbz {
    int gcd(int a,int b) {
        return b?gcd(b,a%b):a;
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int a, b, ans[5];
        int cnt=0;
        cin>>a>>b;
        int c=gcd(a,b);
        for(int i=1;i<=c;i++) {
            int j=sqrt(c*c-i*i);
            if((j*j+i*i)==c*c&&j) {
                ans[++cnt] = -a/c*j;
                ans[++cnt] = a/c*i;
                ans[++cnt] = b/c*i;
                ans[++cnt] = b/c*j;
                break;
            }
        }
        // for(int i=1;i<=a;i++) {
        //     int j=sqrt(a*a-i*i);
        //     if((j*j+i*i)==a*a&&j) {
        //         ans[++cnt] = -j;
        //         ans[++cnt] = i;
        //         break;
        //     }
        // }
        // for(int i=1;i<=b;i++) {
        //     int j=sqrt(b*b-i*i);
        //     if((j*j+i*i)==b*b&&j) {
        //         ans[++cnt] = i;
        //         ans[++cnt] = j;
        //         break;
        //     }
        // }
        if(cnt==4)cout<<"YES"<<"\n";
        else {
            cout<<"NO";
            return;
        }
        if(ans[2]==ans[4])swap(ans[1],ans[2]),swap(ans[3],ans[4]),ans[1]*=-1,ans[2]*=-1;
        for(int i=1;i<=2;i++) { 
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        for(int i=3;i<=4;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        cout<<"0 0";
    }
}

int main() {
    return xbbbz::main(), 0;
}
