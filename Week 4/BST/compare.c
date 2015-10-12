/* CS261- Assignment 4 - compare.c
 * Name: John R Toth
 * Date: 7/18/15
 * Solution description: compare function that returns a value based on the 
 * relationship between the values compared. 
 */

#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
    
    struct data *data1;                         //declare two variables to be 2 pointers to
    struct data *data2;                         //struct data's
    
    data1 = (struct data*)left;                //set data1 to left, but cast it to a pointer to struct data
    data2 = (struct data*)right;               //set data2 to right. Now these can be used as pointers to struct data
    
    if(data1->number < data2->number)
        return -1;
    
    if(data1->number > data2->number)
        return 1;
    
    else
        return 0;

}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/

    struct data * cur = (struct data *) curval;           //struct data TYPE cast
    printf("%s, %d\n", cur->name, cur->number);
}


