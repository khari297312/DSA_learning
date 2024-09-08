#include<bits/stdc++.h>
//#include<iostream>
//#include<vector>
using namespace std;
//we have to find the number of the articulation points in the graph 


void articulationPoint(vector<vector<int>>& grid, int x, int y, int parent, vector<vector<int>>& visited, vector<vector<int>>& disc, vector<vector<int>>& low, int& articulation_point, int& time) {
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    visited[x][y] = 1;
    disc[x][y] = low[x][y] = ++time;

    int children = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() or grid[nx][ny]==0) {   continue;
        }
        if (!visited[nx][ny]) {
            children++;
            articulationPoint(grid, nx, ny, x * grid[0].size() + y, visited, disc, low, articulation_point, time);

            low[x][y] = min(low[x][y], low[nx][ny]);

            if (parent != -1 && low[nx][ny] >= disc[x][y]) {articulation_point++;}
            if (parent == -1 && children > 1) {articulation_point++;}

        } else if ((nx != parent / grid[0].size() || ny != parent % grid[0].size())) {
            low[x][y] = min(low[x][y], disc[nx][ny]);
        }
    }
}
void dfs(vector<vector<int>>& grid,int x,int y,int& count){
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        grid[x][y]=2;
        count++;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            bool check =(nx>=grid.size() or ny>=grid[0].size() or ny<0 or nx<0 or grid[nx][ny]!=1);
            if(check){continue;}
            dfs(grid,nx,ny,count);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int disconnected=-1;
        int count1=0;
        int rootx=-1,rooty=-1;
        //running dfs to check that is there any disconnected compontent is there or not 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rootx=i;rooty=j;
                    dfs(grid,i,j,count1);
                    disconnected++;
                }

            }
        }
        //if there is no ones in the grid --> no island return 0;
        if(count1==0)return 0;
        //if there is more than 1 disconnected graph return 0, as alreday disconnected
        if(disconnected>0){return 0;}
        

        //if whole island is connected,then we consider some base cases, like 1 land ,2 land islands
        if(count1==1){return 1;}
        if(count1==2){return 2;}
        
        //if above condition doesn't staisfy then we find the number of articulation point 
        //if articulation point present  then we return 1 ,else whole grpah is in one cycle 
        //else we require 2 points to break the cycle in two parts
        int articulation_point=0,time=0;
  
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> disc(n, vector<int>(m, -1));
        vector<vector<int>> low(n, vector<int>(m, -1));
        articulationPoint(grid, rootx, rooty, -1, visited, disc, low, articulation_point, time);
        if(articulation_point==0)return 2;
        return 1;

    }
int main() {
    // [[1,1,0,1,1],[1,1,1,1,1],[1,1,0,1,1],[1,1,0,1,1]]
    vector<vector<int>> grid={{1,1,0,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,0,1,1}};
    cout<<minDays(grid);
    return 0;   
}