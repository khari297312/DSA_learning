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
    int c1=0,c0=0;
    if(s[0]=='0'){c0++;}
    else{c1++;}
    for(int i=1;i<n;i++){
        if(s[i]=='1') c1++;
        else{
            if(s[i-1]=='1'){c0++;}
        }
    }

    return ((c1>c0)?"YES":"NO");
    
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