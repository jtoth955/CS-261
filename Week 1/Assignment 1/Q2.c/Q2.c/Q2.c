/* CS261- Assignment 1 - Q.2*/
/* Name: John R Toth
 * Date: 6/24/2015
 * Solution description: Simple pointer manipulation program that passes
 * the memory address for two of three integers in main.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    int dbl = 2;
    *a *= dbl;

    /*Set b to half its original value*/
    *b /= dbl;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z = 7;
    
    /*Print the values of x, y and z*/
    printf("X = %d, Y = %d, Z = %d\n\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int c = 0;
    c = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("The value returned by foo is: %d\n\n", c);
    
    /*Print the values of x, y and z again*/
    printf("X = %d, Y = %d, Z = %d\n\n", x, y, z);
    
    /*Is the return value different than the value of z?  Why?*/
    //Yes, the return value (13) is different than Z (7) becuase the memory
    //address of Z was not passed, therefore only the copy was changed, not
    //the actual memory location that holds the value of Z.
    
    return 0;
}


