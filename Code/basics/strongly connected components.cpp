#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;


void dfs1(vvi &adj,vi &vis, stack<int> &st,int node){
    vis[node]=1;
    for(auto neigh:adj[node]){
        if(!vis[neigh]){
            dfs1(adj,vis,st,neigh);
        }
    }
    st.push(node);
}
void dfs2(vvi& adj,vi &vis,vi &temp,int node){
    vis[node]=1;
    temp.push_back(node);
    for(auto neigh:adj[node]){
        if(!vis[neigh]){
            dfs2(adj,vis,temp,neigh);
        }
    }
}
void stronglyConnectedComponents(vvi& edges,int n){
    vvi adj(n,vi());
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
    }
    vi vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs1(adj,vis,st,i);
        }
    }
    vvi adjT(n,vi());
    for(int i=0;i<n;i++){
        for(auto neigh:adj[i]){
            adjT[neigh].push_back(i);
        }
    }
    fill(vis.begin(),vis.end(),0);
    vvi ans;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            vi temp;
            dfs2(adjT,vis,temp,node);
            ans.push_back(temp);
        }
    }
    for(auto comp:ans){
        for(auto node:comp){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vvi edges={{0,1},{1,2},{2,0},{2,3},{3,4},{4,5},{5,6},{6,4},{6,7},{4,7}};
    stronglyConnectedComponents(edges,8);

    return 0;
}