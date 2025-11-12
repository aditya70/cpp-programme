**For `int` (local/automatic storage):**
```cpp
int count;  // Garbage value (uninitialized)
cout << count;  // Unpredictable output
```

Local `int` variables contain **garbage values** from whatever was in that memory location before.

**For `bool` (local/automatic storage):**
```cpp
bool flag;  // Garbage value (uninitialized)
cout << flag;  // Unpredictable output (could be 0 or 1 or other)
```

Local `bool` variables also contain **garbage values**.

---

**BUT there ARE default values in these cases:**

**1. Global/Static variables:**
```cpp
int count;      // Default: 0
bool flag;      // Default: false
// These are in global/static scope
```

**2. Dynamically allocated:**
```cpp
int* p = new int();     // Default: 0
bool* b = new bool();   // Default: false
```

**3. Class members (if not explicitly initialized):**
```cpp
struct MyClass {
    int count;      // Garbage
    bool flag;      // Garbage
};

MyClass obj;  // Both are uninitialized
```

---

**Best practice - Always initialize:**
```cpp
int count = 0;
bool flag = false;

// OR use brace initialization
int count{};      // Defaults to 0
bool flag{};      // Defaults to false
```

**Summary:**
- **Local variables** → garbage
- **Global/static variables** → defaults (0 for int, false for bool)
- **Dynamic allocation with ()** → defaults
- **Best approach** → always explicitly initialize