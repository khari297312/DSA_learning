#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a, int n) {
    if(n<=2) return 1;
    vector<bool> visited(n,0);
    visited[a[0]]=1;
    for (int i=1;i<n;i++) {
        int seat=a[i];
        if (visited[seat-1]==0 && visited[seat+1] == 0) {
            return 0;
        }
        visited[seat]=1;
    }
    return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<(solve(a,n)?"YES":"NO")<<endl;
    }
    
    return 0;
}
