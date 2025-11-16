#include <iostream>
#include <vector>
using namespace std;

/*
Key differences:
Undirected Graph:

Uses a visited array to track visited nodes
A cycle exists if we encounter a visited node that's not the parent
This avoids false positives from the same edge traversed in both directions

Directed Graph:

Uses a state array with 3 values:

0 = unvisited
1 = currently visiting (in recursion stack)
2 = completely visited


A cycle exists if we encounter a node in state 1 (back edge)

Time Complexity: O(V + E) where V is vertices and E is edges
Space Complexity: O(V) for recursion stack and visited/state arrays
*/

// For undirected graph
bool hasCycleUndirected(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(hasCycleUndirected(neighbor, node, visited, adj)) {
                return true;
            }
        }
        // If visited and not parent, then cycle exists
        else if(neighbor != parent) {
            return true;
        }
    }
    return false;
}

// For directed graph
bool hasCycleDirected(int node, vector<int>& state, vector<vector<int>>& adj) {
    state[node] = 1;  // Currently visiting (in recursion stack)
    
    for(int neighbor : adj[node]) {
        if(state[neighbor] == 0) {  // Not visited
            if(hasCycleDirected(neighbor, state, adj)) {
                return true;
            }
        }
        else if(state[neighbor] == 1) {  // Back edge (cycle found)
            return true;
        }
    }
    
    state[node] = 2;  // Completely visited
    return false;
}

int main() {
    // Example 1: Undirected graph with cycle
    vector<vector<int>> adj1(4);
    adj1[0] = {1, 2};
    adj1[1] = {0, 2};
    adj1[2] = {0, 1, 3};
    adj1[3] = {2};
    
    vector<bool> visited(4, false);
    bool cycleUnd = false;
    for(int i = 0; i < 4; i++) {
        if(!visited[i]) {
            if(hasCycleUndirected(i, -1, visited, adj1)) {
                cycleUnd = true;
                break;
            }
        }
    }
    cout << "Undirected graph has cycle: " << (cycleUnd ? "Yes" : "No") << endl;
    
    // Example 2: Directed graph with cycle
    vector<vector<int>> adj2(4);
    adj2[0] = {1};
    adj2[1] = {2};
    adj2[2] = {3, 0};  // Creates cycle: 0->1->2->0
    adj2[3] = {};
    
    vector<int> state(4, 0);  // 0: unvisited, 1: visiting, 2: visited
    bool cycleDir = false;
    for(int i = 0; i < 4; i++) {
        if(state[i] == 0) {
            if(hasCycleDirected(i, state, adj2)) {
                cycleDir = true;
                break;
            }
        }
    }
    cout << "Directed graph has cycle: " << (cycleDir ? "Yes" : "No") << endl;
    
    return 0;
}

