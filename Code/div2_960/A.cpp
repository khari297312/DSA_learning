#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

string solve(){
   int n;
   cin >> n;
   unordered_map<int, int> mp;
   for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    for(auto it:mp){
        if(it.second & 1){
            return "YES";
        }
    }
    return "NO";
   
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--){
       cout<<solve()<<endl;
   }
}