/*
 * Author: Raj A
 * Sample Input:
 * 5
 * 1 5 7 9 11
 * 3
 * 1 3 7
 */
#include <stdio.h>
int main() {
    unsigned int num_integers;
    scanf("%d", &num_integers);
    
    unsigned int array[num_integers];
    
    for (int i = 0; i < num_integers; i++)
        scanf("%d", &array[i]);
    
    int diff1, diff2;
    for (int i = 1; i <= num_integers-1; i++) {
        diff1 = array[i] - array[i-1];
        diff2 = array[i+1] - array[i];
        if (diff1 == diff2) {
            continue;
        } 
        if (diff1 < diff2) {
            printf("%d\n", array[i]+diff1);
        } else if (diff1 > diff2) {
            printf("%d\n", array[i]-diff2);
        } 
        break;
    }
    return 0;
}
