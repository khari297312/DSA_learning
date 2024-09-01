#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    ll l,r;
    cin >> l >> r;
    ll count=-1;
    ll num=1;
    while(num<=r){
        count++;
        num*=2;
    }
    cout<<count<<endl;
    
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