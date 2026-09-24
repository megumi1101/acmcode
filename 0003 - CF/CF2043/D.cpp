#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    struct node {
        int x,y;
    };
    int gcd(int a, int b) {
        return b?gcd(b,a%b):a;
    }
    node pp(int l,int r,int g) {
        int len = r-l+1;
        int x,y;
        while(len) {
            for(int i=l;i+len-1<=r;i++) {
                if(gcd(i,i+len-1)==1) {x=i; y=x+len-1; return {x*g,y*g}; }
            }
            len--;
        }
        return{-1,-1};
    }
    void sol() {
        int l,r,g;
        cin>>l>>r>>g;
        node u = pp((l-1)/g+1,r/g,g);
        cout<<u.x<<" "<<u.y<<"\n";
 
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
