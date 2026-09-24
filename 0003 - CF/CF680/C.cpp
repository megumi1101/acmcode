#include <bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
    const int N = 5e4+5;
    int vis[N], pr[N], cnt=0;
    vector<int>xx;
    void init() {
        int n = 100;
        for(int i=2;i<=n;i++) {
            if(!vis[i])pr[++cnt]=i;
            for(int j=1;j<=cnt&&i*pr[j]<=n;j++) {
                vis[i*pr[j]]=1;
                if(i%pr[j]==0)break;
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        init();
        int res=0;
        string s;
        cout<<"2"<<endl;
        cin>>s;
        if(s[0]=='y') {
            for(int i=1;2*pr[i]<=100;i++) {
                if(i==1)cout<<"4"<<endl;
                else cout<<pr[i]<<endl;
                cin>>s;
                if(s[0]=='y'){cout<<"composite";return;}
            }
        }
        else {
            cout<<"3"<<endl;
            cin>>s;
            if(s[0]=='y') {
                for(int i=2;3*pr[i]<=100;i++) {
                    if(i==2)cout<<"9"<<endl;
                    else cout<<pr[i]<<endl;
                    cin>>s;
                    if(s[0]=='y'){cout<<"composite";return;}
                }
            }
            else {
                cout<<"5"<<endl;
                cin>>s;
                if(s[0]=='y') {
                    for(int i=3;5*pr[i]<=100;i++) {
                        if(i==3)cout<<"25"<<endl;
                        else cout<<pr[i]<<endl;
                        cin>>s;
                        if(s[0]=='y'){cout<<"composite";return;}
                    }
                }
                else {
                    cout<<"7"<<endl;
                    cin>>s;
                    if(s[0]=='y') {
                        for(int i=4;5*pr[i]<=100;i++) {
                            if(i==4)cout<<"49"<<endl;
                            else cout<<pr[i]<<endl;
                            cin>>s;
                            if(s[0]=='y'){cout<<"composite";return;}
                        }
                    }
                }
            }
        }
        cout<<"prime"<<endl;
    }
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}
