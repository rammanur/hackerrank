struct node {
    int data;
    struct node *left;
    struct node *right;
}
  

/*
 * Helper function that allocates a new node
 * with the given data and NULL left and right
 * pointers.
 */
struct node *NewNode(int data) {
    struct node *node = new(struct node);    // "new" is like "malloc"
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return(node);
}
  
/*
 * Given a binary tree, return true if a node
 * with the target data is found in the tree. Recurs
 * down the tree, chooses the left or right
 * branch by comparing the target to each node.
 */
int 
lookup (struct node *node, int target) 
{
  // 1. Base case == empty tree
  // in that case, the target is not found so return false
  if (node == NULL) {
      return(false);
  } else {
      // 2. see if found here
      if (target == node->data) {
          return(true);
      } else {
          // 3. otherwise recur down the correct subtree
          if (target < node->data) {
              return(lookup(node->left, target));
          } else {
              return(lookup(node->right, target));
          }
      }
  }
} 


int
treeCount (struct node *node)
{
    int count = 0;

    if (node == NULL) {
        return 0;
    }
    count += treeCount(node->left);   
    count += treeCount(node->right);   
    return count+1;
}

enum {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

void
printTree (struct node *node, int order)
{
    if (node == NULL) {
        return;
    }
    if (order == PRE_ORDER) printf("%d ", node->data);
    printTree(node->left, order);
    if (order == IN_ORDER) printf("%d ", node->data);
    printTree(node->right, order);
    if (order == POST_ORDER) printf("%d ", node->data);
}

/*
 * Compute the "maxDepth" of a tree -- the number of nodes along
 * the longest path from the root node down to the farthest leaf node.
 */ 
int
maxDepth (struct node *node)
{
    if (node == NULL) {
        return;
    }
    int ldepth = maxDepth(node->left);
    int rdepth = maxDepth(node->right);
    if (ldepth > rDepth) {
        return ldepth+1;
    }
    return rdepth+1;
}

/*
 * Return the minimum value found in a tree
 */
int
minValue (struct node *node)
{
    if (node == NULL) {
        return;
    }
    while (node->left != NULL) node = node->left;
    return node->data;
}

/*
 * Change a tree so that the roles of the
 * left and right pointers are swapped at every node.
 * 
 * So the tree...
 *     4
 *    / \
 *   2   5
 *  / \
 * 1   3
 *
 * is changed to...
 *     4
 *    / \
 *   5   2
 *      / \
 *     3   1
 */
void 
mirror (struct node *node) 
{
    if (node==NULL) {
      return;
    }

    struct node *tmpnode;

    mirror(node->left);
    mirror(node->right);

    // swap the pointers
    tmpnode = node->left;
    node->left = node->right;
    node->right = tmpnode;

    return;
} 
