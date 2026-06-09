#include <iostream>
#include "Node.h"
#include "Sential_architecture.h"
#include "WrapperSafeClass.h"
using namespace std;

int main(){
    //using the utility class single_list
    {
        cout<<"---STARTING TEST 1: RAW ENGINE \n";
        Node* dummy_head;
        size_t size;
        double val;
        single_list::init_sentinels(dummy_head, size);
        for(int i = 1; i <= 5; i++){
            cout<<"data"<<endl;
            cin>>val;
            single_list::insert(dummy_head, val, size);
        }

        cout<<"The list: ";
        single_list::getlist(dummy_head);
        single_list::remove(dummy_head, size, 3);
        cout<<"the list after removing the third Node: "<<endl;
        single_list::getlist(dummy_head);

        cout<<"The new size: "<<single_list::getsize(dummy_head)<<endl;

        single_list::destroy(dummy_head, size);
        cout<<"Size of the list after being destroyed: "<<size<<"\n"<<endl;
        delete dummy_head;
    }

    {
        cout<<"---STARTING TEST2: WRAPPER CLASS\n";
        SafeClass ob;
        double val;
        for(int i = 1; i <= 5; i++){
            cout<<"data"<<endl;
            cin>>val;
            ob.insert(val);
        }
        cout<<"The list: ";
        ob.getlist();
        ob.remove(3);
        cout<<"the list after removing the third Node: "<<endl;
        ob.getlist();
        cout<<"The new size: "<<ob.getsize()<<endl;
    }
}