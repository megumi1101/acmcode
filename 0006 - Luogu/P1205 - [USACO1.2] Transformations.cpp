#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    int n;
    string zh1(string s){
        string res="";
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                res+=s[i*n+j];
            }
        }
        return res;
    }
    string zh2(string s){
        return zh1(zh1(s));
    }
    string zh3(string s){
        return zh2(zh1(s));
    }
    string ref(string s){
        string res="";
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                res+=s[i*n+j];
            }
        }
        return res;
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        string a,b,s,tmp;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s;
            a+=s;
        }
        for(int i=0;i<n;i++){
            cin>>s;
            b+=s;
        }
        if(b==zh1(a)){puts("1");return;}
        if(b==zh2(a)){puts("2");return;}
        if(b==zh3(a)){puts("3");return;}
        if(b==ref(a)){puts("4");return;}
        if(b==zh1(ref(a))){puts("5");return;}
        if(b==zh2(ref(a))){puts("5");return;}
        if(b==zh3(ref(a))){puts("5");return;}
        if(b==a){puts("6");return;}
        puts("7");return;
    }
}