#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;
    int solve(vector<int>& arr,int M,bool alice,int index){
        if(index>=arr.size()){return 0;}


        int maxi=0;
        if(alice){
            for(int x=M;x<=2*M;x++){
                M=max(M,x);
                int ans=0;
                if(index+x<arr.size())ans=arr[index+x]-arr[index];
                ans+=solve(arr,M,!alice,index+x);
                maxi=max(ans,maxi);
            }
        }
        else[
            
        ]
        return maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> arr(n+1,0);
        for(int i=1;i<n;i++){
            piles[i]+=piles[i-1];
        }
        for(int i=1;i<=n;i++){
            arr[i]=piles[i-1];
        }
        return solve(arr,1,1,0);
    }
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> arr={2,7,9,4,4};
    return stoneGameII(arr);
    return 0;
}