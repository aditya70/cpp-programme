#include <bits/stdc++.h>
using namespace std; 
class LFUCache {
    int capacity;
    unordered_map<int, pair<int, int>> um;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> pos;
    int minFreq;

public:
    LFUCache(int capacity){
        this->capacity=capacity;
        this->minFreq=INT_MAX;
    }

    int get(int key) {
        if (um.count(key) == 0) return -1;
        freq[um[key].second].erase(pos[key]);
        um[key].second++;
        freq[um[key].second].push_back(key);
        pos[key] = --freq[um[key].second].end();
        if (freq[minFreq].size() == 0) minFreq++;
        return um[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (um.count(key) && get(key) != -1) {
            um[key].first = value;
            return;
        }
        if (um.size() >= capacity) {
            int k = freq[minFreq].front();
            freq[minFreq].pop_front();
            pos.erase(k);
            um.erase(k);
        }
        um[key] = {value, 1};
        freq[1].push_back(key);
        pos[key] = --freq[1].end();
        minFreq = 1;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */