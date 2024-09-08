#include<bits/stdc++.h>
//#include<iostream>
//#include<vector>
using namespace std;
// it is like finding the maximum depth of the graph ,intution is that we must use bfs,
// it is not that as it is looking , because there can be many rotten oranges and we have to find the minimum time to get all fresh oranges rotten   
// to find the maximum depth of the graph consider all the root nodes at the same time and then apply bfs
    int bfs(vector<vector<int>>& grid){
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        queue<pair<int,int>> q;
        int level=-1;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)count++;
                if(grid[i][j]==2){q.push({i,j});grid[i][j]=3;}
            }
        }
        if(count==0)return 0;
        while(!q.empty()){
            level++;
            int qsize=q.size();
            while(qsize--){
                pair<int,int> node=q.front();
                q.pop();
                if(node.first==-1){level++;continue;}
                int x=node.first,y=node.second;
                bool flag=0;
                for(int i=0;i<4;i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() or grid[nx][ny]!=1) {continue;}
                    q.push({nx,ny});
                    grid[nx][ny]=3;
                }
            }
        }

        for(auto i:grid){for(auto j:i){if(j==1)return -1;}}
        return level;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //applying bfs to find the maximum depth of graph
        return bfs(grid);

    }
int main() {
    // Your code here
    return 0;
}