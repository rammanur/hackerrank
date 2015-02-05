/*
 * Author: Raj A
 * Partition Method for Quick Sort
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int partition (int lo, int hi, int *  ar)
{
    int first_element = ar[lo];
    int curr_index = lo;

    // 5
    // 4 5 3 7 2
    // 3 2 4 5 7

    for (int i = lo+1; i < hi; i++) {
        //printf("processing index=%d\n", i);
        if (first_element > ar[i]) {
            //printf("ar[%d]=%d is greater than ar[%d]=%d\n", curr_index, first_element, i, ar[i]);
            for (int j = i; j > curr_index; j--) {
                int temp = ar[j];
                //printf("Swapping ar[%d]=%d ar[%d]=%d, curr_index=%d\n", j, ar[j], j-1, ar[j-1], curr_index);
                ar[j] = ar[j-1];
                ar[j-1] = temp;
            }
            curr_index += 1;
        }
        //printf("curr_index=%d, i=%d\n", curr_index, i);
    }

    /*
    printf("partition: ");
    for (int i = lo; i < hi; i++)
        printf("%d ", ar[i]);
    printf("\n");
    */
    return curr_index;
}

void quicksort (int lo, int hi, int *ar)
{
    int pindex = 0;

    if (lo >= hi) return;

    //printf("Calling partition: lo=%d hi=%d\n", lo, hi);
    pindex = partition(lo, hi, ar);

    //printf("\nCalling quicksort: pindex=%d lo=%d hi=%d\n", pindex, lo, pindex);
    quicksort(lo, pindex, ar);

    //printf("\nCalling quicksort: pindex=%d lo=%d hi=%d\n", pindex, pindex+1, hi);
    quicksort(pindex+1, hi, ar);
    
    if (lo+1 == hi) return;
    
    for (int i = lo; i < hi; i++)
        printf("%d ", ar[i]);
    printf("\n");
    
}

int main(void) {

    int _ar_size;
    
    scanf("%d", &_ar_size);
    
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    quicksort(0, _ar_size, _ar);
   
   return 0;
}

