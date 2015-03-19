#include <stdio.h>
#include <stdlib.h>
 
/* 
 * Function to get no of set bits in binary
 * representation of passed binary no. 
 */
int 
countSetBits (int n)
{
    unsigned int count = 0;
    while (n)
    {
      printf("n=%d, n-1=%d\n", n, (n-1));
      n &= (n-1) ;
      count++;
    }
    return count;
}
 
/* 
 * Program to test function countSetBits 
 */
int 
main (int argc, char **argv)
{
    int i = atoi(argv[1]);
    printf("%d", countSetBits(i));
    getchar();
    return 0;
}
