#include <bits/stdc++.h>

using namespace std;

class Graph {
    private:
    int vertex;
    public:
    Graph(int v){
        vertex = v;
    }
    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int u, int v);
    void dfs(int v);
    int noOfVertex(){
        return vertex;
    }
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::dfs(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin(); it!=adj[v].end();++it) {
        if(!visited[*it]) dfs(*it);
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"DFS Graph Traversal"<<"\n";
    for(int i=0;i<g.noOfVertex();i++) {
        if (!g.visited[i])
        g.dfs(i);
    } 
    return 0;
}