#include <iostream>
#include <map>
#include <string>

template<typename Key, typename Value>
class HashTable {
private:
    std::map<Key, Value> map;

public:
    // Constructor
    HashTable() {}

    // Destructor
    ~HashTable() {}

    // Insert key-value pair into the hash table
    void insert(const Key& key, const Value& value) {
        map[key] = value;
    }

    // Retrieve value associated with given key
    Value get(const Key& key) {
        if (map.find(key) != map.end()) {
            return map[key];
        }
        throw std::out_of_range("Key not found in hash table");
    }

    vector<Value> values() {
        std::vector<Value> values;
        for (const auto& pair : map) {
            values.push_back(pair.second);
        }
        return values;
    }

    // Check if the given key exists in the hash table
    bool contains(const Key& key) {
        return map.find(key) != map.end();
    }

    // Remove key-value pair from the hash table
    void remove(const Key& key) {
        map.erase(key);
    }

    // Get the size of the hash table
    size_t size() const {
        return map.size();
    }

    // Check if the hash table is empty
    bool empty() const {
        return map.empty();
    }
};
