#include<iostream>
#include "../Implementation/arrayBST.cpp"

int main() {
    arrayBST bst;

    // Check if the tree is initially empty
    std::cout << "Initially, is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;
    
    bst.addBST(10);
    bst.addBST(1);
    bst.addBST(20);
    bst.addBST(3);
    std::cout << "Tree after adding 10, 1, 20, 3:" << std::endl;
    bst.output();

     // Search for elements in the tree
    std::cout << "Searching for 20: " << (bst.searchBST(20) != -1 ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 3: " << (bst.searchBST(3) != -1 ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 4: " << (bst.searchBST(4) != -1 ? "Found" : "Not Found") << std::endl;

    // Remove an element from the tree
    bst.removeBST(20);
    // Check if the element is still in the tree
    std::cout << "Searching for 20 (after removing): " << (bst.searchBST(20) != -1 ? "Found" : "Not Found") << std::endl;
     std::cout << "Tree after removing 20:" << std::endl;
    bst.output();
   
    return 0;
}