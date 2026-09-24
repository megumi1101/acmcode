// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCé¦™æ¸¯ç«?// Problem: #9917. The Story of Emperor Bie (9917)
// Submission: https://qoj.ac/submission/1573972
// Language: C++23

#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int T,n,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        int ma=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            ma=max(a[i],ma);
        }
        for (int i=1;i<=n;i++)
            if(a[i]==ma)
                cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
</code>