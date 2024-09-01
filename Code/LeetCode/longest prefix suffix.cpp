#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;


void solveLPS(string s){
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
    for(auto x:lps){
        cout<<x<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s="abcabdabcabdabdab";
    solveLPS(s);
    return 0;
}