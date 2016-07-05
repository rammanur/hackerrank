// Find loop in a linked list using
// Floyd’s Cycle-Finding Algorithm:
#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct node
{
    struct node *next;
    int data;
};
 
void insert_node (struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
 
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
 
int find_loop (struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
    struct node *slowp, *fastp;

    slowp = list;
    fastp = list;
    while (slowp && fastp && fastp->next) {
       slowp = slowp->next;
       fastp = fastp->next->next;
       if (slowp == fastp) {
	  return 1;
       }
    }
    return 0;
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node *head = NULL;
 
    insert_node(&head, 20);
    insert_node(&head, 4);
    insert_node(&head, 15);
    insert_node(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (find_loop(head)) {
       printf("Cycle exists\n");
    }
 
    return 0;
}
