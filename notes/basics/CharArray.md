C++ char array (C-style string) cheat sheet**.

---

# 🟢 C++ Char Array (C-style String) Cheat Sheet

---

### 1️⃣ Declaration & Initialization

```cpp
char str1[10];               // uninitialized
char str2[10] = "Hello";     // null-terminated
char str3[] = "World";       // size inferred (6 including '\0')
char str4[5] = {'a','b','c','d','\0'}; // explicit null-termination
```

* Always ensure **`'\0'` termination**
* Size must accommodate **null character**

---

### 2️⃣ Access Elements

```cpp
char ch = str2[0];       // 'H'
str2[1] = 'a';           // modify
cout << str2 << endl;    // prints string until '\0'
```

* Access is **O(1)**

---

### 3️⃣ Common Functions (`<cstring>`)

| Function                | Description             | Example                          |
| ----------------------- | ----------------------- | -------------------------------- |
| `strlen(str)`           | Length (excluding '\0') | `int n = strlen(str2);`          |
| `strcpy(dest, src)`     | Copy string             | `strcpy(str1, str2);`            |
| `strncpy(dest, src, n)` | Copy n chars            | `strncpy(str1, str2, 3);`        |
| `strcat(dest, src)`     | Concatenate             | `strcat(str1, " World");`        |
| `strncat(dest, src, n)` | Concatenate n chars     | `strncat(str1, str2, 3);`        |
| `strcmp(str1,str2)`     | Compare                 | `0 = equal, <0 = str1<str2`      |
| `strncmp(str1,str2,n)`  | Compare first n chars   | `0 = equal`                      |
| `memset(arr,val,n)`     | Set n bytes             | `memset(str1, 0, sizeof(str1));` |
| `memcpy(dest, src, n)`  | Copy n bytes            | `memcpy(str1, str2, 5);`         |

---

### 4️⃣ Iteration

```cpp
for(int i = 0; str2[i] != '\0'; i++)
    cout << str2[i] << " ";

for(char *p = str2; *p != '\0'; p++)
    cout << *p << " ";
```

* Can also use pointers: `char* p = str2`

---

### 5️⃣ Conversion Between `char[]` and `string`

```cpp
string s = str2;           // char[] → string
strcpy(str1, s.c_str());   // string → char[] (ensure enough space)
```

---

### 6️⃣ Safety Tips

1. Always **ensure enough space** for null character when copying or concatenating.
2. Prefer `strncpy` / `strncat` over `strcpy` / `strcat` to **avoid buffer overflow**.
3. Initialize arrays with `memset(str, 0, sizeof(str))` if needed.
4. Use `string` in modern C++ unless **C-style array is required**.

---

### 7️⃣ Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char str1[20] = "Hello";
    char str2[] = "World";

    strcat(str1, " ");     // "Hello "
    strcat(str1, str2);    // "Hello World"
    
    cout << "Length: " << strlen(str1) << endl; // 11
    cout << str1 << endl;                        // Hello World
    
    return 0;
}
```

---

### ✅ Quick Summary

* C-style strings = **null-terminated char arrays**
* Use `<cstring>` functions for manipulation (`strlen`, `strcpy`, `strcat`, `strcmp`)
* **Always check array size** to avoid overflow
* Can convert to `string` for **modern C++ convenience**

