#include "DyV.h"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << BusquedaBinaria(7, v, 0, v.size() - 1) << std::endl;
    std::vector<int> v2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << BusquedaBinaria_INV(7, v2, 0, v2.size() - 1) << std::endl;
    std::vector<int> v3 = {2,3,1,4,7,6,5,9,8};
    std::vector<int> v4 = {2,3,1,4,7,6,5,9,8};
    std::vector<int> v5 = {2,3,1,4,7,6,5,9,8};
    auto start = std::chrono::system_clock::now();
    QuickSort(v3, 0, v3.size() - 1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << "Time: " << duration.count() << "ms" << std::endl;
    auto start2 = std::chrono::system_clock::now();
    QuickSortFirst(v4, 0, v4.size() - 1);
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration2 = end2 - start2;
    std::cout << "Time: " << duration2.count() << "ms" << std::endl;
    auto start3 = std::chrono::system_clock::now();
    QuickSortRandom(v5, 0, v5.size() - 1);
    auto end3 = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration3 = end3 - start3;
    std::cout << "Time: " << duration3.count() << "ms" << std::endl;
    

    return 0;
}