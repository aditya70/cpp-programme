### Basic Map Loop Methods:
Method 1: Range-based for loop with structured bindings (C++17) - BEST
cppmap<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

// ✅ Most modern and readable
for (auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}
// Output:
// 1: one
// 2: two
// 3: three

Method 2: Range-based for loop with pair
cppmap<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

// ✅ Works in C++11+
for (auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}

// Or with const
for (const auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}

Method 3: Iterator-based loop
cppmap<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

// ✅ Traditional way
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

// Or with explicit type
for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

Method 4: Reverse iteration
cppmap<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

// ✅ Loop in reverse order
for (auto it = m.rbegin(); it != m.rend(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
// Output:
// 3: three
// 2: two
// 1: one