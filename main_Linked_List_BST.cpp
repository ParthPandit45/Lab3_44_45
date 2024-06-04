#include "Linked_List_BST.h"
#include <iostream> 
using namespace std;

int main()
{

    BST *bst = new LinkedBST();

    cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << endl;
    bst->addBST(100);
    bst->addBST(200);
    bst->addBST(300);
    bst->addBST(400);
    bst->addBST(500);
    bst->addBST(600);

    //After adding data in the tree , return NO  --->

    cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << endl;


    cout << "Is there 600 in the tree ? " << (bst->searchBST(600) ? "Yes" : "No") << endl;
    cout << "Is there 900 in the tree ? " << (bst->searchBST(900) ? "Yes" : "No") << endl;

     bst->removeBST(400);
     cout << "Is there 400 in tree  after removal? " << (bst->searchBST(400) ? "Yes" : "No") << endl;

    delete bst;

    return 0;
}