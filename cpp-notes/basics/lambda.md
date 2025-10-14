# 🟢 C++ Lambda Function Cheat Sheet

A **lambda function** is an **anonymous function** you can define inline.

**Syntax:**

```cpp
[capture](parameters) -> return_type { body }
```

* `capture` → variables from surrounding scope
* `parameters` → function parameters
* `-> return_type` → optional, inferred by default
* `body` → function code

---

## 1️⃣ Basic Lambda

```cpp
auto add = [](int a, int b) { return a + b; };
cout << add(3,4); // 7
```

---

## 2️⃣ Lambda With Capture

```cpp
int x = 10;
auto printX = [x]() { cout << x << "\n"; }; // capture by value
printX(); // 10

int y = 5;
auto incrementY = [&y]() { y++; };        // capture by reference
incrementY();
cout << y; // 6
```

* `[x]` → capture by value
* `[&x]` → capture by reference
* `[=]` → capture **all variables by value**
* `[&]` → capture **all variables by reference**

---

## 3️⃣ Lambda in `sort`

```cpp
vector<int> v = {3,1,4,2,5};

// Ascending
sort(v.begin(), v.end(), [](int a,int b){ return a < b; });

// Descending
sort(v.begin(), v.end(), [](int a,int b){ return a > b; });
```

* Can be used to **sort vectors, arrays, pairs, structs**

---

## 4️⃣ Lambda With Struct / Object

```cpp
struct Student {
    string name;
    int marks;
};

vector<Student> v = {{"Alice",90},{"Bob",85},{"Charlie",95}};

// Sort by marks descending
sort(v.begin(), v.end(), [](Student a, Student b){ return a.marks > b.marks; });

// Sort by name ascending
sort(v.begin(), v.end(), [](Student a, Student b){ return a.name < b.name; });
```

---

## 5️⃣ Lambda in `for_each`

```cpp
vector<int> v = {1,2,3,4,5};

for_each(v.begin(), v.end(), [](int x){ cout << x*2 << " "; }); // 2 4 6 8 10
```

* Can **replace small function objects**
* Very convenient inline

---

## 6️⃣ Lambda in `priority_queue`

```cpp
vector<int> v = {5,1,3,4,2};

// Min-heap using lambda
auto cmp = [](int a, int b){ return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

for(int x : v) pq.push(x);

while(!pq.empty()) { cout << pq.top() << " "; pq.pop(); }
// Output: 1 2 3 4 5
```

---

## 7️⃣ Lambda with Multiple Captures

```cpp
int a = 5, b = 10;
auto sum = [=]() { return a + b; };   // capture by value
auto sumRef = [&]() { return a + b; }; // capture all by reference
```


----------------------

# 🟢 C++ `decltype` Cheat Sheet
 **`decltype`** carefully is a very useful feature in modern C++ (C++11 onward) for **type deduction**.

### 1️⃣ **What is `decltype`?**

* `decltype` tells the **compiler the type of an expression** without evaluating it.
* Useful when the type is **long, complicated, or depends on templates**.

**Syntax:**

```cpp
decltype(expression) variable_name;
```

* `expression` → any valid expression
* `variable_name` → declares a variable of the **same type as expression**

---

### 2️⃣ **Simple Examples**

```cpp
int x = 5;
decltype(x) y;    // y is int
y = 10;

double z = 3.14;
decltype(z) w;    // w is double
```

---

### 3️⃣ **With Expressions**

```cpp
int a = 5;
double b = 2.5;

decltype(a + b) c; // type of a+b is double
c = 10.5;
```

* Compiler evaluates **type of expression**, not value

---

### 4️⃣ **With References**

```cpp
int x = 5;
int &ref = x;

decltype(ref) y = x;   // y is int& (reference)
y = 10;                // modifies x
```

* Preserves **reference and const qualifiers**

```cpp
const int z = 7;
decltype(z) w = 10;    // w is const int
// w = 5; // error!
```

---

### 5️⃣ **Use in Templates / STL**

```cpp
vector<int> v = {1,2,3};
auto it = v.begin();

// Get type of *it
decltype(*it) val = *it; // val is int& (reference)
val = 10;                 // modifies vector
```

* Works well for **iterators, lambdas, and generic programming**

---

### 6️⃣ **With Lambda / Priority Queue Example**

```cpp
auto cmp = [](int a,int b){ return a>b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); 
```

* Here `decltype(cmp)` → type of the lambda
* Needed because **lambda types are anonymous**

---

### ✅ Quick Rules

1. `decltype(expression)` → type of expression (preserves const & references)
2. Works for **variables, expressions, function calls**
3. Often used with **auto** and **templates**
4. Helps in **generic programming** or **when type is complicated or unknown**

---

### 7️⃣ **Quick Examples Table**

| Expression                    | `decltype` Result                                           |
| ----------------------------- | ----------------------------------------------------------- |
| `int x`                       | `int`                                                       |
| `const int x`                 | `const int`                                                 |
| `int &x`                      | `int&`                                                      |
| `a + b` (int+double)          | `double`                                                    |
| `*it` (vector<int>::iterator) | `int&`                                                      |
| `lambda`                      | anonymous type (use `decltype(lambda)` to declare variable) |

