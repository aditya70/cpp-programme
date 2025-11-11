### Graph Notes
For a component with v vertices, a complete component should have
exactly v*(v - 1)/2 edges.

```
Graph type	Algorithm	Works?	Why
Unweighted (edges = 1)	BFS	✅	Each edge cost = 1
Weighted (positive, varying)	Dijkstra	✅	Accounts for different weights
Weighted (0/1 edges)	0-1 BFS	✅	Optimized variant using deque
Weighted (negative)	Bellman–Ford	✅	Handles negatives
Weighted (mixed, with cycles)	❌ BFS	❌ Doesn’t consider weights	
💡 Key takeaway

BFS is a shortest-path algorithm for graphs where edge weights are all equal.
For unequal weights, switch to Dijkstra (non-negative) or Bellman-Ford (allowing negatives).

Yes, you can use BFS for both directed and undirected graphs —
as long as the graph is unweighted (or all edge weights are equal).

Graph Type	Works with BFS?	Notes
Undirected	✅	Add edges both ways
Directed	✅	BFS follows only valid edge directions
Weighted	⚠️ Only if all weights equal (e.g. 1)	
Weighted (different weights)	❌ Use Dijkstra instead	
```