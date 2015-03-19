/*
 * Given a string s1 and a string s2, write  a snippet to say whether s2 
 * is a rotation of s1 using only one call to strstr routine?  
 * (eg given s1 = ABCD and s2 = CDAB, return  true, given s1 = ABCD, 
 * and s2 = ACBD , return false)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char **argv)
{
    char *s1 = argv[1];
    char *s2 = argv[2];
    char s3[256];

    sprintf(s3, "%s%s", s1, s1);
    if (strstr(s3, s2)) {
        printf("s2=%s is a substring of s1=%s\n", s2, s1);
        return 1;
    } else {
        printf("s2=%s is NOT a substring of s1=%s\n", s2, s1);
        return 0;
    }
}

