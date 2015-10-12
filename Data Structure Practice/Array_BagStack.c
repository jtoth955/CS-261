
#ifndef ArrayBagStack
#define ArrayBagStack

#define TYPE int
#define EQ(a, b) (a == b)

struct arrayBagStack {
	TYPE data [100];
	int count;
};
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//function prototypes

void initArray(struct arrayBagStack * b);

//Bag
void addArray(struct arrayBagStack * b, TYPE v);
int containsArray(struct arrayBagStack * b, TYPE v);
void removeArray(struct arrayBagStack * b, TYPE v);
int sizeArray(struct arrayBagStack * b);


//Stack
void pushArray(struct arrayBagStack * b, TYPE v);
TYPE topArray(struct arrayBagStack * b);
void popArray(struct arrayBagStack * b);
int isEmptyArray(struct arrayBagStack * b);


int main (int argc, char** argv) {

	struct arrayBagStack *a = (struct arrayBagStack *)malloc(sizeof(struct arrayBagStack));
	initArray(a);

	printf("Is stack array empty? %i\n", isEmptyArray(a));
	printf("Add 3, 2, 7, 14 & 9 to the stack, using bag.\n");
	addArray(a, 3);
	addArray(a, 2);
	addArray(a, 7);
	addArray(a, 14);
	addArray(a, 9);

	printf("the number at the top of the array is: %i\n", topArray(a));
	printf("How many numbers are now in the array? %i\n", sizeArray(a));

	printf("Remove last 2 values from the array, using stack implementation.\n");
	popArray(a);
	popArray(a);

	printf("How many numbers are now in the array? %i\n", sizeArray(a));
	printf("The number at the top of the array is now: %i", topArray(a));
	printf("\n");



	return 0;
}
void initArray(struct arrayBagStack * b) {
	b->count = 0;
}

//Bag interface fn's

void addArray(struct arrayBagStack * b, TYPE v) {
	b->data[b->count] = v;
	b->count++;
}
int containsArray(struct arrayBagStack * b, TYPE v) {
	int i; 
	for(i = 0; i < b->count; i++)
	{
		if(EQ(b->data[i], v))
			return 1;
	}

	return 0;
}
void removeArray(struct arrayBagStack * b, TYPE v) {
	int i = 0;
	int j;
	assert(containsArray(b, v));
	while(!EQ(b->data[i], v))
	{	
		i += 1;
	}
	//move elements to fill gap
	for(j = i; j < b->count-1; j++)
	{
		b->data[j] = b->data[j+1];
		b->count = b->count - 1;
	}
}
int sizeArray(struct arrayBagStack * b) {
	return b->count;
}

//Stack interface fns

void pushArray(struct arrayBagStack * b, TYPE v) {
	addArray(b, v);
}
TYPE topArray(struct arrayBagStack * b) {
	assert(b != 0);
	return (b->data[b->count - 1]);
}
void popArray(struct arrayBagStack * b) {
	assert(!isEmptyArray(b));
	b->count--;
}
int isEmptyArray(struct arrayBagStack * b) {
	return(!b->count);
}











