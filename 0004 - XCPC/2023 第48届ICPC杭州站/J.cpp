#include<bits/stdc++.h>
using namespace std;
int T,rep,n;
void ask(int x,int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>rep;
}
void sol()
{
    cin>>n;
    int x=0,y=0;
    for (int i=1;i<=n;i+=2)
    {
        int t=i+1;
        if(i==n) t=n-1;
        ask(i,t);
        if(rep==1) x=i,y=t;
    }
    if(x==0)
    {
        cout<<"! "<<1<<endl;
        return;
    }
    int t1=0,t2=0;
    for (int i=1;i<=n;i++)
        if(i!=x&&i!=y)
        {
            t1=i;
            break;
        }
    for (int i=1;i<=n;i++)
        if(i!=x&&i!=y&&i!=t1)
        {
            t2=i;
            break;
        }
    ask(x,t1);
    if(rep==1)
    {
        ask(x,t2);
        if(rep==1) cout<<"! 2"<<endl;
        else cout<<"! 1"<<endl;
    }
    else
    {
        ask(y,t1);
        if(rep==1)
        {
            ask(y,t2);
            if(rep==0) cout<<"! 1"<<endl;
            else cout<<"! 2"<<endl;
        }
        else cout<<"! 1"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}