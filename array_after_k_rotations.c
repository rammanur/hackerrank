/*
 * Author: Raj A
 * N-sized Array Values after K rotations
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, K, Q;
    
    scanf("%d %d %d", &N, &K, &Q);
    
    unsigned int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
        
    for (int i = 0; i < Q; i++) {
        unsigned int array_index;
        scanf("%d", &array_index);
        
        int position = (array_index-K+N)%N;
        //printf("pos=%d newpos=%d: val=%d\n", array_index, position, array[position]);
        printf("%u\n", array[position]);
    }
    return 0;
}
