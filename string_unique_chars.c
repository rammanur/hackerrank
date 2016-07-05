/*
 * Author: Raj Ammanur
 *
 * Implement an algorithm to determine if a string has all 
 * unique characters What if you can not use additional 
 * data structures?
 */

/*
 * test: for i in hello helo hel10 hel100 1234567890; do ./a.out $i; done
 *
 * Output:
 string: hello is not unique
 string: helo is unique
 string: hel10 is unique
 string: hel100 is not unique
 string: 1234567890 is unique
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int use_brute_force = 0;

int efficientIsUniqueChars2(char *str)
{
   int char_array[256];

   memset(&char_array, 0, 256);
   while((*str) != '\0') {
      char s = *str;
      int ascii_val = s-'0';
      int value = char_array[ascii_val];
      if (value != 0) {
         return 0;
      }
      char_array[ascii_val] = 1;
      str++;
   }
   return 1;
}

int bruteForceIsUniqueChars2(char *str)
{
   char *ptr = str;

   if (ptr == NULL) return 1;

   int str_len = strlen(str);
   int start_index = 1;

repeat_check:
   for(int i = start_index; i < str_len; i++) {
      if (*ptr == str[i]) {
         return 0;
      }
   }
   start_index++;
   if (start_index < str_len) {
      ptr++;
      goto repeat_check;
   }
   return 1;
}

int isUniqueChars2(char *str) 
{
   if (use_brute_force) {
      return bruteForceIsUniqueChars2(str);
   } else {
      return efficientIsUniqueChars2(str);
   }
}

int main(int argc, char **argv)
{
   printf("string: %s is %s\n", argv[1], 
      isUniqueChars2(argv[1]) ? "unique" : "not unique");
}
