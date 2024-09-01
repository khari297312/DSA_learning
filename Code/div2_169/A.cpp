#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

string solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    if(n >=3) {return "NO";}
    if(abs(a[0]-a[1])>1){return "YES";}
    return "NO";
    
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