/*
 * Author: Raj A
 * Return count of primes less than N
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 * Complete the function below.
 */
int getNumberOfPrimes(int N) {
    int array[N];
    
    int multiply_by = 2;
    int i = 2;
    memset(array, 0, sizeof(array));
    
    printf("Got N=%d\n", N);

repeat:
    //printf("Using multiply_by=%d\n", multiply_by);
    while (1) {
        int multiple = i*multiply_by;
        if (multiple > N)
            break;
        //printf("setting array[%d]=1\n", multiple);
        array[multiple] = 1;
        i++;
    }
    
    int j;
    for (j = multiply_by+1; j <= N; j++)
        if (array[j] == 0) break;
    
    if (j != N) {
        multiply_by = j;
        i = 2;
        if (multiply_by <= N)
           goto repeat;
    }
    
    int count = 0;
    for (int i = 2; i <= N; i++)
        if (array[i] == 0) count+=1;
    
    printf("returning count=%d\n", count);
    return count;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    int res;
    int _N;
    scanf("%d", &_N);
    
    res = getNumberOfPrimes(_N);
    fprintf(f, "%d\n", res);
    
    fclose(f);
    return 0;
}

