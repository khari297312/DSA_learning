#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

ll solve(){
    ll l,r;
    cin>>l>>r;
    ll step=1;
    ll num=l;
    while(num<=r){
        num+=step;
        step++;
    }
    return step-1;
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}