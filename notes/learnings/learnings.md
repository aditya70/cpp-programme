
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq(k); // priority_queue does not have a constructor that takes an integer k.
Default constructor: priority_queue<T, Container, Compare> pq;
From a container: priority_queue<T, Container, Compare> pq(Container &c, Compare comp);

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
Then push all elements. If you want to limit the heap to size k, do it manually:
for (auto& [x,y] : f) {
    pq.push({x,y});
    if (pq.size() > k) pq.pop();
}

```
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        // min heap for heap - it's opposite to vector,set where it is descending order
        return a.second>b.second;
    }
};
```

- priority_queue<ListNode*, vector<ListNode*>, cmp> pq;