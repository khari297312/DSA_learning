#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    cin >> n;
    //using dfs
    vector<int> queryAns(n,-1);
    for(int i=2;i<=n;i++){
        cout<<"? "<<1<<' '<<i<<endl;
        int r;
        cin>>r;
        queryAns[i-1]=r;
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