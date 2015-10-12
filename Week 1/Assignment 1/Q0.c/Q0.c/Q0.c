/* CS261- Assignment 1 - Q. 0*/
/* Name: John R Toth
 * Date: 6/24/2015
 * Solution description: This program demonstrates the use of pointers and the values
 * that are both stored in memory, as well as the memory's physical address.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value pointed to by iptr*/
    printf("The value pointed to by iptr* is: %d\n", *iptr);
    
    /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr* is: %p\n", iptr);
    
    /*Print the address of iptr itself*/
    printf("The address of iptr is: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 0;
    
    /*print the address of x*/
    printf("The memory address of X is: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("The value of x is: %d\n", x);
    
    return 0;
}
