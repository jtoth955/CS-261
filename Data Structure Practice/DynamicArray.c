
#ifndef DynamicArray
#define DynamicArray
#define TYPE int

struct DynArr
{
	TYPE * data;	//pointer to the data array
	int size;		//number of elements in the array
	int capacity;	//capacity of the array
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//function prototypes

void initDynArray(struct DynArr *v, TYPE capacity);
void freeDynArr(struct DynArr *v);
TYPE sizeDynArr(struct DynArr *v);
void addDynArr(struct DynArr *v, TYPE val);
void _setCapacityDynArr(struct DynArr *v, TYPE newCap);
TYPE getDynArr(struct DynArr *v, TYPE position);
TYPE putDynArr(struct Dynarr *v, TYPE position, TYPE value);
void swapDynArr(struct DynArr *v, TYPE i, TYPE j);
void removeAtDynArr(struct DynArr *v, TYPE index);
void printDynArr(struct DynArr *v);

int main(int argc, char** argv){

	struct DynArr *a = (struct DynArr *)malloc(sizeof(struct DynArr));
	initDynArray(a, 10);

	printf("The current size of the Dynamic Array: %i\n", sizeDynArr(a));
	printf("Adding 3, 2, 7, 14, 5 & 4 to the Dynamic array\n");
	addDynArr(a, 3);
	addDynArr(a, 2);
	addDynArr(a, 7);
	addDynArr(a, 14);
	addDynArr(a, 5);
	addDynArr(a, 4);

	printf("Now, the size of the Dynamic Array is: %i\n", sizeDynArr(a));
	printDynArr(a);
	printf("Removing value at index 0, which should be 3.\n");
	removeAtDynArr(a, 0);
	printf("Now, the size of the Dynamic Array is: %i\n", sizeDynArr(a));
	printDynArr(a);

	printf("Now, swap index 0 with index 3\n");
	swapDynArr(a, 0, 3);
	printDynArr(a);

	printf("\nDeleting the Dynamic Array\n");
	freeDynArr(a);


return 0;

}
void initDynArray(struct DynArr *v, TYPE capacity) {
	v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);		//check that data is not empty

	v->size = 0;				//initialize size to 0
	v->capacity = capacity;		//initialize capacity to passed value
}
void freeDynArr(struct DynArr *v) {
	if(v->data != 0)
	{
		free(v->data);			//free the space on the heap
		v->data = 0;			//make it  point to null
	}
	v->size = 0;
	v->capacity = 0;

	printf("\nContents of Dynamic Array have been deleted!\n");
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
void _setCapacityDynArr(struct DynArr *v, TYPE newCap) {
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
TYPE getDynArr(struct DynArr * v, TYPE position) {
	assert(position >= 0 && position < v->size);
	assert(v > 0);

	return v->data[position];
}
void putDynArr(struct DynArr *v, TYPE position, TYPE value) {
	assert(v != 0);
	assert(position >= 0);

	if(position >= 0)
	{
		_setCapacityDynArr(v, 2 * v->capacity);
	}

	v->data[position] = value;
}
void swapDynArr(struct DynArr *v, TYPE i, TYPE j) {
	assert(v > 0);
	assert(i >= 0 && i < v->size);
	assert(j >= 0 && j < v->size);
	
	int temp;
	temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}
void removeAtDynArr(struct DynArr *v, TYPE index) { 
	assert(v > 0);
	assert(v->size > 0);
	assert(index < v->size && index >= 0);

	int x;
	for(x = index; x < v->size; x++)
	{
		v->data[x] = v->data[x + 1];
	}
	v->size--;
}
void printDynArr(struct DynArr *v) {
	int i; 

	printf("The Dynamic Array's contents are:\n");
	for(i = 0; i < v->size; i++)
	{
		printf("%i ", v->data[i]);
	}
	printf("\n");
}
