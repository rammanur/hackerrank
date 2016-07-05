#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct Stack {
   int *array;
	 int array_index;
	 int array_size;
	 int array_item_size;
} mystack_t;


void resize(mystack_t *stk, int new_size)
{
   void *saveptr = stk->array;

	 // Alloc the new array for items
	 stk->array = calloc(1, stk->array_item_size*new_size);
	 assert(stk->array != NULL);
	 stk->array_size = new_size;

	 // Was there an already existing array?
	 if (saveptr) {
	    // copy all the old items
	    for (int i = 0; i < stk->array_index; i++) {
	       memcpy(&stk->array[i], &saveptr[i], stk->array_item_size);
	    }

	    // free the old array
	    free(saveptr);
   }

	 return;
}

void *pop(mystack_t *stk)
{
   void *item_ptr;

   // make sure stk is valid
   if (stk == NULL) {
      return NULL;
   }

	 // get the item pointer
   item_ptr = &stk->array[--stk->array_index];

   // Half size of array if its quarter full
   if ((stk->array_index > 0) && 
       (stk->array_index == stk->array_size/4)) {
      resize(stk, stk->array_size/2);
   }

   return item_ptr;
}

int push(mystack_t *stk, void *item)
{
	 if (stk == NULL) {
	    return -1;
	 }

   if (stk->array_size == stk->array_index) {
	    resize(stk, stk->array_size*2);
	 }
	 memcpy(&stk->array[stk->array_index++], item, stk->array_item_size);
	 return 0;
}

mystack_t *stack_init(int stack_size, int item_size)
{
   mystack_t *stk;

	 stk = calloc(1, sizeof(mystack_t));
	 assert(stk != NULL);
	 stk->array_item_size = item_size;
	 resize(stk, stack_size);
	 return stk;
}
