#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    struct Node* next;
    void printReverse(){
        if(next!=nullptr)
            next->printReverse();
        std::cout<<data<<" ";
    }
    void killSelf(){
        if(next!=nullptr)
            next->killSelf();
        delete this;
    };
};

#endif