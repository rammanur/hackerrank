/*
 * Author: Raj A
 * Print the index of given value in a sorted array
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int value;
    scanf("%d", &value);
    
    int array_size;
    scanf("%d", &array_size);
        
    for (int i = 0; i < array_size; i++) {
        int aval;
        scanf("%d", &aval);
        if (value == aval) {
            printf("%d\n", i);
            break;
        }
    }
        

    return 0;
}

