
#include <iostream>
#include "binarysearchtree.h"

struct Arraykey 
{
    int data = -1; 
};
class arrayBST:public BinarySearchTree
{
private:
    Arraykey* data;
    int size;
    int checker;
    bool resize();
    bool resize(int newSize);
    bool isFull();
    void heapify(int index);

public:
    bool isEmpty();
    void addBST(int);
    int searchBST(int);
    void removeBST(int);
    void output();
    arrayBST(int size = 10);
    ~arrayBST();  
};