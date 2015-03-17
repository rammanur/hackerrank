/*
 * Author: Raj A
 *
 * File: llist.c
 * Linked list to do various llist activities
 */

struct node {
    struct node *next;
    void *data;
};

/*
 * number of items in list that match the item value
 */
int 
listCount (struct node *head, int search_item)
{
    int count = 0;
    while(head != NULL) {
        if ((int)head->data == search_item) {
            count++;
        }
        head = head->next;
    }
    return count;
}

/*
 * Combine standard list iteration with the additional problem of counting 
 * over to find the right node. Off-by-one errors are common in this sort 
 * of code. 
 * Check it carefully against a simple case. If it's right for n=0, n=1, 
 * and n=2, it will probably be right for n=1000.
 */
int 
getNth (struct node *head, int index)
{
    while (head) {
        if (count == index) {
            return (int)head->data;
        }
        count++; head = head->next;
    }
    return 0;
}

/*
 * Delete the whole list and set the head pointer to NULL. There is a 
 * slight complication inside the loop, since we need extract the next 
 * pointer before we delete the node, since after the delete it will be 
 * technically unavailable.
 */
void
deleteList (struct node **head)
{
    struct node *curr, *next;

		if ((curr = *head) == NULL) return;

		while (curr != NULL) {
		    next = curr->next;
				free(curr);
				curr = next;
		}
		*head = NULL;
		return;
}

/*
 * Extract the data from the head node, delete the node, advance the head 
 * pointer to point at the next node in line. Uses a reference parameter 
 * since it changes the head pointer.
 */
int
pop (struct node **head)
{
    struct node *curr;
		int result;

		if (head == NULL) return 0;

		curr = *head;
		*head = curr->next;
		result = (int)curr->data;
		free(curr);
		return result;
}

/*
 * The basic strategy is to iterate down the list looking for the place to 
 * insert the new node. That could be the end of the list, or a point just 
 * before a node which is larger than the new node. 
 */
void 
sortedInsert (struct node **head, struct node *newp)
{
		struct node *curr;
    if (*head == NULL) {
		    *head = newp;
				return;
		}
		curr = *head;
		if (curr->data > newp->data) {
		    *head = newp;
				newp->next = curr;
				return;
		}
		while (curr->next != NULL && curr->next->data < newp->data) {
				curr = curr->next;
		}
		newp->next = curr->next;
		curr->next = newp;
		return;
}

/*
 * Start with an empty result list. Iterate through the source list and 
 * sortedInsert() each of its nodes into the result list. Be careful to 
 * note the .next field in each node before moving it into the result list.
 */
void
sortList (struct node **head)
{
    struct node *curr, *newlist = NULL;

		if ((curr = *head) == NULL) {
		    return;
		}

		while (curr != NULL) {
		    struct node *next = curr->next;
				sortedInsert(&newlist, curr);
				curr = next;
		}

		return;
}

/*
 * Remove duplicates from a sorted list:
 *
 * Since the list is sorted, we can proceed down the list and compare 
 * adjacent nodes. When adjacent nodes are the same, remove the second one. 
 * There's a tricky case where the node after the next node needs to be 
 * noted before the deletion.
 */
void 
removeDuplicates (struct node* head) 
{
    struct node *curr = head;

		if (curr == NULL) return;

		while (curr->next != NULL) {
				struct node *next = curr->next;
		    if (curr->data == next->data) {
				    curr->next = next->next;
						free(next);
						continue;
				}
				curr = curr->next;
		}
		return;
}

/*
 * Write an iterative Reverse() function that reverses a list by rearranging 
 * all the .next pointers and the head pointer. Ideally, Reverse() should only 
 * need to make one pass of the list. The iterative solution is moderately 
 * tricky. The efficient recursive solution is quite complex 
 * (A memory drawing and some hints for Reverse() are below.)
 */
void
reverse (struct node **head)
{
    struct node *curr, *next = NULL, *prev = NULL;

		if (head == NULL) return;

		curr = *head;
		while (curr != NULL) {
		    next = curr->next;
				curr->next = prev;
				prev = current;
				curr = next;
		}
		*head = prev;
		return;
}

void
recursiveReverse (struct node **head)
{
		struct node *curr, *next;

    if (head == NULL || *head == NULL) return;

		curr = *head;
		next = curr->next;
		if (next == NULL) {
		    return;
    }
		recursiveReverse(&next);
    next->next = curr;
		curr->next = NULL;
		*head = next;
		return;
}
