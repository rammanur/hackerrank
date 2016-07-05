/*
 * Author: Raj Ammanur
 *
 * Reverse words in a given string
 *
 */

/*
 * Test: ./a.out “i like this program very much”
 *
 * Output:
 “much very program this like i”
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void
reverseString(char *str)
{
   char *last = str, *saveptr = str;
   char savebuf[256];

   strcpy(savebuf, str);
   
   // skip to the last-1 (last is null)
   while (*last) {
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

    //printf("orig: %s swapped: %s\n", savebuf, saveptr);

    return;
}

void
reverseSentence(char *str)
{
   char *sptr = str;

   if (sptr == NULL) return;

   /* reverse individual words of sentence */
   char *start = sptr;
   while(*sptr) {
      if (*sptr == ' ') {
	 *sptr = '\0';
         reverseString(start);
	 *sptr = ' ';
	 start = sptr+1;
      } else if (*(sptr+1) == '\0') {
         reverseString(start);
	 break;
      }
      sptr++;
   }

   /* reverse the whole sentence */
   reverseString(str);
}

int main(int argc, char **argv)
{
   printf("Orig string: %s\n", argv[1]);
   reverseSentence(argv[1]);
   printf("Reverse: %s\n", argv[1]);
}
