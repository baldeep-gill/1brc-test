#include <chrono>

#include "solution.cpp"

int main (int argc, char* argv[]) {
    std::string filename = "data.txt";

    if (argc > 1) filename = argv[1];

    auto start = std::chrono::high_resolution_clock::now();

    solution(filename);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Elapsed time: " << elapsed_time.count() << " ms\n";

    return 0;
}