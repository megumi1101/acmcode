#include <bits/stdc++.h>
using namespace std;

mt19937 rng{std::random_device{}()};

auto random(int n) {
    vector<vector<int>> adj(n+1);
    for (int i = 2; i <= n; ++i){
        int f = rng() % (i - 1) + 1;
        adj[f].push_back(i);
    }
    return adj;
}

bool isok(int n, std::vector<std::vector<int>> adj) {
    for (int msk = 0; msk < (1 << n); ++msk) {
        if (__builtin_popcount(msk) != n / 2) continue;
        int ok = 1;
        std::vector<int> mx(n+1,-114514),mn(n+1, 114514);
        [&](this auto&& dfs, int u) -> void {
            for (int v : adj[u]){
                dfs(v);
                if (mx[u] + mx[v] > 3) ok =0;
                if (mn[u] + mn[v] <-3) ok=0;
                mx[u] = max(mx[u], mx[v] + ((msk >> (u-1) & 1) ? 1 : -1));
                mn[u] = min(mn[u], mn[v] + ((msk >> (u-1) & 1) ? 1 : -1));
            }
            if(mn[u]<-3||mx[u]>3)ok=0;
        }(1);
        if(ok) 
        {
            cout<<msk<<"\n";
            return true;
        }
    }
    return false;
}

int main() {
    int t = 1;
    vector<vector<int>>adj(21);
    while (t--) {
        // int n = (rng() % 10 + 1) << 1;
        // auto adj = random(n);
        int n=20;
        for (int i=1;i<=20;i+=4)
        {
            if(i<17) adj[i+3].push_back(i+4);
            for (int j=i+1;j<=i+3;j++)
                adj[i].push_back(j);
        }
        if (!isok(n, adj)) {
            for (int i = 1; i <= n; ++i) {
                for (int v : adj[i]) {
                    cout<<i<<' ' <<v<<'\n';
                }
            }
            break;
        }else{
            cerr<<n<<" ok\n";
        }
    }
}