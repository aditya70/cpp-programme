`string` cheat sheet**, covering **declaration, common operations, STL functions, and tricks**.

---

# 🟢 C++ String Cheat Sheet

---

### 1️⃣ Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

string s1;                // empty string
string s2 = "Hello";      // initialized
string s3(5, 'a');        // "aaaaa" (5 times 'a')
string s4 = s2;           // copy constructor
```

---

### 2️⃣ Access / Modify

```cpp
char ch = s2[0];          // 'H', 0-based index
s2[0] = 'h';              // modify
cout << s2.front() << "\n"; // 'h'
cout << s2.back() << "\n";  // 'o'
```

* Strings support **random access** like vectors

---

### 3️⃣ Size / Empty / Clear

```cpp
int n = s2.size();      // 5
bool isEmpty = s2.empty(); // false
s2.clear();             // empty string
```

---

### 4️⃣ Concatenation

```cpp
string s5 = s2 + " World"; // "Hello World"
s2 += "!";                  // append
```

---

### 5️⃣ Comparison

```cpp
s1 = "abc"; s2 = "xyz";

if(s1 == s2) ...
if(s1 != s2) ...
if(s1 < s2)  ...  // lexicographical
```

* Supports all **relational operators** (`==`, `!=`, `<`, `>`, `<=`, `>=`)

---

### 6️⃣ Substring / Find

```cpp
string s = "hello world";
string sub = s.substr(0, 5);   // "hello"
size_t pos = s.find("world");  // 6, returns string::npos if not found
s.replace(0, 5, "Hi");         // "Hi world"
s.erase(3, 2);                 // erase 2 chars from index 3
```

---

### 7️⃣ Iteration

```cpp
for(char c : s) cout << c << " ";
for(auto it = s.begin(); it != s.end(); ++it) cout << *it;
```

* Can also use **reverse iterators**: `rbegin()`, `rend()`

---

### 8️⃣ Conversion

```cpp
// string ↔ int
string num = "123";
int x = stoi(num);              // 123
x = 456;
string sNum = to_string(x);     // "456"

// string ↔ double
double d = stod("3.14");
string sD = to_string(d);
```

---

### 9️⃣ String to Char Array

```cpp
string s = "hello";
char cstr[6];
strcpy(cstr, s.c_str());  // c_str() gives null-terminated char array
```

---

### 10️⃣ Useful Functions

| Function                      | Description                  |
| ----------------------------- | ---------------------------- |
| `length()` / `size()`         | Number of characters         |
| `empty()`                     | Check if empty               |
| `append(str)` / `+=`          | Add string                   |
| `insert(pos, str)`            | Insert at index              |
| `erase(pos, len)`             | Remove substring             |
| `replace(pos, len, str)`      | Replace substring            |
| `find(str)` / `rfind(str)`    | Find first / last occurrence |
| `substr(pos, len)`            | Extract substring            |
| `c_str()`                     | Get C-style string           |
| `stoi`, `stol`, `stod`        | String to number             |
| `to_string`                   | Number to string             |
| `sort(s.begin(), s.end())`    | Sort characters              |
| `reverse(s.begin(), s.end())` | Reverse string               |

---

### 11️⃣ Common Interview Patterns

1. **Palindrome check**: `s == string(s.rbegin(), s.rend())`
2. **Anagram check**: `sort(s1.begin(), s1.end()) == sort(s2.begin(), s2.end())`
3. **Prefix / Suffix**: `s.substr(0, len)`, `s.substr(s.size()-len)`
4. **Split by delimiter**: `stringstream ss(s); getline(ss, token, ',');`
5. **String compression / count consecutive**

---

### ✅ Quick Tips

* Strings are **mutable** (unlike C-style strings)
* Supports **random access, iterators, STL algorithms**
* Can be **converted easily to/from numbers**
* Use `c_str()` for **legacy C APIs**
* `string` + `vector<char>` are interchangeable in many algorithms


