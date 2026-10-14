#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[64];
void solution() {
    int n, mark = -1;
    long long x, res = 0ll;
    cin >> n, fill(cnt, cnt + 60, 0);

    vector<ll>num(n+5);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        for (int j = 0; j < 60; ++j)
            if (num[i] & (1ll << j)) ++cnt[j];
    }
    // for(int i=59;i>=0;--i) cout<<"i = "<<i<<" cnt[i] = "<<cnt[i]<<'\n';
    for (int i = 59; i >= 0; --i)
        if (cnt[i] > 0) {
            mark = i;
            break;
        }
    if(cnt[mark]%2==1)
    {
        for (int i = 0; i <= mark; ++i)
            if (cnt[i] && (cnt[i] & 1) == (cnt[mark] & 1)) res += (1ll << i);
        cout << res << '\n';
        return;
    }
    ll a[62],bz[62];
    memset(a,0,sizeof(a));
    memset(bz,0,sizeof(bz));

    for (int i=0;i<=mark;i++)
        if(cnt[i]%2==0&&cnt[i])
            bz[i]=1;
    for (int i=1;i<=n;i++)
    {
        ll x=num[i];
        for (int j=60;j>=0;j--)
        {
            if(!bz[j]) continue;
            if(a[j])
            {
                if(x&(1ll<<j)) x^=a[j];
            }
            else
            {
                if(x&(1ll<<j))
                {
                    a[j]=x;
                    break;
                }
            }
        }
    }
    ll ans=0;
    for (int i=60;i>=0;i--)
        if(a[i]&&(ans&(1ll<<i))==0&&bz[i])
            ans^=a[i];
    for (int i=0;i<=60;i++)
        if(!bz[i]&&(ans&(1ll<<i)))
            ans-=(1ll<<i);
    cout<<ans<<"\n";
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}