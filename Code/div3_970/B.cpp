#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

string solve(){
    int n;
    cin >> n;
    string s;
    cin>>s;
    int a=ceil(sqrt(n));
    int b=sqrt(n);
    if(a!=b){return "NO";}
    for(int i=0;i<n;i++){
        if(i<a){
            if(s[i]!='1'){return "NO";}
            else{continue;}
        }
        else if(i>=(a*(a-1))){
            if(s[i]!='1'){return "NO";}
            else{continue;}
        }
        else{
            if((((i%a )==0) or ((i%a)==(a-1))) ){
                if(s[i]!='1'){return "NO";}
                else{continue;}
            }
            else if(s[i]!='0'){return "NO";}
        }
    }
    return "YES";
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}