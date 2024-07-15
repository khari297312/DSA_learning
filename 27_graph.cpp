#include <iostream>
#include <vector>
using namespace std;
//creation of graph using adjacency list
//adjacency list is a collection of linked lists
//each node of the linked list represents the vertex of the graph
//each linked list contains the vertices which are adjacent to the vertex
//adjacency list is used to represent the graph


//implementation of graph using adjacency list
class graph{
    int V;
    vector<int> *l;
public:
    graph(int v){
        V=v;
        l=new vector<int>[V];
    }
    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void removeEdge(int u,int v,bool bidir=true){
        vector<int> list=l[u];
        for(int i=0;i<list.size();i++){
            if(list[i]==v){
                l[u].erase(l[u].begin()+i);
                break;
            }
        }
        if(bidir){
            list=l[v];
            for(int i=0;i<list.size();i++){
                if(list[i]==u){
                    l[v].erase(l[v].begin()+i);
                    break;
                }
            }
        }
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(auto j:l[i]){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};



//implementation of graph using adjacency matrix
class graph1{
    int V;
    vector<vector<int>> adj;
    public:
    graph1(int v){
        V=v;
        adj=vector<vector<int>>(V,vector<int>(V,0));
    }
    void addEdge(int u,int v,bool biDir=true){
        adj[u][v]=1;
        if(biDir){
            adj[v][u]=1;
        }
    }
    void removeEdge(int u,int v,bool biDir=true){
        adj[u][v]=0;
        if(biDir){
            adj[v][u]=0;
        }
    }
    void print(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3); 
    g.addEdge(3,2);
    g.print();
    g.removeEdge(0,1);
    g.print();
    //graph is type of data structure which consist of nodes and edges
    //nodes are the vertices of the graph
    //edges are the connections between the vertices
    //two types of graphs:
    //1. Directed Graph: in which edges have direction
    //2. Undirected Graph: in which edges have no direction
    //node contains any data type
    //edge for connecting the nodes
    //indegree(node) is the number of edges coming to the node
    //outdegree(node) is the number of edges going out of the node
    
    //weighted graph: in which edges have weights
    //path in the graph is the sequence of vertices in which each vertex is connected to the next vertex by an edge
    //cyclic graph: in which there is a cycle in the graph
    //acyclic graph: in which there is no cycle in the graph



    graph1* g1=new graph1(4);
    g1->addEdge(0,1);
    g1->addEdge(0,2);
    g1->addEdge(0,3);
    g1->addEdge(1,3);
    g1->addEdge(3,2);
    g1->print();

    return 0;
}