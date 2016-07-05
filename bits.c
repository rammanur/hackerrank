#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned int a = 0x400;
unsigned int b = 0x15;

int main ()
{
   unsigned int x = b;
   x = x<<2;
   x = (x<<(31-6))>>(31-6);
   printf("x is 0x%x num is 0x%x\n", x, (a | x));
   return 0;
}
