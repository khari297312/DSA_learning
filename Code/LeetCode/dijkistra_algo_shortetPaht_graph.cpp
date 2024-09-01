#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //dijikstra algorithm
    int n=6;
    vector<vector<pair<int,int>>> adj={
        {{1,6},{2,2}},
        {{2,3},{3,7}},
        {{4,4}},
        {{4,5},{5,2}},
        {{5.9}}
    };
    vector<int> dist(n,INT_MAX);
    vector<bool> vis(n,false);
    dist[0]=0;
    
    //we can use priority queue to find the minimum distance node
    //priority queue is used to find the minimum distance node in O(logn) time
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        //if already find the minimum distance of this node then continueq
        if(vis[node])continue;
        vis[node]=true;
        for(auto neigh:adj[node]){
            //if already visited then continue
            if(vis[neigh.first])continue;
            //if the distance of this node is greater than the distance of the current node + the distance between the current node and this node
            //then update the distance of this node
            if(dist[neigh.first]>dist[node]+neigh.second){
                dist[neigh.first]=dist[node]+neigh.second;
                pq.push({dist[neigh.first],neigh.first});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}