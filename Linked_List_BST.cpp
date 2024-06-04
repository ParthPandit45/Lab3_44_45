
#include <iostream>
#include "Linked_List_BST.h"

using namespace std;

LinkedBST::LinkedBST() : root(nullptr) {}
LinkedBST::~LinkedBST()
{
    delete root;
}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

void LinkedBST::addBST(int data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr)
    {
        parent = temp;
        if (data < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    if (data < parent->key)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
    newNode->parent = parent;
}

bool LinkedBST::removeBST(int keyToDelete)
{
    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr && temp->key != keyToDelete)
    {
        parent = temp;
        if (keyToDelete < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }

    if (temp == nullptr)
    {
        return false;
    }

    //  Case 1: Node doesnt have any children:

    if (temp->leftChild == nullptr && temp->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = nullptr;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = nullptr;
        }
        else
        {
            parent->rightChild = nullptr;
        }
        delete temp;
    }

    // Case 2: Node contains only one children:

    else if (temp->leftChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = temp->rightChild;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = temp->rightChild;
        }
        else
        {
            parent->rightChild = temp->rightChild;
        }
        delete temp;
    }
    else if (temp->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = temp->leftChild;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = temp->leftChild;
        }
        else
        {
            parent->rightChild = temp->leftChild;
        }
        delete temp;
    }
    // Case 3: Node contains two children:
    
    else
    {
        Node *successor = temp->rightChild;
        Node *successorParent = temp;
        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        if (successorParent != temp)
        {
            successorParent->leftChild = successor->rightChild;
        }
        else
        {
            successorParent->rightChild = successor->rightChild;
        }

        temp->key = successor->key;
        delete successor;
    }

    return true;
}

bool LinkedBST::searchBST(int targetKey)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (targetKey == temp->key)
        {
            return true;
        }
        else if (targetKey < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    return false;
}