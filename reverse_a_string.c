/*
 * Author: Raj Ammanur
 *
 * Write code to reverse a C-Style String (C-String means that 
 * “abcd” is represented as five characters, including the null 
 * character )
 *
 */

/*
 * Test: ./a.out "hello world"
 *
 * Output:
 string is : hello world reverse is dlrow olleh
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void
reverseString(char *str)
{
   char *last = str;
   
   // skip to the last-1 (last is null)
   while (*last != '\0') {
      last++;
   }
   last--;

   // Now swap
   while (str < last) {
      char tmp = *last;
      *last = *str;
      *str = tmp;
      str++; last--;
    }

    return;
}

int main(int argc, char **argv)
{
   printf("string is : %s ", argv[1]);
   reverseString(argv[1]);
   printf("reverse is %s\n", argv[1]);
}
