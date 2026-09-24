#include<bits/stdc++.h>
using namespace std;


namespace xbbbz {
    #define int long long
    const int N = 10510;
    int n;
    int count;
    int ch[N][26], cnt[N], ne[N];
    int ans[N];
    void add(string s) {
        int u = 0;
        for(int i=0;i<s.size();i++) {
            int v = s[i] - 'a';
            if(!ch[u][v]) ch[u][v] = ++count;
            u = ch[u][v];
            if(i==s.size()-1)cnt[u]++;
        }
    }
    int find(string s) {
        int u = 0;
        int x = 0;
        for(int i=0;i<s.size();i++) {
            int v = s[i] - 'a';
            u = ch[u][v];
            if(i==s.size()-1)x = ans[u];
        }
        return x;
    }
    void build() {
        queue<int> q;
        for(int i=0;i<26;i++) {
            if(ch[0][i])q.push(ch[0][i]);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i=0;i<26;i++) {
                int v = ch[u][i];
                if(v)ne[v] = ch[ne[u]][i], q.push(v);
                else ch[u][i] = ch[ne[u]][i];
            }
        }
    }
    void cx(string s) {
        int u=0;
        for(int i=0;i<s.size();i++) {
            u=ch[u][s[i]-'a'];
            for(int j=u;j;j=ne[j]) {
                ans[j]+=cnt[j];  
            }
        }
    }    
    void sol() {
        memset(ch,0,sizeof(ch));
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));
        memset(ne,0,sizeof(ne));
        count=0;
        int tmp=0;
        string ss[n+5];
        for(int i=1;i<=n;i++) {
            cin>>ss[i];
            add(ss[i]);
        }
        build();
        string s;
        cin>>s;
        cx(s);
        for(int i=1;i<=n;i++) {
            tmp=max(tmp, find(ss[i]));
        }
        cout<<tmp<<"\n";
        for(int i=1;i<=n;i++) {
            if(find(ss[i])==tmp)cout<<ss[i]<<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        while(cin>>n) {
            if(!n)break;
            sol();
        }
    }
    #undef int 
}

int main() {
    return xbbbz::main(), 0;
}