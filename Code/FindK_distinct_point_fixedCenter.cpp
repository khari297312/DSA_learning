#include <bits/stdc++.h>
using namespace std;
void solve(int xc,int yc,int k){
    if(k%2==1){
        for(int i=1;i<=k;i++){
            cout<<(xc-k/2)+i-1<<' '<<(yc-k/2)+i-1<<endl;
        }
    }

    else{
        for(int i=1;i<=k;i++){
            cout<<(xc-k)+2*i-1<<' '<<(yc-k)+2*i-1<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int xc,yc,k;
        cin>>xc>>yc>>k;
        solve(xc,yc,k);
    }
}