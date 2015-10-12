/* CS261- Assignment 1 - Q.3*/
/* Name: John R Toth
 * Date: 6/24/2015
 * Solution description: C program that randomly assigns 20 random integers
 * to an array, prints the list, then sorts the list, then prints the sorted
 * list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    int z = 0;
    
    for(int x = 0; x < n; x++)
    {
        for(int y = x + 1; y < n; y++)
        {
            if(number[x] > number[y])
            {
                z = number[x];
                number[x] = number[y];
                number[y] = z;
            }
        }
    }

}

int main(){
    
    srand((unsigned)time(NULL));
    
    /*Declare an integer n and assign it a value of 20.*/
    int *n;
    
    /*Allocate memory for an array of n integers using malloc.*/
    n = (int *)malloc(sizeof(int));
    
    if(n == 0)
    {
        printf("Error: Out of Memory!\n");
        return 1;
    }
    
    *n = 20;
        
    /*Fill this array with random numbers, using rand().*/
    for(int x = 0; x < 20; x++)
    {
        //I imposed an upperbound value
        n[x] = (rand() % 100 + 1);
    }
    
    /*Print the contents of the array.*/
    printf("This is the unsorted array list:\n\n");
    
    int a = 1;
    for(int x = 0; x < 20; x++)
    {
        printf("%d. %d\n", a, n[x]);
        a++;
    }
    
    /*Pass this array along with n to the sort() function of part a.*/
    int num = 20;
    sort(n, num);
    
    /*Print the contents of the array.*/
    printf("\nThis is the sorted array list:\n\n");
 
    int b = 1;
    for(int x = 0; x < 20; x++)
    {
        printf("%d. %d \n", b, n[x]);
        b++;
    }

    /*I can free the memory on home enviro, but it glibc seg faults on FLIP? Why?
    free(n);
    */ 
    
    return 0;
}
