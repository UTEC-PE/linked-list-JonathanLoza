#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

    void print_reverse(Node<T>* head){

    };

public:
    List(){
        head= nullptr;
        tail= nullptr;
    };
    T front(){
        return head->data;
    };
    T back(){
        return tail->data;
    };
    void push_front(T value){
        auto* temp= new Node<T>{value, nullptr};
        if (head==nullptr) {
            head=temp;
            tail=temp;
        }else{
            temp->next=head;
            head=temp;
        }
    };
    void push_back(T value){
        auto* temp= new Node<T>{value, nullptr};
        if (head==nullptr) {
            head=temp;
            tail=temp;

        }else{
            tail->next=temp;
            tail=temp;
        }
    };
    void pop_front(){

    };
    void pop_back(){
        delete tail;

    };
    T get(int position){

    };
    void concat(List<T> &other){

    };
    bool empty(){
        return head == nullptr;
    };
    int size(){

    };
    void print(){
        Node<T>* actual=head;

    };
    void print_reverse(){

    };
    void clear(){

    };
    Iterator<T> begin(){

    };
    Iterator<T> end(){

    };
    ~List(){};
};
#endif
