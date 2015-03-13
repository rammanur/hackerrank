/*
 * Author: Raj A
 *
 * Check if passed in line is a pangram
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char c;
    char array[26];
    int count = 0;
    memset(array, 0, sizeof(array));
    while ((scanf("%c", &c)) != EOF) {
        if (isalpha(c)) {
            int pos = tolower(c) - 'a';
            if (array[pos]) {
                continue;
            }
            array[pos]++;
            count++;
        } 
    }
    if (count == 26) {
        printf("pangram");
    } else {
        printf("not pangram");
    }
    return 0;
}

