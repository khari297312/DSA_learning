#include <iostream>
#include <vector>
#include<queue>
#include<limits.h>
using namespace std;
vector<vector<pair<int,int>>> adjl(vector<vector<int>> edges,int n){
    vector<vector<pair<int,int>>> adjlist(n,vector<pair<int,int>>{});
    for(auto i:edges){adjlist[i[0]].push_back({i[1],i[2]});}
    return adjlist;
}

vector<int> indeg(vector<vector<pair<int,int>>> adjlist,int n){
    vector<int> indegree(n,0);
    for(auto i:adjlist){
        for(auto j:i){
            indegree[j.first]++;
        }
    }
    return indegree;
}

vector<int> topsort(vector<vector<pair<int,int>>> adjlist,int n){
    // vector<vector<int>> adjlist=adj(edges,n);
    vector<int> indegree=indeg(adjlist,n);
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){q.push(i);}
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adjlist[node]){
            indegree[i.first]--;
            if(indegree[i.first]==0){q.push(i.first);}
        }
    }
    return ans;
}

vector<int> shortestPath(vector<vector<int>> edges,int n,int s){
    vector<vector<pair<int,int>>> adjlist=adjl(edges,n);
    vector<int> top=topsort(adjlist,n);
    vector<int> dist(n,INT_MAX);
    dist[s]=0;
    int i=0;
    while(top[i]!=s){i++;}

    //edge[i][2] is the weight of edge from edge[i][0] to edge[i][1]
    for(;i<n;i++){
        for(auto j:adjlist[top[i]]){
            if(dist[j.first]>dist[top[i]]+j.second){
                dist[j.first]=dist[top[i]]+j.second;
            }
        }
    }
    return dist;
}




int main() {
    vector<vector<int>> edges={{0,1,5},{0,2,3},{1,2,2},{1,3,6},{2,3,7},{2,4,4},{2,5,2},{3,4,-1},{3,5,1},{4,5,-2}};
    vector<int> ans=shortestPath(edges,6,1);
    for(auto i:ans){cout<<i<<" ";}cout<<endl;
    return 0;
}