#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

string solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    vector<vector<char>> b(n, vector<char> (m));

    for(int i = 0; i < n; i++) {
        for(int j  = 0;j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j  = 0;j < m; j++){
            cin >> b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        int suma=0,sumb=0;
        for(int j=0;j<m;j++){suma+=(a[i][j]-'0');sumb+=(b[i][j]-'0');}
        if((suma % 3)!=(sumb % 3)){return "NO";}
    }

    for(int j=0;j<m;j++){
        int suma=0,sumb=0;
        for(int i=0;i<n;i++){suma+=(a[i][j]-'0');sumb+=(b[i][j]-'0');}
        if((suma % 3)!=(sumb % 3)){return "NO";}
    }
    return "YES";
    
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