#pragma once
#include <iostream>
#include "Node.h"

//Class to manage operation on the list 
class Singlelist{
    public:

    //to get the full list
    static void getlist(Node *head){
        Node* ptr;
        ptr = head;
        std::cout<<"[ ";
        while( ptr!=nullptr ){
            std::cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        std::cout<<"]";
    }
    
    
    //To insert new nodes and if the position isn't defined it inserts in the fron one of the cons of 
    //single linked list
    //to tackle the no argument issue while understanding user's 1 based indexing i used size_t(-1) which acts as a flag to 
    //insert in the front
    static void insert(Node *&head, double val, size_t &list_size, size_t position = size_t(-1)){
        Node* newnode;
        newnode = new Node(val);

        //Check if the list is empty
        if(head==nullptr){
            head = newnode;
            list_size++;
        }

        else {

            //this inserts the node in the front
            if(position==size_t(-1)){
                Node* temp;
                temp = head;
                head = newnode;
                head->next = temp;
                list_size++;
            }

            //this inserts the node if the position argument is passed by the user
            else{
                Node* ptr;
                ptr = head;

                //loop for traversal and loop stops one node behind the position where user wants to add and since 
                //we are considering user's 1 based indexing we stop at position-2 position-1 to get to 0 based indexing and 
                //extra -1 for stopping one step behind the required position
                for(int i = 0; i < position-2; i++){

                    //check if the nullptr is hit befor getting to the position loop stops
                    if(ptr->next==nullptr){
                        break;
                    }
                    ptr = ptr->next;
                }
                
                //updates the new node at the specified position we get after list traversal loop
                newnode->next = ptr->next;
                ptr->next = newnode;
                list_size++;
                
            }
        }

    }

    //To remove a node from the list
    //returning int is powerful is that it allows your function to communicate the error back to main() (by 
    //returning -1), so main() knows the deletion failed.
    static int remove(Node*& head, size_t &list_size, size_t position){

        //check if the list is empty and since its based on 1 based indexing user shouldn't pass 0 so check for 
        //that too
        if(head==nullptr||position==0){
            return -1;
        }

        Node* ptr;
        ptr = head;
        //Easiest with time complexity O(1) no need for traversal to remove the 1st node
        if(position==1){
                head = ptr->next;
                delete(ptr);
                list_size--;
                return 0;
        }

        //for any other position the time complexity is O(n)
        for(int i = 0; i<position-2 ; i++){

            //check for the bound and if the user passes some position where there is no node
            if( ptr->next==nullptr ){
                return -1;
            }
            ptr = ptr->next;
        }

        //check if user passed to delete a node right after the last node which is not possible since it doesn't exist
        if ( ptr->next == nullptr ) {
            return -1;
        }

        //logic to delete the node
        Node* temp;
        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete(temp);
        list_size--;
        return 0;
    }

    //TO desttroy list after use
    static void destroy(Node*& head, size_t &list_size){
        Node* ptr = head;
        Node* temp;
        while (ptr!=nullptr){
            temp = ptr;
            ptr = ptr->next;
            delete (temp);
        }
        head = nullptr;
        list_size = 0;
    }

    //to get the size of the list
    static int size(Node*& head){
        Node* ptr = head;
        size_t size = 0;
        while(ptr!=nullptr){
            size++;
            ptr = ptr->next;
        }
        return size;

    }

    //Reverse a list
    static void reverse(Node*& head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};