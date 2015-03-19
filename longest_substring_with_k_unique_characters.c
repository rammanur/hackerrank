// C++ program to find the longest substring with k unique
// characters in a given string
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CHARS 26
 
// This function calculates number of unique characters
// using a associative array count[]. Returns true if
// no. of characters are less than required else returns
// false.

typedef enum {
    FALSE,
    TRUE,
} bool;

bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;
 
    // Return true if k is greater than or equal to val
    printf("%s.%d: Found %d unique chars\n", __FUNCTION__, __LINE__, val);
    return (k >= val);
}
 
// Finds the maximum substring with exactly k unique chars
void kUniques(char *s, int k)
{
    int u = 0; // number of unique characters
    int n = strlen(s);
 
    // Associative array to store the count of characters
    int count[MAX_CHARS];
    memset(count, 0, sizeof(count));
 
    // Traverse the string, Fills the associative array
    // count[] and count number of unique characters
    for (int i=0; i<n; i++)
    {
        if (count[s[i]-'a']==0)
            u++;
        count[s[i]-'a']++;
    }
 
    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        printf("Not enough unique characters\n");
        return;
    } else {
        printf("%s.%d: Found %d unique chars\n", __FUNCTION__, __LINE__, u);
    }
 
    // Otherwise take a window with first element in it.
    // start and end variables.
    int curr_start = 0, curr_end = 0;
 
    // Also initialize values for result longest window
    int max_window_size = 1, max_window_start = 0;
 
    // Initialize associative array count[] with zero
    memset(count, 0, sizeof(count));
 
    count[s[0]-'a']++;  // put the first character
 
    // Start from the second character and add
    // characters in window according to above
    // explanation
    for (int i=1; i<n; i++)
    {
        // Add the character 's[i]' to current window
        count[s[i]-'a']++;
        curr_end++;
 
        // If there are more than k unique characters in
        // current window, remove from left side
        while (!isValid(count, k))
        {
            count[s[curr_start]-'a']--;
            curr_start++;
        }
 
        // Update the max window size if required
        if (curr_end-curr_start+1 > max_window_size)
        {
            max_window_size = curr_end-curr_start+1;
            max_window_start = curr_start;
        }
    }
 
    s[max_window_size] = '\0';
    printf( "Max sustring is %s with length %d\n", &s[max_window_start], max_window_size);
}
 
// Driver function
int 
main(int argc, char **argv)
{
    char string_array[] = "aabacbebebe";
    char *s = string_array;
    int k = 3;

    if (argc > 1) {
        s = argv[1];
        k = atoi(argv[2]);
    }
    kUniques(s, k);
    return 0;
}
