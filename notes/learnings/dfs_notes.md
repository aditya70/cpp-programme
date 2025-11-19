---
Every recursive DFS that marks something must also unmark it.

✔ visited[x] = true
✔ explore deeper
✔ visited[x] = false ← cleanup

This way each DFS branch gets a clean, correct copy of the state.
---

```
visited[cur] = true;

for (int nxt : choices) {
    if (!visited[nxt]) {
        dfs(nxt);
    }
}

visited[cur] = false;  // <-- IMPORTANT!

```