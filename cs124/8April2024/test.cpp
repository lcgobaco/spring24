#include <iostream>
#include <string>

// Forward declaration of HashCode function template
template<typename T>
size_t HashCode(const T& obj);

// HashCode specialization for integer types
template<typename IntegerType>
size_t HashCodeInteger(const IntegerType& value) {
    return static_cast<size_t>(value);
}

// HashCode specialization for string type
template<>
size_t HashCode<std::string>(const std::string& str) {
    size_t hash = 0;
    for (char ch : str) {
        hash = hash * 31 + ch;
    }
    return hash;
}

// Generic HashCode function template
template<typename T>
size_t HashCode(const T& obj) {
    return HashCodeInteger(obj);
}

int main() {
    int intVal = 123;
    std::string strVal = "hello";
    
    std::cout << "Hash code of intVal: " << HashCode(intVal) << std::endl;
    std::cout << "Hash code of strVal: " << HashCode(strVal) << std::endl;
    
    return 0;
}

