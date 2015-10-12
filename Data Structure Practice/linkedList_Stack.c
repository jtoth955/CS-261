
//fn definitions, could be placed in header file.

# ifndef LinkedListStack
# define LinkedListStack
# define TYPE int
# define EQ(a, b) (a == b)
struct link {
    TYPE value;
    struct link * next;
};

struct linkedListStack {
    struct link *firstLink;
};
# endif                             
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//function prototypes

void linkedListStackInit (struct linkedListStack * s);
void linkedListStackFree (struct linkedListStack *s);
void linkedListStackPush (struct linkedListStack *s, TYPE d);
TYPE linkedListStackTop (struct linkedListStack *s);
void linkedListStackPop (struct linkedListStack *s);
int linkedListStackIsEmpty (struct linkedListStack *s);

int main(int argc, char** argv) {
    
	//test to see if linkedlist stack works

    struct linkedListStack * list = (struct linkedListStack *)malloc(sizeof(struct linkedListStack)); 
    printf("Initializing the linked list.\n");
    linkedListStackInit(list);
    printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
    
    printf("Pushing the value 3 onto the list.\n");
    linkedListStackPush(list,3);
    printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
    printf("Top of the list = %i\n", linkedListStackTop(list));
    
    printf("Pushing the value 5 onto the list.\n");
    linkedListStackPush(list,5);
    printf("Pushing the value 8 onto the list.\n");
    linkedListStackPush(list,8);
    printf("Pushing the value 13 onto the list.\n");
    linkedListStackPush(list,13);
    
    printf("Top of the list = %i\n", linkedListStackTop(list));
    printf("Popping the list.\n");
    linkedListStackPop(list);
    
    printf("Top of the list = %i\n", linkedListStackTop(list));
    printf("Popping the list.\n");
    linkedListStackPop(list);
    
    printf("Top of the list = %i\n", linkedListStackTop(list));
    printf("Popping the list.\n");
    linkedListStackPop(list);
    
    printf("Top of the list = %i\n", linkedListStackTop(list));
    printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
    printf("Popping the list.\n");
    linkedListStackPop(list);
    
    printf("Top of the list = %i\n", linkedListStackTop(list));
    printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
    
    linkedListStackFree(list);
    
    return 0;

}
//function definitions

void linkedListStackInit(struct linkedListStack *s) {
	s->firstLink = 0;
}
void linkedListStackFree(struct linkedListStack *s) {
	while(!linkedListStackIsEmpty(s))
	{
		linkedListStackPop(s);
	}
}
void linkedListStackPush(struct linkedListStack *s, TYPE d) {
	struct link *newLink = (struct link *)malloc(sizeof(struct link));		//must cast to struct (link *) for it to work, same in main
	assert(newLink != 0);
	newLink->value = d;
	newLink->next = s->firstLink;
	s->firstLink = newLink;
}
TYPE linkedListStackTop(struct linkedListStack *s) {
	assert(!linkedListStackIsEmpty(s));
	return s->firstLink->value;
}
void linkedListStackPop(struct linkedListStack *s) {
	struct link *temp = s->firstLink;
	assert(!linkedListStackIsEmpty(s));
	s->firstLink = temp->next;
	free(temp);
}
int linkedListStackIsEmpty(struct linkedListStack *s) {
	return s->firstLink == 0;
}