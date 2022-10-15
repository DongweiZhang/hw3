
#include <iostream>
#include <vector>
#include "heap.h"


int main(int argc, char* argv[])
{
    Heap<int, std::greater<>> h1(3);

    h1.push(5);
    h1.push(2);
    h1.push(12);
    h1.push(3);
    h1.push(55);
    h1.push(21);
    h1.push(7);
    h1.push(9);
    h1.push(11);
    h1.push(9);

    std::cout << h1.size() << std::endl;
    std::cout << h1.top() << std::endl;

    if (h1.empty()) {
        std::cout << "heap is empty" << std::endl;
    }

    h1.pop();
    std::cout << h1.top() << std::endl;

    std::cout << h1.size() << std::endl;
    return 0;
}
