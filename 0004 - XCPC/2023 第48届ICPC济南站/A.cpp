// QOJ user: xbbbz
// Contest: 2023 ç¬?8å±ŠICPCæµå—ç«?// Problem: #7894. Many Many Heads (7894)
// Submission: https://qoj.ac/submission/1454779
// Language: C++14

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
    char now;
    int cnt0,cnt1;
    node(char now_='\0') :now(now_),cnt0(0),cnt1(0) {}
};
stack<node> st;
string s;
int main(){
    int T;
    bool flag;
    node temp;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        while(!st.empty()) st.pop();
        cin>>s,flag=false;
        for(int i=0;i<s.size();++i){
            if(s[i]==')') s[i]='(';
            if(s[i]==']') s[i]='[';
        }
        st.push(node());
        for(int i=0;i<s.size();++i){
            // cout<<"i="<<i<<" st.top().now="<<st.top().now<<" s[i]="<<s[i]<<'\n';
            if(st.top().now==s[i]){
                st.pop();
                temp=st.top(),st.pop();
                if(s[i]=='(') ++temp.cnt0;
                else ++temp.cnt1;
                if(temp.cnt0>1||temp.cnt1>1){
                    flag=true;
                    break;
                }
                st.push(temp);
            }
            else st.push(node(s[i]));
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
</code>