#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

int solve(){
   int n, k;
   cin >> n >> k;
   int count=0;
   while(n>1){
        count++;
        n-=(k-1);
   }
   return count; 
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--){
       cout<<solve()<<endl;
   }
   return 0;
}