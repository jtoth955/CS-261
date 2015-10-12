/* CS261- Assignment 1 - Q.1*/
/* Name: John R Toth
 * Date: 6/24/14
 * Solution description: C Program that calculates min, max and average test scores
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
    int id;
    int score;
};

struct student* allocate() {
    
    /*Allocate memory for ten students*/
    int numStudents = 10;
    
    struct student* s = malloc(numStudents * sizeof(struct student));
    
    /*return the pointer*/
    return s;
}

void generate(struct student* students){
    /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
 
    for(int x = 0;  x < 10; x++)
    {
        students[x].id = (rand() % 10 + 1);
        students[x].score = (rand() % 100 + 1);
    }
    
}

void output(struct student* students){
    /*Output information about the ten students in the format:
     ID1 Score1
     ID2 score2
     ID3 score3
     ...
     ID10 score10*/
    
    int n = 1;
    
    for(int x = 1;  x < 11; x++)
    {
        printf("ID %d: %d" "\tScore %d: %d\n", n, students[x].id, n, students[x].score);
        n++;
    }

}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/

    int sum = 0, avg = 0, min = 100, max = 0;
    
    for(int x = 0;  x < 10; x++)
    {
        if(students[x].score < min)
        {
            min = students[x].score;
        }
        if(students[x].score > max)
        {
            max = students[x].score;
        }
            
        sum += students[x].score;
    }
    
    avg = (sum / 10);
    
    printf("\nThe Minimum Score was: %d\n", min);
    printf("The Maximum Score was: %d\n", max);
    printf("The Average Score was: %d\n\n", avg);
    
}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    srand((unsigned)time(NULL));
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);
    
    return 0;
}
