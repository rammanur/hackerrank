/*
 * AUTHOR: Raj A
 * Diameter of Tree
 * Passed 15/17
 */

/* Write your custom functions here */
int maxDepth (struct node *node)
{
   if (node == NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
} 

int diameterOfTree(node * root) {
/* For your reference
  struct node {
   struct node *left,*right;
   int val;
};
*/
    return 1 + maxDepth(root->left) + maxDepth(root->right);
}

int main(){
   
   FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
   node * root = NULL;
   int a[1000],K,i = 0,j = 0;
   int isBst = 0; scanf("%d",&isBst);    
   
   scanf("%d",&K);
   for( j = 0; j < K;j++ ) {
       scanf("%d",&a[i++]);    
   }

   for( i = 0; i < K;i++ ){
       if( !isBst ){            
           root = addRandomElement(root,a[i],i);
       } else {
           root = addElement(root,a[i]);
       }            
   }
   fprintf(f, "%d\n", diameterOfTree(root));
   fclose(f);
   
return 0;
}
node * addElement(node * root, int x ){
   if( root == NULL ) {
       root = (node *) (malloc(sizeof(node))); 
       root->val = x;root->val1 = -1;
               root->left = NULL; root->right = NULL;
       return root;
   }
   if( x < root->val ) {
        root->left = addElement(root->left,x);
   }
   else {
       root->right = addElement(root->right,x);                            
   }
   return root;
}

node * addRandomElement(node *root, int x, int index){
   if( root == NULL ) {
       root = (node *) (malloc(sizeof(node))); 
       root->val = x;root->val1 = -1;
               root->left = NULL; root->right = NULL;
               return root;
   }

   if( index <=2 ){
       root->left = addRandomElement(root->left,x,index);
   } else {
       root->right = addRandomElement(root->right,x,index);
   }

   return root;
}
