### string notes

```
    // Helper function to split string by delimiter
    vector<string> split(string& str, char delimiter) {
        stringstream stringStream(str);
        string item;
        vector<string> result;

        // Extract each component separated by delimiter
        while (getline(stringStream, item, delimiter)) {
            result.emplace_back(item);
        }

        return result;
    }

split("/leet/code") // size 3 includes empty string
```

```
vector<string> split(string& str, char delimiter) {
    stringstream stringStream(str);
    string item;
    vector<string> result;
    while (getline(stringStream, item, delimiter)) {
        if (!item.empty()) {  // Skip empty strings
            result.emplace_back(item);
        }
    }
    return result;
}

split("/leet/code") // size 2 not includes empty string
```