#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    cin >> n;
    if(n==1){cout<<1<<endl;return ;}
    else if(n%2 == 0){cout<<-1<<endl;return ;}
    else{
        for(int i=n;i>=1;i--){
            if((i%2)==1){cout<<i<<' ';}
        }
        for(int i=n;i>=1;i--){
            if((i%2)==0){cout<<i<<' ';}
        }
        cout<<endl;
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