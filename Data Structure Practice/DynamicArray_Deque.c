#ifndef DynArrayDeque
#define DynArrayDeque
#define TYPE int

struct deque
{	
	TYPE * data;	//pointer to the data array
	int capacity;	//capacity of the array
	int size; 		//number of elements in the array
	int start;
};
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//function prototypes

void dequeInit(struct deque *d, TYPE initCapacity);
TYPE dequeSize(struct deque *d);
void _dequeSetCapacity(struct deque *d, TYPE newCap);
void dequeAddFront(struct deque *d, TYPE newValue);
void dequeAddBack(struct deque *d, TYPE newValue);
TYPE dequeFront(struct deque *d);
TYPE dequeBack(struct deque *d);
void dequeRemoveFront(struct deque *d);
void dequeRemoveBack(struct deque *d);
TYPE dequeIsEmpty(struct deque *d);
void dequeFree(struct deque *d);

int main(int argc, char** argv) {

	struct deque * l = (struct deque *)malloc(sizeof(struct deque));
	   
	   dequeInit(l, 10);

	   printf("Is Dynamic Array empty? = %i\n", dequeIsEmpty(l));
	   printf("Add 5 to the front.\n");
	   dequeAddFront(l,5);
	   
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));
	   
	   printf("Add 9 to the front.\n");
	   dequeAddFront(l,9);
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));
	   printf("Is Dynamic Array empty? = %i\n", dequeIsEmpty(l));
	   
	   printf("Add 12 to the front.\n");
	   dequeAddFront(l,12);
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));
	   
	   printf("Add 20 to the back.\n");
	   dequeAddBack(l,20);
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));
	   
	   printf("Remove from the back.\n");
	   dequeRemoveBack(l);
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));
	   
	   printf("Remove from the front.\n");
	   dequeRemoveFront(l);
	   printf("Front of the list = %i\n", dequeFront(l));
	   printf("Back of the list = %i\n", dequeBack(l));

	   dequeFree(l);


	return 0;
}
void dequeInit(struct deque *d, int initCapacity) {
	d->size = d->start = 0;		//set size and start to zero
	d->capacity = initCapacity;	//initialize capacity to passed value
	assert(initCapacity > 0);	
	d->data = (TYPE *)malloc(initCapacity * sizeof(TYPE));
	assert(d->data != 0);		//ensure data is not zero
}
TYPE dequeSize(struct deque *d) {
	return d->size;
}
void _dequeSetCapacity(struct deque *d, int newCap) {
	int i;
	TYPE *newData = (TYPE *)malloc(sizeof(TYPE)*newCap);	//create new underlying array
	assert(newData != 0);

	int j = d->start;
	for(i = 0; i < d->size; i++)	//copy elements to new underlying array
	{
		newData[i] = d->data[j];
		j = j + 1;
		if(j >= d->capacity)
		{
			j = 0;
		}
	}

	free(d->data);					//delete old underlying array
	
	d->data = newData;				//update cap, size, & data
	d->capacity = newCap;
	d->start = 0;
}
void dequeAddFront(struct deque *d, TYPE newValue) {
	if(d->size >= d->capacity)			//resize array if necessary
	{
		_dequeSetCapacity(d, 2 * d->capacity);
	}
	
	int beforBeginning;
	if(d->start == 0)		//if start == 0, wrap around
	{
		beforBeginning = d->capacity - 1;
		d->data[beforBeginning] = newValue;
	}
	else 
	{
		beforBeginning = d->start - 1;		//shift starting position by 1
		d->data[beforBeginning] = newValue;
	}

	d->size++;
	d->start = beforBeginning;
}
void dequeAddBack(struct deque *d, TYPE newValue) {
	if(d->size >= d->capacity)			//resize array if necessary
	{
		_dequeSetCapacity(d, 2 * d->capacity);
	}

	int index = d->start + d->size;
	if(index >= d->capacity)
	{
		index -= d->capacity;
	}
	d->data[index] = newValue;
	d->size++;
}
TYPE dequeFront(struct deque *d) {
	assert(dequeSize(d) > 0);
	
	return d->data[d->start];			
}
TYPE dequeBack(struct deque *d) {
	int index = d->start + d->size - 1;
	
	if(index > d->capacity)
	{
		index -= d->capacity;
	}

	return d->data[index];
}
void dequeRemoveFront(struct deque *d) {
	assert(!dequeIsEmpty(d));
	
	if(d->start == d->capacity - 1)
	{
		d->start = 0;
	}
	else
	{
		d->start++;
	}
	d->size--;
}
void dequeRemoveBack(struct deque *d) {
	assert(!dequeIsEmpty(d));

	d->size--;
}
TYPE dequeIsEmpty(struct deque *d) {
	return d->size == 0;
}
void dequeFree(struct deque *d) {
	free(d->data);
	d->size = 0;
	d->capacity = 0;
}
