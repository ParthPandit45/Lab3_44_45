#include <iostream>

class BST{
    public:
        virtual bool isEmpty() = 0;
        virtual void addBST(int data) = 0;
        virtual bool removeBST(int keyToDelete) = 0;
        virtual bool searchBST(int targetKey) = 0;
};