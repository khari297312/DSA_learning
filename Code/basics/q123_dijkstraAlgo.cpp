#include <iostream>
#include <vector>
#include<set>
#include<limits.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> edges,int n,int s){
    //create adjlist
    vector<vector<pair<int,int>>> adjlist(n,vector<pair<int,int>>{});
    for(auto i:edges){adjlist[i[0]].push_back({i[1],i[2]});adjlist[i[1]].push_back({i[0],i[2]});}
    //print adjlist
    for(auto i:adjlist){for(auto j:i){cout<<"("<<j.first<<","<<j.second<<")";}cout<<endl;}cout<<endl;

    vector<int> dist(n,INT_MAX);
    dist[s]=0;
    set<pair<int,int>> st;
    st.insert({0,s});
    while(!st.empty()){
        auto it=st.begin();
        int node=it->second;
        int distNode=it->first;
        st.erase(it);
        for(auto i:adjlist[node]){
            if(dist[i.first]>distNode+i.second){
                if(dist[i.first]!=INT_MAX){
                    st.erase(st.find({dist[i.first],i.first}));
                }
                dist[i.first]=distNode+i.second;
                st.insert({dist[i.first],i.first});
            }
        }
    }
    return dist;
}
int main() {
    //dijkstra algorithm is used to find shortest path in weighted graph
    //time complexity: O(ElogV) where V is no of vertices
    //space complexity: O(V)
    vector<vector<int>> edges={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,8,2},{2,5,4},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}};
    vector<int> ans=dijkstra(edges,9,2);
    for(auto i:ans){cout<<i<<" ";}cout<<endl;
    return 0;
}