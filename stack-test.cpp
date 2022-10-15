#include <iostream>
#include "stack.h"


int main(int argc, char* argv[])
{

//    std::less<int> less;
//    std::cout <<  less(60, 29) << std::endl;

    Stack<int> stack;

    stack.push(12);
    stack.push(13);
    stack.push(14);
    stack.push(15);
    stack.push(16);

    std::cout << stack.size() << std::endl;

    if (stack.empty()) {
        std::cout << "stack is empty" << std::endl;
    }

    stack.pop();
    std::cout << stack.top() << std::endl;

    return 0;
}
