/*
 * Author: Raj A
 * Naive method to find if left sum is equal to right sum, given a pivot
 * in an array.
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int num_test_cases = 0;
    int num_elements = 0, print_yes = 0;
    
    scanf("%d", &num_test_cases);
    
repeat:
    num_elements = print_yes = 0;
    scanf("%d", &num_elements);
    
    //printf("num_test_cases=%d num_elements=%d\n", num_test_cases, num_elements);
    
    // populate the array
    unsigned int sherlock_array[num_elements];
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &sherlock_array[i]);
    }
    
    if (num_elements == 1) {
        //printf("Skipping everything, num_elements=1\n");
        print_yes = 1;
        goto skip_everything;
    }
    
    //printf("Sherlock_array: ");
    //for (int i = 0; i < num_elements; i++) {
    //    printf("%d ", sherlock_array[i]);
    //}
    //printf("\n");
    
    // check for sum of elements of left == sum of elements of right
    unsigned int lsum = 0, rsum = 0;
    
    for (int j = 1; j < num_elements; j++) {
        rsum += sherlock_array[j];
    }
    //printf("Rsum=%d\n", rsum);

    for (int i = 1; i < num_elements; i++) {
        lsum += sherlock_array[i-1];
        rsum -= sherlock_array[i];
        if (lsum == rsum) {
            print_yes = 1;
        }
        //printf("i=%d lsum=%d rsum=%d\n", i, lsum, rsum);
    }

skip_everything:
    if (print_yes) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    
    // are there most test cases to run ?
    if (--num_test_cases)
        goto repeat;
    
    return 0;
}

