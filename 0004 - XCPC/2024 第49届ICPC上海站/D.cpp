// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCä¸Šæµ·ç«?// Problem: #9040. Decrease and Swap (9040)
// Submission: https://qoj.ac/submission/1541574
// Language: C++23

#include<bits/stdc++.h>
using namespace std;
#define N 2000010
int n,T,a[N];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        cin>>s;
        s=" "+s;
        int cnt=0,j=0;
        for (int i=1;i<=n-2;i++)
        {
            if(s[i]=='1') j++;
            if(s[i]=='0')
            {
                if(j) a[++cnt]=1,j--;
                a[++cnt]=0;
            }
        }
        for (int i=1;i<=j;i++) a[++cnt]=1;
        a[n]=s[n]-'0',a[n-1]=s[n-1]-'0';
        // for (int i=1;i<=n;i++) cout<<a[i];cout<<"\n";
        n+=2;
        for (int i=n;i>=3;i--) a[i]=a[i-2];
        a[1]=a[2]=0;
        if(a[n-2]==a[n-3]&&a[n-2]==1||(a[n]==0&&a[n-1]==0)) {cout<<"Yes\n";continue;}
        if(a[n]==a[n-1]&&a[n]==1)// 11
        {
            if(a[n-3]==1) cout<<"Yes\n";
            else if(a[n-4]==1&&a[n-2]==1) cout<<"Yes\n";
            else cout<<"No\n";
        }
        if(a[n]==1&&a[n-1]==0)// 01
        {
            if(a[n-4]==1&&a[n-2]==1) cout<<"Yes\n";
            else cout<<"No\n";
        }
        if(a[n]==0&&a[n-1]==1)// 10
        {
            if(a[n-3]==1||(a[n-4]==1&&a[n-2]==1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}
/*
3
 3
 101
 4
 1010
 5
 00000
*/
</code>