#pragma once
#include <iostream>
#include "Node.h"
#include "Sential_architecture.h"

// ==========================================
// SafeClass: The Object-Oriented Wrapper
// ==========================================
// This class provides a fully encapsulated, memory-safe interface 
// for the single_list Sentinel engine. It utilizes RAII to guarantee 
// zero memory leaks, hiding all pointer management from the user.
class SafeClass{
    private:
    Node* dummy_head;
    size_t size;
    public:
    // Constructor: Automatically initializes the Sentinel architecture
    SafeClass(){
        single_list::init_sentinels(dummy_head, size);
    }

    // Inserts a value into the list. 
    // Uses 1-based indexing. Defaults to LIFO (front insertion) in O(1) time.
    // Specific position insertions take O(n) time.
    void insert(double val, size_t position = size_t(-1)){
        single_list::insert(dummy_head, val, size, position);
    }

    // Removes a node from the list.
    // Uses 1-based indexing. Defaults to FIFO (back removal).
    // Safely rejects invalid bounds or empty lists.
    void remove(size_t position = size_t(-1)){
        single_list::remove(dummy_head, size, position);
    }

    // Returns the current number of active nodes in O(n) time.
    size_t getsize(){
        return single_list::getsize(dummy_head);
    }

    // Prints the list format to the console: [ 1 2 3 ]
    void getlist(){
        single_list::getlist(dummy_head);
    }

    // Destructor: Automatically wipes all user data and executes the 
    // Sentinel node when the object goes out of scope. (Zero memory leaks).
    ~SafeClass(){
        single_list::destroy(dummy_head, size);
        delete dummy_head;
    }
};
