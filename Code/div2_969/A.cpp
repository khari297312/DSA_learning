#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    int l,r;
    cin >> l>>r;
    if(l&1 and r&1){
        cout<<((r-l)/2+1)/2<<endl;
    }
    else if(l&1 and !(r&1)){
        cout<<((r-l+1)/2)/2<<endl;
    }
    else if(!(l&1) and r&1){
        cout<<((r-l+1)/2)/2<<endl;
    }
    else{
        cout<<((r-l)/2)/2<<endl;
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}