### Priority Queue Notes
```
Option 1 — Define comparison operator inside the struct
struct Edge {
    int cost, r, c;
    bool operator>(const Edge& other) const {
        return cost > other.cost;  // min-heap by cost
    }
};

Then you can safely do:
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

✅ Works perfectly — simplest and cleanest.

Option 2 — Use a custom lambda comparator
If you don’t want to define operators on Edge, define a comparator inline:
auto cmp = [](const Edge& a, const Edge& b) {
    return a.cost > b.cost;  // min-heap
};
priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);

This avoids modifying your struct, but is slightly more verbose.

Option 3 — Don’t use a struct at all (use tuple/array)
You could store (cost, r, c) as a tuple:
priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
pq.push({grid[0][0], 0, 0});

And access with:
auto [cost, r, c] = pq.top();

This works because std::array and std::tuple already define < and > operators lexicographically.

Option 4 — Define comparator  inside another struct
// cmp is a functor (a struct/class with operator() defined)

struct Edge {
    int cost, r, c;
};

struct cmp {
    bool operator()(const Edge& a, const Edge& b) const {
        return a.cost > b.cost;  // min-heap by cost
    }
};

// ✅ min-heap
priority_queue<Edge, vector<Edge>, cmp> pq;

```
