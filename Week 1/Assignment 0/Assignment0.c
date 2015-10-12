/***********************************************************************************
 *Filename: Assignment0.c
 *Name: John R Toth
 *Date: 6/23/15
 *Description: Simple program that determines if value is
 *Input: User defined int value
 *Output: Whether the value is odd or even
 ***********************************************************************************/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int val;
    
    printf("Enter a number and I'll tell you if it's odd or even: ");
    
    scanf("%d", &val);
    
        if(val < 0)
            printf("Invalid number!\n");
        
        else if(val % 2)
            printf("Your number is odd!\n");

        else
            printf("Your number is even!\n");
        

    return 0;
}
