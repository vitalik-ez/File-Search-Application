#include "search_lib.h"
#include <filesystem>
#include <thread>
#include <iostream> // Add this line to include iostream
#include <atomic>

namespace fs = std::filesystem;

void SearchLibrary::searchFile(const std::string& rootDir, const std::string& fileName, bool& found) {
    if (fs::is_directory(rootDir)) {
        std::atomic_bool stopSearch(false);

        auto searchThread = [&]() {
            for (const auto& entry : fs::recursive_directory_iterator(rootDir)) {
                if (stopSearch) break;

                if (entry.is_regular_file() && entry.path().filename().string() == fileName) {
                    found = true;
                    std::cout << "File found: " << entry.path().string() << std::endl;
                    stopSearch = true;
                    break;
                }
            }
        };

        int numThreads = std::min(std::thread::hardware_concurrency(), 8u);
        std::vector<std::thread> threads;

        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back(searchThread);
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }
}
