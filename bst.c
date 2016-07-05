// call newNode() three times 
struct node* build123a() 
{
  struct node* root = newNode(2); 
  struct node* lChild = newNode(1); 
  struct node* rChild = newNode(3);
  root->left = lChild; 
  root->right= rChild;

  return(root); 
}

int size (struct node *node)
{
   if (node == NULL) {
      return 0;
   }

   return size(node->left )+ 1 + size(node->right);
}

int maxDepth (struct node *node)
{
   /* 
    * Compute the "maxDepth" of a tree -- the number of nodes 
    * along the longest path from the root node down to the 
    * farthest leaf node. 
    */
    if (node == NULL) {
       return 0;
    }

    int leftSize = maxDepth(node->left);
    int rightSize = maxDepth(node->right);
    if (leftSize > rightSize) {
       return leftSize + 1;
    }
    return rightSize + 1;
}

/* 
 * Given a non-empty binary search tree, 
 * return the maximum data value found in that tree. 
 * Note that the entire tree does not need to be searched. 
 */ 
int maxValue (struct node* node) 
{
   while (node->right != NULL) {
      node = node->right;
   }
   return node->data;
}

/* 
 * Given a non-empty binary search tree, 
 * return the minimum data value found in that tree. 
 * Note that the entire tree does not need to be searched. 
 */ 
int minValue (struct node* node) 
{
   while (node->left != NULL) {
      node = node->left;
   }
   return node->data;
}

/* 
 * Given a binary search tree, print out 
 * its data elements in increasing 
 * sorted order. 
 */ 
void printTree(struct node *node)
{
   if (node == NULL) {
      return;
   }
   printTree(node->left);
   printf("%d ", node->data);
   printTree(node->right);
   return;
}

/* 
 * Given a tree and a sum, return true if there is a path from the root 
 * down to a leaf, such that adding up all the values along the path 
 * equals the given sum.
 * Strategy: subtract the node value from the sum when recurring down, 
 * and check to see if the sum is 0 when you run out of tree. 
 */ 
int hasPathSum (struct node* node, int sum) 
{
   // return true if we run out of tree and sum==0 
   if (node == NULL) { 
      return(sum == 0); 
   } 

