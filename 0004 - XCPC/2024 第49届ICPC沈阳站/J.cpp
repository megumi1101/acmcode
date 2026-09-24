#include<iostream>
#include<algorithm>
using namespace std;
string s,up,down;
int main(){
    int t,upmaxn=-1,downmaxn=-1;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    for(int i=0;i<4;++i){
        cin>>s>>t;
        if(upmaxn<t) upmaxn=t,up=s;
    }
    for(int i=0;i<4;++i){
        cin>>s>>t;
        if(downmaxn<t) downmaxn=t,down=s;
    }
    if(upmaxn>downmaxn) cout<<up+" beats "+down;
    else cout<<down+" beats "+up;
    return 0;
}
