#pragma once
#include <iostream>
#include "Node.h"

class single_list{
    private:
    //Traversal private function used by both insert() and remove()
    static Node* traversal(Node*& dummy_head, size_t position){
        Node* ptr = dummy_head;
        for(int i = 0; i<position - 1; i++){
            ptr = ptr->next;
        }
        return ptr;
    }

    public:
    //initializes dummy_head and list_size
    static void init_sentinels ( Node*& dummy_head, size_t &list_size){
        dummy_head = new Node(0);
        list_size = 0;
    }

    //To print the list
    static void getlist(Node* dummy_head){
        Node* ptr = dummy_head->next;
        std::cout<<"[ ";
        while (ptr!=nullptr){
            std::cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        std::cout<<"]";
    }

    //inserting elements and by default in the front it seems as LIFO approach and this approach of 
    //sential architecture helps us get rid of edge cases involving nullptr
    static void insert(Node*& dummy_head, double val, size_t &list_size, size_t position = size_t(-1)){
        Node *newnode = new Node(val);
        Node *ptr;

        //Check for out of bound
        if(position > list_size+1 && position != size_t(-1)){
            std::cout<<"out of bound";
            return;
        }
        //the default case (LIFO)
        if (position == size_t(-1)){
            newnode->next = dummy_head->next;
            dummy_head->next = newnode;
            list_size++;
        }

        //For specific position
        else{
            Node* temp;
            ptr = traversal(dummy_head, position);
            newnode->next = ptr->next;
            ptr->next = newnode;
            list_size++;
        }
    }

    //Same approach as of insert though the default case here is always going to remove from the end so as 
    //a whole this engine still works on (FIFO) though insert seems to work as (LIFO)
    static void remove(Node*& dummy_head, size_t &list_size, size_t position = size_t(-1)){
        Node* ptr;
        Node* temp;

        position = position == size_t(-1)?list_size:position; //making the default position to be the last 

        //Check for invalid remove positions
        if( position == 0|| list_size == 0){
            std::cout<<"Invalid operation";
            return;
        }

        //Check for Out of bound the Node that doesn't exist can't be removed
        if(position > list_size){
            std::cout<<"Out of bound";
            return;
        }

        
        //Finally the logic for removal
        ptr = traversal(dummy_head, position);
        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        list_size--;

    }

    //To get the size of the list
    static size_t getsize(Node*& dummy_head){
        size_t list_size = 0;
        Node* ptr = dummy_head->next;
        while(ptr!=nullptr){
            list_size++;
            ptr = ptr->next;
        }
        return list_size;
    }

    //to destroy the list completely after use 
    static void destroy(Node*& dummy_head, size_t &list_size){
        Node* ptr = dummy_head->next;
        Node* temp;
        while (ptr!=nullptr){
            temp = ptr;
            ptr = temp->next;
            delete temp;
        }
        dummy_head->next = nullptr;//necessary else dummy will always be pointing to a deleted node and 
        //that's a case of Dangling Pointer.
        list_size = 0;
    }


};