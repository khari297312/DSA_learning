#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> v(n,vector<ll>(2));
        for(ll i=0;i<n;i++){
            cin>>v[i][0]>>v[i][1];
        }
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        ll i;
        for(i=0;i<n;i++){
            ll dist1=(v[i][0]-x2)*(v[i][0]-x2)+(v[i][1]-y2)*(v[i][1]-y2);
            if(dist1<=dist){break;}
        }
        if(i == n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}