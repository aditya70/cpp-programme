# 🟢 C++ Native Array Cheat Sheet

---

### 1️⃣ Declaration

```cpp
int arr[5];              // size 5, uninitialized // uninitialized (garbage values)
int arr2[5] = {1,2,3,4,5}; // initialize with values
int arr3[] = {10,20,30};  // size inferred (3)
int arr4[5] = {1,2,3};     // partially initialized, rest = 0
```

* Fixed size → must be known at compile time
* Stored on stack by default

---

### 2️⃣ Access Elements

```cpp
arr2[0] = 10;             // assign
int x = arr2[2];          // access
```

* Indexing starts at 0
* Access **O(1)**

---

### 3️⃣ Loops

```cpp
// Forward loop
for(int i = 0; i < 5; i++) cout << arr2[i] << " ";

// Range-based for (C++11)
for(int x : arr2) cout << x << " ";
```

---

### 4️⃣ Size of Array

```cpp
int n = sizeof(arr2)/sizeof(arr2[0]);
cout << n;  // 5
```

* `sizeof(arr)` gives total bytes
* Divide by `sizeof(element)` to get number of elements

---

### 5️⃣ Multi-dimensional Arrays

```cpp
int mat[3][4];                  // 3x4 matrix
int mat2[2][3] = {{1,2,3},{4,5,6}}; // initialization

mat[0][2] = 10;                 // access
```

* Can use nested loops to iterate:

```cpp
for(int i=0;i<3;i++) {
    for(int j=0;j<4;j++)
        cout << mat[i][j] << " ";
    cout << "\n";
}
```

---

### 6️⃣ Common Operations
```cpp
memset (from <cstring>)
int arr[10];
memset(arr, 0, sizeof(arr));   // set all elements to 0
memset(arr, -1, sizeof(arr));  // set all bits to 1 (usually -1 for int)

char str[10];
memset(str, 'A', sizeof(str));  // fill with 'A'

int dp[100][100];
memset(dp, -1, sizeof(dp));  // all elements set to -1

- For values other than 0 or -1, it may not behave as expected for int, long, etc.
- Safe for char or bool arrays
- Prefer memset for small fixed-size arrays
- For vectors or modern C++ containers, use fill or assign instead

int arr[5];
fill(arr, arr+5, 7);   // set all elements to 7

// 2D array (flattened)
int dp[100][100];
fill(&dp[0][0], &dp[0][0] + 100*100, -1);
- Works with arrays and vectors
- Preferred over memset for non-0/-1 values

5️⃣ vector Initialization
#include <vector>
vector<int> v1(5);            // size 5, all 0
vector<int> v2(5, 7);         // size 5, all 7
vector<int> v3 = {1,2,3,4};   // initializer list


Dynamic size → safer than native arrays

Can use fill(v.begin(), v.end(), val)

6️⃣ 2D Arrays / Matrices
int mat[3][4];              // static 2D array
memset(mat, 0, sizeof(mat)); // initialize all to 0

vector<vector<int>> mat2(3, vector<int>(4, 0)); // dynamic 2D vector, all 0

✅ Quick Tips

- memset → fast, for 0 or -1

- fill → safe, any value

- vector → dynamic arrays, safe & STL-friendly

- 2D arrays → flatten for memset, or use vectors

```

```cpp
// Fill with value
fill(arr2, arr2+5, 0);

// Copy array
int arrCopy[5];
copy(arr2, arr2+5, arrCopy);

// Sort
sort(arr2, arr2+5); // requires <algorithm>
```

* Use pointer arithmetic with **begin + end** for STL algorithms

---

### 7️⃣ Passing Arrays to Functions

```cpp
void printArr(int arr[], int n) {  // or int* arr
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

int main() {
    int arr[] = {1,2,3};
    printArr(arr, 3);
}
```

* Arrays decay to pointers when passed → size must be passed separately

---

### 8️⃣ Dynamic Arrays

```cpp
int n = 5;
int* arr = new int[n];  // heap allocation
arr[0] = 10;

delete[] arr;           // free memory
```

* Use **`new` / `delete[]`** for runtime-sized arrays
* Prefer **`vector`** in modern C++ for safety

---

### 9️⃣ Complexity

| Operation | Complexity |
| --------- | ---------- |
| Access    | O(1)       |
| Iteration | O(n)       |
| Fill      | O(n)       |
| Copy      | O(n)       |
| Sort      | O(n log n) |

---

### ✅ Tips for Interviews

1. Fixed size → use stack arrays; dynamic size → use `new` or `vector`.
2. Use `sizeof(arr)/sizeof(arr[0])` to get length in compile-time arrays.
3. For **2D arrays**, nested loops are the easiest way to iterate.
4. Use **STL algorithms** with pointers for modern convenience.
5. Remember **arrays decay to pointers** when passed to functions.

---

If you want, I can make a **complete C++ array cheat sheet** covering:

* 1D, 2D arrays
* Dynamic arrays
* Common operations, sorting, copying, filling
* Pointer arithmetic tricks

This is extremely handy for **interviews and competitive programming**.

Do you want me to make that?
