#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

int solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    int maxi=INT_MIN;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        mp[a]++;
        maxi=max(maxi,mp[a]);
    }
    
    return n-maxi;
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cout<<"ans;";
        cout<<solve()<<endl;
    }
    return 0;
}