#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> roomsTime(n);
        for(int i=0;i<n;i++){
            cin>>roomsTime[i];
        }
        for(int i=1;i<=k;i++){
            bool cond=true;
            for(int j=0;j<n;j++){
                int diff=roomsTime[n-1]+i-roomsTime[j];
                int NoOfCycles=diff/k;
                if(NoOfCycles%2==1){cond=false;break;}
            }
            if(cond){cout<<roomsTime[n-1]+i<<endl;}
        }
        cout<<-1<<endl;
    }
}