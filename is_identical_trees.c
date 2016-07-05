/*
 * Author: Raj Ammanur
 *
 * Iterative function to check if two trees are identical
 * Two trees are identical when they have same data and 
 * arrangement of data is also same. To identify if two 
 * trees are identical, we need to traverse both trees 
 * simultaneously, and while traversing we need to compare 
 * data and children of the trees.
 *
 */

/*
 * Test: ./a.out 
 *
 * Output:
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int
areIdentical(Node *root1, Node *root2)
{
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
 
    Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
 
    areIdentical(root1, root2)? cout << "Yes"
                              : cout << "No";
    return 0;
}
