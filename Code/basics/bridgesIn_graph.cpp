#include<bits/stdc++.h>
//#include<iostream>
//#include<vector>
using namespace std;
//like finding the bridges in the graph 
    void dfs(vector<vector<int>>& adj,int node,vector<int>& discoveryTime,vector<int>& lowTime,vector<bool> visited,vector<vector<int>> & bridges,int& time){
        visited[node]=1;
        discoveryTime[node]=time;
        lowTime[node]=time;
        for(int neigh:adj[node]){
            if(visited[neigh]){
                lowTime[node]=min(lowTime[node],lowTime[neigh]);
            }
            dfs(adj,neigh,discoveryTime,lowTime,visited,bridges,++time);
            if(lowTime[neigh]>=lowTime[node]){
                bridges.push_back({neigh,node});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>{});
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> discoveryTime(n,0);
        vector<int> lowTime(n,0);
        vector<bool> visited(n,0);
        vector<vector<int>> bridges;
        int time=0;
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            dfs(adj,i,discoveryTime,lowTime,visited,bridges,time);
        }

    }
int main() {
    // Your code here
    return 0;
}