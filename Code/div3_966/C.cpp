#include <bits/stdc++.h>
using namespace std;
bool temp(string &s,vector<int>& a,int n){
    if(s.length()!=n)return 0;
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]=a[i];
        }else{
            if(mp[s[i]]!=a[i])return 0;
        }
    }
    unordered_map<int,char> mp1;
    for(int i=0;i<n;i++){
        if(mp1.find(a[i])==mp1.end()){
            mp1[a[i]]=s[i];
        }else{
            if(mp1[a[i]]!=s[i])return 0;
        }
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        cout<<(temp(s,a,n)?"YES":"NO")<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}