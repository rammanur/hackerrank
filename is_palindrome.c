/*
 * Author: Raj Ammanur
 *
 * Write code to check if given string is a palindrome
 */

/*
 * Test: 
 * ./a.out "I am not a palindrome"
 * ./a.out "radar"
 * ./a.out "Aibohphobia"
 * ./a.out "As I pee, sir, I see Pisa"
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Below function works for strings with no spaces
 * ./a.out "I am not a palindrome": Works
 * ./a.out "radar": Works
 * ./a.out "Aibohphobia": Works
 * ./a.out "As I pee, sir, I see Pisa": Fails
 */
int
is_a_palindrome_for_strings_only(char *str)
{
   int len = 0;
   char *saveptr = str;

   while(*str) {
      len++; str++;
   }
   
   //printf("str=%s is %d long\n", str, len);
   str = saveptr;
   for(int i = 0; i < len/2; i++) {
      //printf("comparing: %c vs %c\n", str[i], str[len-i-1]);
      if(tolower(str[i]) != tolower(str[len-i-1])) {
         return 0;
      }
   }

   return 1;
}

int main(int argc, char **argv)
{
   printf("String `%s` is : %s \n", argv[1],
      (is_a_palindrome_for_strings_only(argv[1]) ? "Palindrome" : "not Palindrome"));
}
