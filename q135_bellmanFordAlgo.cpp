#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int bellmanFord(int n,vector<vector<int>> edges,int src,int dest){
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(--n){
        for(auto i:edges){
            int u=i[0],v=i[1],wt=i[2];
            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(auto i:edges){
        int u=i[0],v=i[1],wt=i[2];
        if((dist[u]+wt<dist[v]) and dist[u]!=INT_MAX){
            cout<<"Negative cycle present"<<endl;
            return -1;
        }
    }
    return dist[dest];


}
int main() {
    //dijkstra's algorithm is not applicable for negative weights
    //bellman ford algorithm is used for negative weights and it is slower than dijkstra's algorithm
    //this algo is applied to directed and undirected graph and no negative cycle should be present

    //time complexity is O(V*E)
    //space complexity is O(V)
    //where V is the number of vertices and E is the number of edges
    int n=5;
    vector<vector<int>> edges={{0,1,1},{1,2,1},{2,3,1},{3,4,1},{4,0,-3}};
    cout<<bellmanFord(n,edges,0,4)<<endl;

    return 0;
}