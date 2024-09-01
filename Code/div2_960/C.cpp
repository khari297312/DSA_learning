#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

//brute force
// int solve(){
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int countZero=0;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=a[i];
//     }
//     while(countZero<n){
//         //iterating over all i from 0 to n-1
//         unordered_map<int, int> mp;
//         int maxi=-1;
//         for(int i=0;i<n;i++){
//             if(a[i]==0){
//                 continue;
//             }
//             mp[a[i]]++;
//             bool found = false;
            
//             //this is basic brute force condition 

//             /*for (const auto& pair : mp) {
//                 if (pair.second >= 2) {
//                     found = true;
//                     maxi=max(maxi,pair.first);
//                 }
//             }*/

//             //this is bit more optimized
//             if(a[i]>maxi and mp[a[i]]>=2){
//                 found=true;
//                 maxi=a[i];
//             }

//             if(!found){
//                 if(maxi==-1){
//                     a[i]=0;
//                 countZero++;
//                 }
//                 else{
//                     a[i]=maxi;
//                 }
                
//             }
//         }
//         //add all elements of a to sum
//         for(int i=0;i<n;i++){
//             sum+=a[i];
//         }
//         if(maxi==-1){return sum;}
//     }
//     return sum;
   
// }

ll solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    for(ll i = 0; i < n; i++) {
            cin >> a[i];       
    }
    ll count=2;
    while(count--){
        ll maxi=-1;
        unordered_map<ll, ll> mp;
        for(ll i=0;i<n;i++){
            sum+=a[i];
            if(a[i]==0)continue;
            mp[a[i]]++;
            bool found = false;
            if(a[i]>maxi and mp[a[i]]>=2){
                found=true;
                maxi=a[i];
            }
            if(!found){
                if(maxi==-1){a[i]=0;}
                else {a[i]=maxi;}
            }
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(a[i]==0)break;
        sum+=(a[i]*(n-i));
    }
    return sum;
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