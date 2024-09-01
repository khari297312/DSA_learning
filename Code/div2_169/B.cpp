#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

int solve(){
    int l,r,L,R;
    cin>>l>>r>>L>>R;
    if(r<L-1){return 0;}
    if(R<l-1){return 0;}
    if(R==r){return r-max(L,l)+1;}
    if(l==L){return min(R,r)-l+1;}
    if(R>r){
        return r-max(L,l)+2;
    }
    if(R<r and R>l){
        return R-max(L,l)+2;
    }
    if(R==l or r==L){
        return 2;
    }
return 0;
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