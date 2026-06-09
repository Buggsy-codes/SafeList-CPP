#pragma once
#include<iostream>
//Structure of the list
struct Node{
    double data;
    Node* next;

    Node(double val=0) : data(val), next(nullptr){}
};