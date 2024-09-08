#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
       if(n<=k and m<=k){cout<<n*m<<endl;}
       else if(n>=k and m>=k){cout<<k*k<<endl;}
       else if(n<k and m>k){cout<<n*(k)<<endl;}
       else if(n>k and m<k){cout<<m*(k)<<endl;}

    }
}