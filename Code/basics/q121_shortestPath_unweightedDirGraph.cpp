#include <iostream>
#include <vector>
#include<limits.h>
#include<queue>
#include<algorithm>
using namespace std;

void solve(vector<vector<int>> adjlist,int n,int s,int t,vector<bool> visited,vector<vector<int>>& ans,vector<int>&  temp){
	if(s==t){ans.push_back(temp);return ;}
	for(auto i:adjlist[s]){
          if (!visited[i]) {
            temp.push_back(i);
            visited[i] = 1;
            solve(adjlist, n, i, t, visited, ans, temp);
            temp.pop_back();
            visited[i] = 0;
          }
        }
}

//approach 1: using backtracking
//time complexity: O(n^m) where n is no of nodes and m is no of edges
//space complexity: O(n)
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//create adjlist
	vector<vector<int>> adjlist(n,vector<int>{});
	for(int i=0;i<m;i++){int u=edges[i].first-1,v=edges[i].second-1;adjlist[u].push_back(v);adjlist[v].push_back(u);}
    //print adjlist
    // cout<<"Adjacency List: "<<endl;for(auto i:adjlist){for(auto j:i){cout<<j+1<<" ";}cout<<endl;}
	//create visited
	vector<bool> visited(n,0);
	vector<vector<int>> ans;
	vector<int> temp={s-1};
	visited[s-1]=1;
	solve(adjlist,n,s-1,t-1,visited,ans,temp);
	int minIndex=0;
	int minPath=INT_MAX;
	for(int i=0;i<ans.size();i++){
		if(minPath>ans[i].size()){minIndex=i;minPath=ans[i].size();}
	}
    // cout<<"no of paths: "<<ans.size()<<endl;
    // cout<<"All paths: "<<endl;
    // for(auto i:ans){for(auto j:i){cout<<j+1<<" ";}cout<<endl;}
	return ans[minIndex];
	
}


//approach 2: using bfs
//this is the most optimized approaach to find shortest path in unweighted graph
//time complexity: O(V+E) where V is no of vertices and E is no of edges
//space complexity: O(V)
vector<int> shortestPathBFS(vector<pair<int,int>> edges , int n , int m, int s , int t){
    //create adjlist
    vector<vector<int>> adjlist(n,vector<int>{});
    for(int i=0;i<m;i++){int u=edges[i].first-1,v=edges[i].second-1;adjlist[u].push_back(v);adjlist[v].push_back(u);}
    vector<bool> visited(n,0);
    vector<int> parent(n,-1);
    queue<int> q;
    bool cond=0;
    q.push(s-1);
    visited[s-1]=1;
    while(!q.empty()){
        int val=q.front();
        q.pop();
        for(auto i:adjlist[val]){
            if(!visited[i]){
                visited[i]=1;
                parent[i]=val;
                if(i==t-1){cond=1;break;}
                q.push(i);
            }
        }
        if(cond){break;}
    }
    vector<int> ans;
    int temp=t-1;
    while(temp!=-1){
        ans.push_back(temp+1);
        temp=parent[temp];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
vector<pair<int,int>> edge={{1,2},{1,3},{1,4},{2,5},{3,8},{4,6},{5,8},{6,7},{7,8}};
vector<pair<int,int>> edges={{1,2},{2,3},{3,4},{1,3}};
vector<int> ans=shortestPath(edges,4,4,1,4);
cout<<"shortest path between 1 and 8: ";
for(auto i:ans){cout<<i+1<<" ";}cout<<endl;

vector<int> ans1=shortestPathBFS(edge,8,9,1,8);
cout<<"shortest path between 1 and 8: ";
for(auto i:ans1){cout<<i<<" ";}cout<<endl;
    return 0;
}