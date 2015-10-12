/* CS261- Assignment 1 - Q.4*/
/* Name: John R Toth
 * Date: 6/24/2015
 * Solution description: C program that creates an array and 
 * assigns random integer values to two struct variables. The program
 * then sorts the array in ascending order, based on highest score.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
    int id;
    int score;
};

void sort(struct student* students, int n){
    /*Sort the n students based on their score*/
    int z = 0, a = 0;
    
    for(int x = 0; x < n; x++)
    {
        for(int y = x + 1; y < n; y++)
        {
            if(students[x].score > students[y].score)
            {
                z = students[x].score;
                students[x].score = students[y].score;
                students[y].score = z;
                
                a = students[x].id;
                students[x].id = students[y].id;
                students[y].id = a;
            }
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    struct student* s = malloc(n * sizeof(struct student));
    
    
    /*Generate random IDs and scores for the n students, using rand().*/
    for(int x = 0; x < n; x++)
    {
        s[x].id = rand() % 30 + 1;
        s[x].score = rand() % 100 + 1;
        
    }

    /*Print the contents of the array of n students.*/
    int z = 1;
    printf("\nPre-sorted list:\n\n");
    
    for(int y = 0; y < n; y++)
    {
        printf("ID %d: %d" "\tScore %d: %d\n", z, s[y].id, z, s[y].score);
        z++;
    }
    
    /*Pass this array along with n to the sort() function*/
    sort(s, n);
    
    /*Print the contents of the array of n students.*/
    int c = 1;
    printf("\nPost-sorted list:\n\n");
    
    for(int d = 0; d < n; d++)
    {
        printf("ID %d: %d" "\tScore %d: %d\n", c, s[d].id, c, s[d].score);
        c++;
    }
    
    return 0;
}
