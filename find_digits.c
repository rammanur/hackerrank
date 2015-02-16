/*
 * Author: Raj A
 *
 * You are given an integer N. Find the digits in this number that 
 * exactly divide N(division that leaves 0 as remainder) and display 
 * their count. For N=24, there are 2 digits − 2 & 4. Both of these 
 * digits exactly divide 24. So our answer is 2.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void count_numbers (unsigned int input_num, int *array)
{
    int original_num = input_num;

    //printf("original_num=%d\n", original_num);
    while (input_num) {
        int mod = input_num % 10;
        //printf("input_num=%d mod=%d\n", input_num, mod);
        if (mod && ((original_num/mod)*mod) == original_num) {
            //printf("incrementing array[%d]\n", mod);
            array[mod]++;
        }
        input_num /= 10;
    }
    return;
}

int main() {
    int num_test_cases = 0;
    scanf("%d", &num_test_cases);
    //printf("num_test_cases=%d\n", num_test_cases);

    int *array = calloc(10, sizeof(int));

    for (int i = 0; i < num_test_cases; i++) {
        unsigned int input_num = 0;
        scanf("%u", &input_num);
        //printf("input_num=%d\n", input_num);

        count_numbers(input_num, array);
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (array[j] != 0)
                count += array[j];
        }
        printf ("%d\n", count);
        for (int j = 0; j < 10; j++) {
	    array[j] = 0;
	}
    }
    return 0;
}

