#include <iostream>
#include <fstream>
#include <stdexcept>

void loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    // File is open, do something with it
    std::cout << "File opened successfully." << std::endl;

    // Example: Read contents of the file
    char ch;
    while (file.get(ch)) {
        std::cout << ch;
    }

    file.close();
}

int main() {
    std::string filename = "example.txt"; // Change this to the file you want to load

    try {
        loadFile(filename);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
