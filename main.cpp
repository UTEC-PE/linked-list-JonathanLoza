#include <iostream>
#include "list.h"
#include "node.h"
#include "iterator.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    List<int> list;
    bool x=list.empty();
    if(x)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_front(3);
    x=list.empty();
    if(x)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    cout<<list.front()<<endl;
    cout<<list.back()<<endl;
    list.print();
    list.print_reverse();
    cout<<list.get(1)<<endl;
    list.pop_back();
    list.print();
    list.pop_front();
    list.print();

    return 0;
}