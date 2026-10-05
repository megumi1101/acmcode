#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
bool cmp(int x,int y){return x>y;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int s=0;
    for (int i=1;i<=n;i++)
        if(s>=a[i]) s++;
        else s--;
    cout<<s<<" ";

    s=0;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        if(s>=a[i]) s++;
        else s--;
    cout<<s<<"\n";
    return 0;
}