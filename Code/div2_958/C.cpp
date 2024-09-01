#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

//brtue force
// void solve(){
//     ll n;
//     cin >> n;
//     vector<ll> ans;
//     ll j=n;
//     ans.push_back(n);
//     for(ll i=n-1;i>=1;i--){
//         if((j | i) == n){
//             j = i;
//             ans.push_back(i);
//         }
//     }
//     cout<<ans.size()<<endl;
//     for(ll i=ans.size()-1;i>=0;i--){
//         cout<<ans[i]<<' ';
//     }
//     cout<<endl;
// }


void solve(){
    ll n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(n);
    ll k=log2(n);
    ll x=1;
    for(ll i=0;i<=k;i++){
        if((n & (x<<i))!=0){
            if((n^(x<<i))==0){break;}
            ans.push_back(n^(x<<i));
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<' ';
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