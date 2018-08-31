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
        if(!this->head){
            throw "Vacio";
        }
        head->printReverse();
    };

public:
    List(){
        head= nullptr;
        tail= nullptr;
        nodes=0;
    };
    T front(){
        if(!head){
            throw "Lista Vacia";
        } else{
            return head->data;
        }
    };
    T back(){
        if(!head){
            throw "Lista Vacia";
        } else{
            return tail->data;
        }
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
        nodes++;
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
        nodes++;
    };
    void pop_front(){
        auto* temp=head;
        if(!head)
            throw "Lista vacia";
        if(nodes==1)
            head=tail=nullptr;
        else{
            head=temp->next;
        }
        delete temp;
        nodes--;
    };
    void pop_back(){
        auto* temp=head;
        if(!head)
            throw "Lista vacia";
        if(nodes==1)
            head=tail=nullptr;
        else{
            while(temp->next!=tail)
                temp=temp->next;
            tail=temp;
            temp=temp->next;
        }
        delete temp;
        nodes--;
    };
    T get(int position){
        if(!head){
            throw "Vacio";
        }
        auto* temp=head;
        for (int i = 1; i < position; i++) {
            temp=temp->next;
        }
        return temp->data;
    };
    void concat(List<T> &other){
        if(!other.head || !head){ // Si una de las listas es vacía, entonces deberías retornar la otra
           throw "Lista vacia ";
        }
        tail->next=other.head;
        tail=other.tail;
        nodes=nodes+other.nodes;
    };
    bool empty(){
        return head == nullptr;
    };
    int size(){
        return nodes;
    };
    void print(){
        Node<T>* actual=head;
        while(actual!=tail){
            cout<<actual->data<<" ";
            actual=actual->next;
        }
        cout<<tail->data<<endl;
    };
    void print_reverse(){
        if(!head){
            throw "Vacio";
        }
        head->printReverse();
        cout<<endl;
    };
    void clear(){ // No es tan simple, aquí deberías iterar sobre los elementos de la lista para darles delete
        head=nullptr;
        tail=nullptr;
        nodes=0;
    };
    Iterator<T> begin(){

    };
    Iterator<T> end(){

    };
    ~List(){ // El clear debería ser similar
        if(head){
            head->killSelf();
        }
        delete [] head; // Estos dos deletes no deberían hacerse, ya que killSelf ya se encarga de borar head y tail. Fuera de eso, no deberían tener []
        delete [] tail;
    };
};
#endif