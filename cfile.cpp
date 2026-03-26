#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace CFILE {

    bool exists(const std::string& path) {
        return std::filesystem::exists(path);
    }

    bool create(const std::string& path) {
        std::ofstream file(path);
        return file.good();
    }

    std::string read(const std::string& path) {
        std::ifstream file(path);
        if (!file) return "";

        std::string content, line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }

    bool write(const std::string& path, const std::string& content) {
        std::ofstream file(path);
        if (!file) return false;

        file << content;
        return true;
    }

    bool append(const std::string& path, const std::string& content) {
        std::ofstream file(path, std::ios::app);
        if (!file) return false;

        file << content;
        return true;
    }

    bool remove(const std::string& path) {
        return std::filesystem::remove(path);
    }

}

int main() {
    using namespace CFILE;

    std::string file = "test.txt";

    create(file);
    write(file, "Hello from CFILE!");
    append(file, "\nThis is cool 😎");

    std::cout << "=== CONTENT ===\n";
    std::cout << read(file);

    if (exists(file)) {
        std::cout << "\nFile exists!\n";
    }

    remove(file);

    return 0;
}