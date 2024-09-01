#include<bits/stdc++.h>
using namespace std;

void solve(){
   int n,x,y;
   cin>>n>>x>>y;
    for(int i=0;i<y-1;i++){
        cout<<-1<<" ";
    }
    for(int i=y-1;i<x;i++){
        cout<<1<<" ";
    }
    for(int i=x;i<n;i++){
        cout<<-1<<" ";
    }
    cout<<endl;
}

int main() {
   int t;
   cin>>t;
   while(t--){
       solve();
   }
   return 0;

}