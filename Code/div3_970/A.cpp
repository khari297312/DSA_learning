#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

string solve(){
    int a,b;
    cin>>a>>b;
    if(!(a&1) and !(b&1)){return "YES";}
    else if((a&1) and !(b&1)){return "NO";}
    else if(!(a&1) and (b&1)){
        if(a<2)return "NO";
        else return "YES";
    }
    else if((a&1) and (b&1)){return "NO";}
    
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