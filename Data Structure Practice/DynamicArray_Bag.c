#ifndef DynArrBag
#define DynArrBag
#define TYPE int
#define EQ(A, B) (A == B)
#endif

struct DynArr
{
	TYPE *data;	//pointer to the data array
	int size;		//number of elements in the array
	int capacity;	//capacity of the array
};

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//function prototypes

void initDynArray(struct DynArr *v, TYPE capacity);
void freeDynArr(struct DynArr *v);
TYPE sizeDynArr(struct DynArr *v);
void addDynArr(struct DynArr *v, TYPE val);
void _setCapacityDynArr(struct DynArr *v, TYPE newCap);
TYPE getDynArr(struct DynArr *v, TYPE position);
void putDynArr(struct DynArr *v, TYPE position, TYPE value);
void swapDynArr(struct DynArr *v, TYPE i, TYPE j);
void removeAtDynArr(struct DynArr *v, TYPE index);
void removeDynArr(struct DynArr *v, TYPE test);
TYPE containsDynArr(struct DynArr *v, TYPE e);
TYPE isEmptyDynArr(struct DynArr *v);

int main(int argc, char** argv) {




	return 0;
}


void initDynArray(struct DynArr *v, int capacity) {
	v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);		//check that data is not empty

	v->size = 0;				//initialize size to 0
	v->capacity = capacity;		//initialize capacity to passed value
}
void freeDynArr(struct DynArr *v) {
	if(v->data != 0)
	{
		free(v->data);			//free the space on the heap
		v->data = 0;			//make is point to null
	}
	v->size = 0;
	v->capacity = 0;
}
TYPE sizeDynArr(struct DynArr *v) {
	return v->size;				
}
void addDynArr(struct DynArr *v, TYPE val) {
	if(v->size == v->capacity)	//check to see if re-size is necessary
		_setCapacityDynArr(v, 2 * v->capacity);

	v->data[v->size] = val;
	v->size++;
}
void _setCapacityDynArr(struct DynArr *v, int newCap) {
	int i;
	TYPE *newArr = (TYPE *)malloc(newCap * sizeof(TYPE));

	for(i = 0; i < v->size; i++ )
	{
		newArr[i] = v->data[i];
	}
	
	free(v->data);
	v->capacity = newCap;
	v->data = newArr;
}
TYPE getDynArr(struct DynArr *v, TYPE position) {
	assert(v != 0);
	assert(!isEmptyDynArr(v));

	return v->data[position];
}
void putDynArr(struct DynArr *v, int position, TYPE value) {
	assert(v != 0);
	
	if(position >= 0)
	{
		_setCapacityDynArr(v, 2 * v->capacity);
	}

	v->data[position] = value;
}
void swapDynArr(struct DynArr *v, TYPE i, TYPE j) {
	assert(v > 0);
	assert(!isEmptyDynArr(v));
	
	int temp;
	temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}
void removeAtDynArr(struct DynArr *v, TYPE index) { 
	assert(v > 0);
	assert(!isEmptyDynArr(v));

	int x;
	for(x = index; x < v->size; x++)
	{
		v->data[x] = v->data[x + 1];
	}
	
	v->size--;
}

//Building a Bag using Dynamic Array

void removeDynArr(struct DynArr *v, TYPE test) {
	int i; 
	for(i = 0; i < v->size; i++)
	{
		if(EQ(test, v->data[i]))
		{
			removeAtDynArr(v, i);
			return;
		}
	}
}
TYPE containsDynArr(struct DynArr *v, TYPE e) {
	assert(!isEmptyDynArr(v));

	int i; 
	for(i = 0; i < v->size; i++)
	{
		if(v->data[i] == e)
		{
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
TYPE isEmptyDynArr(struct DynArr *v) {
	return v->size == 0;
}












