#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin>>s;
    vector<vector<int>> ans;
    vector<bool> visited(n,0);
    int index=-1;
    for(int i=0;i<n;i++){
        if(visited[i]){continue;}
        int j=i;
        vector<int> arr;
        while(!visited[j]){
            arr.push_back(j);
            visited[j]=1;
            j=a[j]-1;
        }
        ans.push_back(arr);
    }
    vector<int> final(n,0);
    vector<int> count(ans.size(),0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            if(s[ans[i][j]]=='0'){
                count[i]++;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){

            final[ans[i][j]]=count[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<final[i]<<' ';
    }
    cout<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}