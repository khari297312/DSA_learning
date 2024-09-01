#include <bits/stdc++.h>
using namespace std;
static bool cp1(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            pq.push({min(a,b),max(a,b)});
        }

        int ans=0;
        while(k--){
            auto i=pq.top();
            pq.pop();
            int a=i.first,b=i.second;

            ans+=min(a,b);

            if(a>b)a--;
            else b--;

            if(a==0 or b==0)continue;

            pq.push({min(a,b),max(a,b)});
        }
        cout<<ans<<endl;
    }
}