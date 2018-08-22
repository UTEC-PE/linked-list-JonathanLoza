#include <iostream>
#include "list.h"
#include "node.h"
#include "iterator.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;
    list.push_back(5);
    list.push_back(6);
    cout<<list.front()<<endl;
    cout<<list.back()<<endl;

    return 0;
}