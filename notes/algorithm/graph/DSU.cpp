class DSU {
    vector<int> parent, rank;  // or size, depending on strategy

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;  // each node is its own parent
    }

    // find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;  // already in same set

        // attach smaller rank tree under larger rank tree
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;  // increase rank if both equal
        }
    }
};

int main() {
    DSU dsu(5); // elements: 0,1,2,3,4

    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(1, 2);

    cout << (dsu.find(0) == dsu.find(3)) << endl; // prints 1 (true)
    cout << (dsu.find(0) == dsu.find(4)) << endl; // prints 0 (false)
}

// Alternative: Union by size (instead of rank)
// size of each set instead of rank.

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
};



// Option3: without rank and size 
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i
    }
}






/*

DSU (Disjoint Set Union), also known as Union-Find — one of the most fundamental data structures for graphs and connectivity problems.
It helps manage a collection of disjoint (non-overlapping) sets and efficiently supports:

find(x) → Find the representative (parent) of the set containing x.

union(x, y) → Merge the sets containing x and y.

It’s heavily used in:

Connected components

Kruskal’s MST

Detecting cycles in undirected graphs

Dynamic connectivity

*/