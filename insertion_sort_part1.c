/*
 * Author: Raj A
 * Insertion sort - Part 1
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int ar_size, int *  ar) {
    if (ar == NULL) return;
    
    // 2 3 1
    int save_val = ar[ar_size-1], swapped = 0;
    for (int i = ar_size-1; i > 0; i--) {
        if (ar[i-1] >= save_val) {
            //printf("swapping %d with %d\n", ar[i], ar[i-1]);
            ar[i] = ar[i-1];
            for (int i = 0; i < ar_size; i++)
                printf("%d ", ar[i]);
            printf("\n");
        } else {
            //printf("swapping %d with %d\n", ar[i], save_val);
            ar[i] = save_val;
            swapped = 1;
            break;
        }
    }
    if (!swapped)
        ar[0] = save_val;
    
    for (int i = 0; i < ar_size; i++)
        printf("%d ", ar[i]);
    printf("\n");


    return;
}
int main(void) {
   
   int _ar_size;
   scanf("%d", &_ar_size);
   int _ar[_ar_size], _ar_i;
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
   }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
