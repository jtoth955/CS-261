
#ifndef LinkedListDeque
#define LinkedListDeque
#define TYPE int

struct link {
	TYPE value;
	struct link *next;
	struct link *prev;
};
struct listDeque {
	int size;
	struct link *frontSentinel;
	struct link *backSentinel;
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//function prototypes

void linkedDequeInit(struct listDeque *q);
void linkedDequeFree(struct listDeque *q);
void linkedDequeAddFront(struct listDeque *q, TYPE e);
void linkedDequeAddBack(struct listDeque *q, TYPE e);
void linkedDequeRemoveFront(struct listDeque *q);
void linkedDequeRemoveBack(struct listDeque *q);
TYPE linkedDequeIsEmpty(struct listDeque *q);
void _addBefore(struct listDeque *q, struct link *lnk, TYPE e);
void _removeLink(struct listDeque *q, struct link *lnk);
TYPE linkedDequeFront(struct listDeque *q);
TYPE linkedDequeBack(struct listDeque *q);

int main(int argc, char** argv) {

	struct listDeque * l = (struct listDeque *)malloc(sizeof(struct listDeque));
	   
	   linkedDequeInit(l);

	   printf("Is linked list empty? = %i\n", linkedDequeIsEmpty(l));
	   printf("Add 5 to the front.\n");
	   linkedDequeAddFront(l,5);
	   
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));
	   
	   printf("Add 9 to the front.\n");
	   linkedDequeAddFront(l,9);
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));
	   printf("Is linked list empty? = %i\n", linkedDequeIsEmpty(l));
	   
	   printf("Add 12 to the front.\n");
	   linkedDequeAddFront(l,12);
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));
	   
	   printf("Add 20 to the back.\n");
	   linkedDequeAddBack(l,20);
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));
	   
	   printf("Remove from the back.\n");
	   linkedDequeRemoveBack(l);
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));
	   
	   printf("Remove from the front.\n");
	   linkedDequeRemoveFront(l);
	   printf("Front of the list = %i\n", linkedDequeFront(l));
	   printf("Back of the list = %i\n", linkedDequeBack(l));

	   linkedDequeFree(l);


	return 0;
}
void linkedDequeInit(struct listDeque *q) {
	q->frontSentinel = (struct link *)malloc(sizeof(struct link));
	assert(q->frontSentinel != 0);
	q->backSentinel = (struct link *)malloc(sizeof(struct link));
	assert(q->backSentinel);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinel;
	q->size = 0;
}
void linkedDequeFree(struct listDeque *q) {
	while(q->size > 0)
	{
		linkedDequeRemoveFront(q);
	}
	free(q->frontSentinel);
	free(q->backSentinel);
	q->frontSentinel = q->backSentinel = NULL;
}
void linkedDequeAddFront(struct listDeque *q, TYPE e) {
	_addBefore(q, q->frontSentinel->next, e);
}
void linkedDequeAddBack(struct listDeque *q, TYPE e) {
	_addBefore(q, q->backSentinel, e);
}
void linkedDequeRemoveFront(struct listDeque *q) {
	assert(!linkedDequeIsEmpty(q));
	_removeLink(q, q->frontSentinel->next);
}
void linkedDequeRemoveBack(struct listDeque *q) {
	assert(!linkedDequeIsEmpty(q));
	_removeLink(q, q->backSentinel->prev);
}
TYPE linkedDequeIsEmpty(struct listDeque *q) {
	return q->size == 0;
}
void _addBefore(struct listDeque *q, struct link *lnk, TYPE e) {
	struct link *newLink = (struct link *)malloc(sizeof(struct link));
	assert(newLink != 0);
	newLink->value = e;
	newLink->prev = lnk->prev;
	newLink->next = lnk;
	lnk->prev->next = newLink;
	lnk->prev = newLink;
	q->size++;
}
void _removeLink(struct listDeque *q, struct link *lnk) {
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	q->size--;
}
TYPE linkedDequeFront(struct listDeque *q) {
	assert(!linkedDequeIsEmpty(q));
	return q->frontSentinel->next->value;
}
TYPE linkedDequeBack(struct listDeque *q) {
	assert(!linkedDequeIsEmpty(q));
	return q->backSentinel->prev->value;
}
















