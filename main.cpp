#include "common.h"
#include "d04.h"
#include "d05.h"
#include "d06.h"
int main() {
    std::printf("hello\n");
    
    // D04b d04b;
    // d04b.run();

    D06b d06b;
    auto start = std::chrono::high_resolution_clock::now();
    d06b.run();
    auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> time_in_seconds{end - start};
    std::cout << "Time Taken: " << time_in_seconds << "\n";
    return 0;
}