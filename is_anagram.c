/*
 * Author: Raj Ammanur
 *
 * Write a method to decide if two strings are anagrams or not
 *
 */

/*
 * Test: ./a.out iceman cinema
 *
 * Output:
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int
is_anagram(char *str1, char *str2)
{
   int str1count = 0, str2count = 0;
   while(*str1) {
      str1count += *str1 - '0';
      str1++;
   }
   while(*str2) {
      str2count += *str2 - '0';
      str2++;
   }
   printf("str1count=%d str2count=%d\n", str1count, str2count);
   return str1count == str2count;
}

int main(int argc, char **argv)
{
   printf("Orig strings: %s, %s\n", argv[1], argv[2]);
   printf("Is_anagram: %s\n", 
      (is_anagram(argv[1], argv[2]) == 1) ? "TRUE" : "FALSE");
}
