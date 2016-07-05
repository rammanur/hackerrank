/*
 * Author: Raj Ammanur
 *
 * Design an algorithm and write code to remove the duplicate characters 
 * in a string without using any additional buffer 
 *
 * NOTE: One or two additional variables are fine An extra copy of the 
 * array is not
 */

/*
 * Test: ./a.out "hello world"
 *
 * Output:
 string is : hello world reverse is dlrow olleh
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int use_brute_force = 1;

void
removeDupChars_bruteforce(char *str)
{
   char *curr = str, *next = str+1;

   while(*curr) {
      next = curr+1;

      //printf("curr=%c next=%c\n", *curr, *next);

      /* Look for duplicate */
      while(*next) {
         if (*curr == *next) {
	    // get rid of the duplicate
	    //printf("removing duplicate: %c\n", *curr);
	    char *tmpptr = next;
	    while (*tmpptr) {
	      //printf("replacing %c with %c\n", *tmpptr, *(tmpptr+1));
	      *tmpptr = *(tmpptr+1);
	      tmpptr++;
	    }
	 } else {
	    next++;
	 }
      }
      curr++;
   }
   
   return;
}

int main(int argc, char **argv)
{
   if (argv[1] == NULL) exit(-1);

   printf("-------------------\n");
   printf("Orig string: %s\n", argv[1]);
   removeDupChars_bruteforce(argv[1]);
   printf("Modified: %s\n", argv[1]);
   printf("-------------------\n");
   exit(0);
}
