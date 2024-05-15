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

int main() {
    HashTable<std::string, int> ht;

    // Insert some key-value pairs
    ht.insert("apple", 5);
    ht.insert("banana", 10);
    ht.insert("orange", 7);

    // Retrieve and print the value associated with a key
    try {
        std::cout << "Value associated with 'banana': " << ht.get("banana") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Check if a key exists
    std::cout << "Does 'grape' exist in the hash table? " << (ht.contains("grape") ? "Yes" : "No") << std::endl;

    // Remove a key-value pair
    ht.remove("banana");

    // Print the size of the hash table
    std::cout << "Size of the hash table: " << ht.size() << std::endl;

    return 0;
}
