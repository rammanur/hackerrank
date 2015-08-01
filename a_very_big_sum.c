/*
 * Author: Raj Ammanur
 * A Very Big Sum
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int num_integers;
    long long int sum = 0;
    
    scanf("%d", &num_integers);
    
    long long int array[num_integers];
    for (int i = 0; i < num_integers; i++) {
        scanf("%lld", &array[i]);
        sum += array[i];
        //printf ("integer %d is %lld\n", i, array[i]);
    }
    printf ("%lld\n", sum);
}
