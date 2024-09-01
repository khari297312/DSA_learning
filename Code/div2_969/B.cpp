#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    ll n,m;
    cin >> n>>m;
    ll maxi=INT_MIN;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        maxi=max(maxi,x);
    }
    vector<ll> a(m);
    for(ll i = 0; i < m; i++) {
        char c;
        cin>>c;
        ll l,r;
        cin>>l>>r;
        if(c == '+'){
            if(maxi<=r and maxi>=l){
                maxi++;
            }
        }
        else if(c == '-'){
            if(maxi>=l and maxi<=r){
                maxi--;
            }
        }
        a[i]=maxi;
    }
    for(ll i = 0; i < m; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}