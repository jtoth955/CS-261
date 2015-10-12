
#ifndef DynArrayStack
#define DynArrayStack
#define TYPE int

struct DynArr
{
	TYPE * data;	//pointer to the data array
	int size;		//number of elements in the array
	int capacity;	//capacity of the array
};
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//function prototypes

void initDynArray(struct DynArr *c, int capacity);
void freeDynArr(struct DynArr *v);
TYPE sizeDynArr(struct DynArr *v);
void addDynArr(struct DynArr *v, TYPE val);
void _setCapacityDynArr(struct DynArr *v, int newCap);
TYPE getDynArr(struct DynArr *da, int position);
void putDynArr(struct DynArr *da, int position, TYPE value);
void swapDynArr(struct DynArr *da, int i, int j);
void removeAtDynArr(struct DynArr *da, int index);
void pushDynArray(struct DynArr *da, TYPE e);
TYPE topDynArray(struct DynArr *da);
void popDynArray(struct DynArr *da);
TYPE isEmptyDynArray(struct DynArr *da);

int main (int argc, char** argv) {


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
TYPE sizeDynArr(struct DynArr * v) {
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
TYPE getDynArr(struct DynArr *da, int position) {
	assert(position >= 0 && position < da->size);
	assert(da > 0);

	return da->data[position];
}
void putDynArr(struct DynArr *da, int position, TYPE value) {
	assert(da != 0);
	assert(position >= 0);

	if(position >= 0)
	{
		_setCapacityDynArr(da, 2 * da->capacity);
	}

	da->data[position] = value;
}
void swapDynArr(struct DynArr *da, int i, int j) {
	assert(da > 0);
	assert(i >= 0 && i < da->size);
	assert(j >= 0 && j < da->size);
	
	int temp;
	temp = da->data[i];
	da->data[i] = da->data[j];
	da->data[j] = temp;
}
void removeAtDynArr(struct DynArr *da, int index) { 
	assert(da > 0);
	assert(!isEmptyDynArray(da));
	
	int x;
	for(x = index; x < da->size; x++)
	{
		da->data[x] = da->data[x + 1];
	}
	da->size--;
}

//Dynamic Array implementation of the Stack interface

void pushDynArray(struct DynArr *da, TYPE e) {
	addDynArr(da, e);
}
TYPE topDynArray(struct DynArr *da) {
	assert(da->size > 0);
	return da->data[da->size - 1];
}
void popDynArray(struct DynArr *da) {
	assert(da->size > 0);

	removeAtDynArr(da, da->size - 1);
}
int isEmptyDynArray(struct DynArr * da) {
	assert(da < 0);
	if(da->size < 1)
		return 1;

	return 0;
}