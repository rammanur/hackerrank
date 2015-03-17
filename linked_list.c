/*
 * Author: Raj A
 *
 * A simple linked list implementation.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _ll_node_st {
    struct _ll_node_st *lln_next;
    struct _ll_node_st *lln_prev;
    void               *lln_data;
} ll_node_t;

typedef struct _ll_head_st {
    ll_node_t *llh_head;
    ll_node_t *llh_tail;
    uint32_t  llh_size;
} ll_head_t;

/*
 * list_enqueue: allocates a new item and point the provied data and
 * queues it at the tail of the list
 */
int
list_enqueue (ll_head_t **llist, void *node_data)
{
		ll_head_t *headp;

    /* Do we need to allocate for the list itself */
    if (!llist) {
				return -1;
    }

		if (*llist == NULL) {
				// There is no list, allocate it.
				*llist = (ll_head_t*)calloc(sizeof(ll_head_t), 1);
				assert(*llist != NULL);
		}
		headp = *llist;

		// Allocate the new element
		ll_node_t *nodep = (ll_node_t*)calloc(sizeof(ll_node_t), 1);
		assert(nodep != NULL);
		nodep->lln_prev = headp->llh_tail;
		nodep->lln_data = node_data;
		headp->llh_size++;

		if (headp->llh_tail) {
				// Queue at tail.
				headp->llh_tail->lln_next = nodep;
				headp->llh_tail = nodep;
		} else {
				// This is the first element on the list
				headp->llh_head = headp->llh_tail = nodep;
		}
		return 0;
}

/*
 * list_enqueue_head: allocates a new item and point the provied data and
 * queues it at the head of the list
 */
int
list_enqueue (ll_head_t **llist, void *node_data)
{
		ll_head_t *headp;

    /* Do we need to allocate for the list itself */
    if (!llist) {
				return -1;
    }

		if (*llist == NULL) {
				// There is no list, allocate it.
				*llist = (ll_head_t*)calloc(sizeof(ll_head_t), 1);
				assert(*llist != NULL);
		}
		headp = *llist;

		// Allocate the new element
		ll_node_t *nodep = (ll_node_t*)calloc(sizeof(ll_node_t), 1);
		assert(nodep != NULL);
		nodep->lln_prev = headp->llh_tail;
		nodep->lln_data = node_data;
		headp->llh_size++;

		if (headp->llh_tail) {
				// Queue at tail.
				headp->llh_tail->lln_next = nodep;
				headp->llh_tail = nodep;
		} else {
				// This is the first element on the list
				headp->llh_head = headp->llh_tail = nodep;
		}
		return 0;
}

/*
 * list_dequeue_node: dequeue the specified node 
 */
int
list_dequeue_node (ll_head_t *llist, ll_node_t *nodep)
{
		// THere better be a list and a node to enqueue
    if (!llist || !nodep) {
				return -1;
		}

		// Is there an element after this?
    if (nodep->lln_next) {
				nodep->lln_next->lln_prev = nodep->lln_prev;
    }

		// Is there an element before this ?
		if (nodep->lln_prev) {
				nodep->lln_prev->lln_next = nodep->lln_next;
    }

		// Are we removing the queue head?
		if (nodep == llist->llh_head) {
				llist->llh_head = nodep->lln_next;
		} 

		// Are we removing the queue tail?
		if (nodep == llist->llh_tail) {
				llist->llh_tail = nodep->lln_prev;
    }

		// Update the size and free the node.
		llist->llh_size--;
		free(nodep);
		return 0;
}

/*
 * list_dequeue: dequeue the node at the head and return
 * the data
 */
int
list_dequeue (ll_head_t *llist, void **datap)
{
		// THere better be a list and a datap
    if (!llist || !datap) {
				return -1;
		}

		ll_node_t *nodep = llist->llh_head;

		if (nodep == NULL) {
				*datap = NULL;
				return -1;
		}

		*datap = nodep->lln_data;
		return list_dequeue_node(llist, nodep);
}
