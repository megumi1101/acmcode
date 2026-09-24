#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>a>>b>>c>>d;
    for(;a&&b&&c&&d;){
        if(a<=c&&b<=d) return cout<<"Polycarp",0;
        if(c<=a&&d<=b) return cout<<"Vasiliy",0;
        if(a-b==c-d)
            if(a<c) return cout<<"Polycarp",0;
            else return cout<<"Vasiliy",0;
        if(a-b>c-d) --a;
        else --b;
        --c,--d;
        // cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<'\n';
    }
    if(a+b<=c+d-min(c,d)) cout<<"Polycarp";
    else cout<<"Vasiliy";
    return 0;
}
/*
6 1 5 6
*/
