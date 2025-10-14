#include <bits/stdc++.h>

using namespace std;

class Graph {
  int V;
  vector<list<int>> adj;
  public:
    Graph(int v);
    void addEdge(int v, int w);
    void bfs(int s);
    void bfs2(int s);
};

Graph::Graph(int v){
    this->V = v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::bfs(int s){
    vector<bool> visited;
    visited.resize(V,false);
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);

    while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(auto i : adj[s]){
            if (!visited[i]) {
                visited[i]=true;
                queue.push_back(i);
            }
        }
    }
}

void Graph::bfs2(int s){
    bool visited[V];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    visited[s]=true;
    cout<<s<<" ";
    while (!q.empty())
    {
       int f = q.front();
       q.pop();
       for(auto i: adj[f]){
         if (!visited[i]) {
            cout<<i<<" ";
            visited[i]=true;
         }
       }
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
    cout<<"Bfs Traversal Graph "<<"\n";
    g.bfs(2);
    cout<<"\nBfs Traversal Method2 Graph "<<"\n";
    g.bfs(2);
    return 0;
}