#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n;string s;
        int ns=0,nw=0,ne=0,nn=0;
        cin>>n>>s;
        s=' '+s;
        for(int i=1;i<=n;i++) {
            if(s[i]=='W')nw++;
            if(s[i]=='E')ne++;
            if(s[i]=='S')ns++;
            if(s[i]=='N')nn++;
        }
        if((nw+ne)%2||(nn+ns)%2) {
            cout<<"NO\n";
            return;
        }
        
        int x=min(nw,ne);
        int y=min(ns,nn);
        for(int i=1;i<=n;i++) {
            if(s[i]=='W'&&x) {
                if(x%2)s[i]='R';
                else s[i]='H';
                x--; 
            }
            if(s[i]=='S'&&y) {
                if(y%2)s[i]='H';
                else s[i]='R';
                y--; 
            }
        }
        x=min(nw,ne);
        y=min(ns,nn);
        for(int i=1;i<=n;i++) {
            if(s[i]=='E'&&x) {
                if(x%2)s[i]='R';
                else s[i]='H';
                x--; 
            }
            if(s[i]=='N'&&y) {
                if(y%2)s[i]='H';
                else s[i]='R';
                y--; 
            }
        }
 
        x=abs(nw-ne)/2;
        y=abs(nn-ns)/2;
        for(int i=1;i<=n;i++) {
            if(s[i]=='E'&&x)s[i]='R',x--; 
            if(s[i]=='N'&&y)s[i]='R',y--;
            if(s[i]=='W'&&x)s[i]='R',x--; 
            if(s[i]=='S'&&y)s[i]='R',y--;
        }
        x=abs(nw-ne)/2;
        y=abs(nn-ns)/2;
        for(int i=1;i<=n;i++) {
            if(s[i]=='E'&&x)s[i]='H',x--; 
            if(s[i]=='N'&&y)s[i]='H',y--;
            if(s[i]=='W'&&x)s[i]='H',x--; 
            if(s[i]=='S'&&y)s[i]='H',y--;
        }
        bool fg1=0,fg2=0;
        for(int i=1;i<=n;i++) {
            if(s[i]=='H')fg1=1;
            if(s[i]=='R')fg2=1;
        }
        if(fg1==0||fg2==0) {
            cout<<"NO\n";
            return;
        }
        for(int i=1;i<=n;i++)cout<<s[i];
        cout<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
