#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    string s[5];
    int n,num[5],op;
    vector<char>ed[100005];
    int getnum(string s) {
        int res=0;
        for(int i=1;i<=2*n;i++) {
            if(s[i]-'0'==0)res++;
        }
        return (res<=n);
    }
    void sol() {
        cin>>n;
        for(int i=1;i<=3;i++)cin>>s[i],s[i]='a'+s[i];
        for(int i=1;i<=3;i++)num[i]=getnum(s[i]);
        bool fg=0;
        for(int i=1;i<=3&&fg==0;i++) 
            for(int j=1;j<=3;j++)
                if(i!=j&&num[i]==num[j]){
                    string s1 = s[i];
                    string s2 = s[j];
                    s[1]=s1;
                    s[2]=s2;
                    op = num[i];
                    fg=1;
                    break;
                }
        for(int i=1;i<=2;i++) {
            int res=0;
            for(int j=1;j<=2*n;j++) {
                if(s[i][j]==op+'0'&&res<n){res++;continue;}
                else {
                    ed[res].push_back(s[i][j]);
                }
            }
        }
        for(int i=0;i<=n;i++) {
            if(i)putchar('0'+op);
            for(char ch : ed[i]) {
                cout<<ch;
            }
        }
        cout<<"\n";
        for(int i=0;i<=n;i++)ed[i].clear();
    }
    void main() {
        int T;
        cin>>T;
        while(T--)sol();
    }
}
int main() {
    return xbbbz::main(), 0;
}
