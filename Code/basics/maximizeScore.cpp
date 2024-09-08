#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findmedian(vector<ll> a,ll n){ 
    sort(a.begin(),a.end());
    ll median; 
    if(n%2==0){median=a[(n-1)/2];}
    else{median=(a[n/2]+a[n/2-1])/2;}

    return median+a[n-1];
}
ll solve(vector<ll> a,vector<ll> &b,ll i,ll k,ll n){
    if(k==0 or i==n){return findmedian(a,n);}


    if(b[i]==0){return solve(a,b,i+1,k,n);}

    ll ans1=solve(a,b,i+1,k,n);
    a[i]++;
    ll ans2=solve(a,b,i,k-1,n);
    return max(ans1,ans2);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++){cin>>a[i];}
        for(ll i=0;i<n;i++){cin>>b[i];}
        cout<<solve(a,b,0,k,n)<<endl;
    }
}