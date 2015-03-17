/*
 * Author: Raj A
 *
 * Test driver for my simple linked list implementation.
 */

#define list_push(list, value) do { \
   typeof (*list) _v_copy = (typeof (*list)) value; \
   list_enqueue((ll_head_t **) &list, sizeof (_v_copy), &_v_copy); \
} while (0) \


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int 
main (int argc, char * argv [])
{
		list (int, list);
		memset (&list, 0, sizeof (list));
		assert (list_length (list) == 0);
		list_enqueue(list, 6);
		list_enqueue_head(list, 5);
		list_enqueue(list, 7);
		list_enqueue(list, 8);
		list_enqueue(list, 9);
		list_enqueue(list, 10);

    list_enqueue_head(list, 4);
    list_enqueue_head(list, 3);
    list_enqueue_head(list, 2);
    list_enqueue_head(list, 1);
    list_enqueue_head(list, 0);

}
