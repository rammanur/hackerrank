int Count (struct node* head, int searchFor)
{
   int count = 0;
   while (head != NULL) {
      if (searchFor == head->data) {
         count++;
      }
      head = head->next;
   }
   return count;
}

int GetNth (struct node* head, int index)
{
   int currIndex = 0;
   while (head != NULL) {
      if (index == currIndex) {
         return head;
      }
      currIndex++;
   }
   return NULL;
}

struct node *allocNode (int data)
{
    return calloc(1, sizeof(struct node));
}

void InsertNth (struct node** headRef, int index, int data)
{
   int currIndex = 0;
   struct node *currNode = NULL;

   assert(headRef != NULL);
   if (index == 0) {
      Push(headRef, data);
      return;
   }

   // Find the node before the index where we want to insert
   currNode = *headRef;
   while (currIndex < index-1) {
      currIndex++;
      assert(currNode != NULL);
      currNode = currNode->next;
   }

   // Insert the node
   Push(&(currNode->next), data);

   return;
}

/*
 * Iterative list reverse.
 * Iterate through the list left-right.
 * Move/insert each node to the front of the result list --
 * like a Push of the node.
 */
static void Reverse1 (struct node** headRef) 
{
   struct node *curr = NULL;
   struct node *result = NULL;
   struct node *next = NULL;

   curr = *headRef;
   while (curr != NULL) {
      next = curr->next;
      curr->next = result;
      result = curr;
      curr = next;
   }
   *headRef = result;
}

void Reverse2 (struct node** headRef) 
{
    struct node *front;
    struct node *curr;
    struct node *back;

    curr = *headRef;
    front = curr->next;
    back = NULL;

    while (1) {
       curr->next = back;
       if (front == NULL) {
          return;
       }
       back = curr;
       curr = front;
       front = front->next;
    }
}

void RecursiveReverse (struct node **headRef)
{
   struct node *first, *rest;

   if (*headRef == NULL) {
      return;
   }
   first = *headRef;
   rest = first->next;

   if (rest == NULL) {
      return;
   }

   RecursiveReverse(&rest);
   first->next->next = first;
   first->next = NULL;
   *headRef = rest;
}


void Reverse (struct node** headRef) 
{
   if (headRef == NULL || 
       *headRef == NULL || 
       *headRef->next == NULL) {
      return;
   }
   return Reverse1(headRef);
}

void Push (struct node **headRef, int data)
{
   struct node *currNode = *headRef;
   struct node *newEntry = allocNode(data);

   *headRef = newEntry;
   newEntry->next = currNode;

   return;
}

/*
 * The opposite of Push(). Takes a non-empty list
 * and removes the front node, and returns the data
 * which was in that node.
 */
int Pop (struct node** headRef) 
{
   struct node *top;
   int data;

   if (headref == NULL || *headref == NULL) {
      return 0;
   }
   top = *head;
   *head = top->next;
   data = top->data;
   free(top);

   return data;
}

// Build and return the list {1, 2, 3}
struct node* BuildOneTwoThree() 
{
   struct node* head = NULL; // Start with the empty list
   Push(&head, 3); // Use Push() to add all the data
   Push(&head, 2);
   Push(&head, 1);
   return(head);
}

// Remove duplicates from a sorted list
void RemoveDuplicates (struct node* head) 
{
   while (head->next != NULL) {
      if (head->data == head->next->data) {
	 struct n28894ode *dup = head->next;
         head->next = dup->next;
	 free(dup);
	 return;
      }
   }
   return;
}

void printList (struct node *head)
{
   if (head == NULL) {
      printf("Nothing to print in list..\n");
      return;
   }
   while (head != NULL) {
      printf("currNode = %p, data=0x%x\n", head, head->data);
      head = head->next;
   }
   return;
}

void PopTest ()
{
   struct node* head = BuildOneTwoThree(); // build {1, 2, 3}
   int a = Pop(&head); // deletes "1" node and returns 1
   int b = Pop(&head); // deletes "2" node and returns 2
   int c = Pop(&head); // deletes "3" node and returns 3
   int len = Length(head); // the list is now empty, so len == 0
}

void DeleteListTest (struct node **head)
{
   struct node *curr;
   if (head == NULL || *head == NULL) {
      return;
   }
   while ((curr = *head) != NULL) {
      *head = *head->next;
      free(curr);
   }

   // print the list and make sure nothing prints
   printList(*head);
   return;
}
