#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, unsigned int n)
{
   /* calculate number of bits in type */
   size_t s = sizeof(x) * CHAR_BIT;
   size_t p;

   /* limit shift to range 0 - (s - 1) */
   if(n < s)
       p = n; 
   else
       p = n % s;

   /* if either is zero then the original value is unchanged */
   if((0 == x) || (0 == p))
       return x;

   return (x >> p) | (x << (s - p));
}

/* Driver based on yours but runs the shift values beyond the size of an
unsigned integer on any system */

int main(void)
{
   unsigned int val;
   unsigned int pos;
   unsigned int max = sizeof (pos) * CHAR_BIT + 1;

   for(val = 0; val < 700; val += 49)
   {
      for(pos = 0; pos < max; ++pos)
      {
         printf("%u, %d: %u\n", x, n, rightrot(val, pos));
      }
   }
}

