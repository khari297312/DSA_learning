#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;
void solveLPS(string s){
    int n=s.size();
    vector<int> lps(s.size(),0);
    int pre=0,suf=1;
    while(suf<s.size()){
        if(s[pre]==s[suf]){
            lps[suf]=pre+1;
            pre++;suf++;
        }
        else{
            if(pre!=0){
                pre=lps[pre-1];
            }
            else{
                lps[suf]=0;
                suf++;
            }
        }
    }
    if(lps[n-1]==0 or lps[n-1]<=n/2 or lps[n-1]==1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<s.substr(0,lps[n-1])<<endl;
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string t;
    cin>>t;
    solveLPS(t);
    return 0;
}