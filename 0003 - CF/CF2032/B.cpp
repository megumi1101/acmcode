#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    priority_queue<int, vector<int>, greater<int>> q1,q2;
    void sol() {
        int n,k;
        cin>>n>>k;
        if(n==1) {
            cout<<"1\n1\n";
            return;
        }
        if(k==1||k==n) {
            cout<<"-1\n";
            return;
        }
        else {
            if(k&1) {
                cout<<"5\n";
                cout<<"1 2 "<<k<<" "<<k+1<<" "<<k+2<<"\n"; 
            }
            else {
                cout<<"3\n";
                cout<<"1 "<<k<<" "<<k+1<<"\n";
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
}
int main() {
    return xbbbz::main(), 0;
}
