#include <iostream>
#include "../Header/ArrayBST.h"
arrayBST::arrayBST(int size) : data(nullptr), size(size), checker(0) 
{
    data = new Arraykey[size];
}

arrayBST::~arrayBST() 
{
    delete[] data;
}

bool arrayBST::resize() 
{
    return resize(size * 2);
}

bool arrayBST::resize(int newSize) 
{
    Arraykey* temp = new Arraykey[newSize];
    if (temp == nullptr) {
        std::cout << "Error allocating space" << std::endl;
        return false;
    }

    for (int i = 0; i < size; i++) 
    {
        temp[i] = data[i];
    }
    for (int i = size; i < newSize; i++) 
    {
        temp[i].data = -1; 
    }
    delete[] data;
    data = temp;
    size = newSize;
    return true;
}

bool arrayBST::isFull() 
{
    return (checker == size);
}

void arrayBST::heapify(int index) 
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if ((left < checker) && (data[left].data != -1) && (data[left].data < data[smallest].data)) 
    {
        smallest = left;
    }

    if ((right < checker) && (data[right].data != -1) && (data[right].data < data[smallest].data)) 
    {
        smallest = right;
    }

    if (smallest != index) 
    {
        std::swap(data[index], data[smallest]);
        heapify(smallest);
    }
}

bool arrayBST::isEmpty() 
{
    return (checker == 0);
}

void arrayBST::addBST(int element) 
{
    if (isFull()) {
        if (!resize()) {
            std::cout << "Error allocating space" << std::endl;
            return;
        }
    }
    int current = 0;
    while (data[current].data != -1) 
    {
        if (element < data[current].data) 
        {
            current = 2 * current + 1;
        } 
        else 
        {
            current = 2 * current + 2;
        }
        if (current >= size) 
        {
            if (!resize()) 
            {
                std::cout << "Error allocating space" << std::endl;
                return;
            }
        }
    }

    data[current].data = element;
    checker++;
}

void arrayBST::removeBST(int element) 
{
    if (isEmpty()) 
    {
        std::cout << "Empty tree cannot be removed" << std::endl;
        return;
    }

    int i;
    for (i = 0; i < size; i++) 
    {
        if (data[i].data == element) 
        {
            break;
        }
    }

    if (i < size && data[i].data == element) 
    {
        data[i].data = data[checker - 1].data;
        data[checker - 1].data = -1;
        checker--;
        if (i != checker) { 
            heapify(i);
        }
    } 
    else 
    {
        std::cout << "Key not found" << std::endl;
    }
}

int arrayBST::searchBST(int element) 
{
    if (isEmpty()) 
    {
        std::cout << "Empty tree cannot be searched" << std::endl;
        return -1;
    }

    int current = 0;
    while (current < size && data[current].data != -1) 
    {
        if (data[current].data == element) 
        {
            return current;
        } 
        else if (element < data[current].data) 
        {
            current = 2 * current + 1;
        } 
        else 
        {
            current = 2 * current + 2;
        }
    }


    return -1;
}
void arrayBST::output() 
{
    if (isEmpty()) {
        std::cout << "Tree is empty." << std::endl;
    } else {
        for (int i = 0; i < size; i++) {
            if (data[i].data != -1) {
                std::cout << data[i].data << ' ';
            }
        }
        std::cout << std::endl;
    }
}

