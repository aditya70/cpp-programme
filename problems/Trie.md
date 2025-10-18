Here’s a **curated list of LeetCode problems** (from easy → hard) that cover all important Trie patterns 👇

---

## 🟢 **Beginner (Basic Trie Construction)**

These help you build the foundation — insert/search/prefix operations.

1. **[208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)**
   → Classic implementation (insert, search, startsWith).
   🔑 *Focus:* Learn the basic Trie node structure and traversal.

2. **[211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)**
   → Like Trie but with `.` wildcard.
   🔑 *Focus:* DFS in Trie + handling wildcard search.

3. **[648. Replace Words](https://leetcode.com/problems/replace-words/)**
   → Replace words in a sentence with the shortest prefix from a dictionary.
   🔑 *Focus:* Using Trie for efficient prefix lookups.

---

## 🟡 **Intermediate (Word Search + Autocomplete)**

Here you’ll use Trie + DFS/backtracking.

4. **[720. Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)**
   → Find the longest word such that all prefixes exist.
   🔑 *Focus:* Trie + BFS or DFS traversal.

5. **[212. Word Search II](https://leetcode.com/problems/word-search-ii/)**
   → Find all words from a list that appear in a 2D board.
   🔑 *Focus:* Trie + backtracking + pruning.

6. **[677. Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/)**
   → Trie where each node stores a prefix sum.
   🔑 *Focus:* Store aggregate data in Trie nodes.

7. **[820. Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)**
   → Reverse Trie for suffix compression.
   🔑 *Focus:* Build Trie in reverse order.

---

## 🔵 **Advanced (Applications of Trie)**

These combine Trie with bit manipulation or optimization.

8. **[421. Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)**
   → Use bitwise Trie to find max XOR pair.
   🔑 *Focus:* Trie for bits (0/1), not characters.

9. **[1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)**
   → Autocomplete based on prefixes.
   🔑 *Focus:* Lexicographic order + DFS on Trie nodes.

10. **[1032. Stream of Characters](https://leetcode.com/problems/stream-of-characters/)**
    → Reverse Trie for real-time suffix matching.
    🔑 *Focus:* Efficient streaming lookup using reversed Trie.

---

## ⚙️ **Bonus (Good for Google-style interviews)**

11. **[1804. Implement Trie II (Prefix Tree)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)**
    → Enhanced Trie with `countWordsEqualTo` and `countWordsStartingWith`.
    🔑 *Focus:* Storing counts at each node.

12. **[745. Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)**
    → Combine prefix & suffix matching using Trie.
    🔑 *Focus:* Complex Trie structure (e.g. `suffix#prefix` trick).

---

## 💡 Practice Order (Recommended)

If you’re learning systematically:

```
208 ➜ 211 ➜ 648 ➜ 720 ➜ 677 ➜ 212 ➜ 820 ➜ 421 ➜ 1268 ➜ 1032 ➜ 745
```

