#include<bits/stdc++.h>
using namespace std;
int x1,x2,y11,y22;
int T;
bool check(int x,int y,int type)
{
    if(type==1&&x1==x2-1&&y11==y22) return true;
    if(type==2&&y11==y22+1&&x1==x2) return true;
    if(type==3&&x1==x2+1&&y11==y22) return true;
    if(type==4&&y11==y22-1&&x1==x2) return true;

    if(x==x2&&y==y22) return false;
    if(x<1||x>9||y<1||y>10) return true;
    if(x==x2||y==y22) return true;
    return false;
}
void sol()
{
    cin>>x1>>y11>>x2>>y22;

    if(check(x1+1,y11+2,4)&&check(x1+1,y11-2,2)&&check(x1+2,y11+1,1)&&check(x1+2,y11-1,1)
    &&check(x1-1,y11-2,2)&&check(x1-1,y11+2,4)&&check(x1-2,y11-1,3)&&check(x1-2,y11+1,3))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
2
1 5 2 5
1 1 2 3
*/