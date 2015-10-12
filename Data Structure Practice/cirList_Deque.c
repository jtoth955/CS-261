
#ifndef CirListDeque
#define CirListDeque
#define TYPE double

struct dLink {
	TYPE value;
	struct dLink *next;
	struct dLink *prev;
};
struct cirListDeque {
	int size;					//# of links in deque
	struct dLink *Sentinel;		//pointer to Sentinel
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//function prototypes

struct cirListDeque *createCirListDeque();
struct dLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct dLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct dLink *lnk);
void _initCirListDeque (struct cirListDeque *q);
void addBackCirListDeque(struct cirListDeque *q, TYPE val);
void addFrontCirListDeque(struct cirListDeque *q, TYPE val);
TYPE frontCirListDeque(struct cirListDeque *q);
TYPE backCirListDeque(struct cirListDeque *q);
void removeFrontCirListDeque(struct cirListDeque *q);
void removeBackCirListDeque(struct cirListDeque *q);
void freeCirListDeque(struct cirListDeque *q);
int isEmptyCirListDeque(struct cirListDeque *q);
void printCirListDeque(struct cirListDeque *q);
void reverseCirListDeque(struct cirListDeque *q);

int main(int argc, char** argv) {

	struct cirListDeque* q = createCirListDeque();
    addBackCirListDeque(q, (TYPE)1);
    addBackCirListDeque(q, (TYPE)2);
    addBackCirListDeque(q, (TYPE)3);
    addFrontCirListDeque(q, (TYPE)4);
    addFrontCirListDeque(q, (TYPE)5);
    addFrontCirListDeque(q, (TYPE)6);
    printCirListDeque(q);
    printf("The value at the front of the list is: %g\n", frontCirListDeque(q));
    printf("The value at the back of the list is: %g\n", backCirListDeque(q));
    printf("\nRemoving the value at the front and back of the list\n\n");
    removeFrontCirListDeque(q);
    removeBackCirListDeque(q);
    printCirListDeque(q);
    printf("\nReversing the order of the list... \n");
    reverseCirListDeque(q);
    printCirListDeque(q);

	return 0;
}
struct cirListDeque* createCirListDeque() {
	struct cirListDeque *newCirLink = (struct cirListDeque *)malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCirLink);

	return newCirLink;
}
struct dLink* _createLink(TYPE val) {
	struct dLink *newLink = (struct dLink *)malloc(sizeof(struct dLink));
	assert(newLink != 0);
	newLink->value = val;

	return newLink;
}
void _addLinkAfter(struct cirListDeque *q, struct dLink *lnk, TYPE v) {
	assert(q != NULL);
	assert(lnk != NULL);

	struct dLink *newLink;
	newLink = _createLink(v);
	newLink->next = lnk->next;
	newLink->prev = lnk;

	lnk->next->prev = newLink; 
	lnk->next = newLink;

	q->size++;

}
void _removeLink(struct cirListDeque *q, struct dLink *lnk) {
	assert(q != NULL);;
	assert(!isEmptyCirListDeque(q));

	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	q->size--;
}
void _initCirListDeque(struct cirListDeque *q) {
	q->Sentinel = (struct dLink *)malloc(sizeof(struct dLink));
	assert(q->Sentinel != 0);

	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
	q->size = 0;
}
void addBackCirListDeque(struct cirListDeque *q, TYPE val) {
	assert(q != NULL);
	_addLinkAfter(q, q->Sentinel->prev, val);
}
void addFrontCirListDeque(struct cirListDeque *q, TYPE val) {
	assert(q != NULL);
	_addLinkAfter(q, q->Sentinel, val);
}
TYPE frontCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	return q->Sentinel->next->value;
}
TYPE backCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	return q->Sentinel->prev->value;
}
void removeFrontCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	_removeLink(q, q->Sentinel->next);
}
void removeBackCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	_removeLink(q, q->Sentinel->prev);
}
void freeCirListDeque(struct cirListDeque *q) {
	while(q->size > 0)
	{
		_removeLink(q, q->Sentinel->next);
	}

	q->Sentinel = NULL;
}
int isEmptyCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);

	return q->size == 0;			//check to see if this throws errors
}
void printCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	struct dLink *current = q->Sentinel->next;
	assert(current != 0);

	printf("\nThe links from front to back are:\n");
	while(current != q->Sentinel)
	{
		printf("%f\n", current->value);
		current = current->next;
	}
}
void reverseCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	assert(!isEmptyCirListDeque(q));

	struct cirListDeque *temp = createCirListDeque();

	while(!isEmptyCirListDeque(q))
	{
		addBackCirListDeque(temp, backCirListDeque(q));
		removeBackCirListDeque(q);
	}
	q->Sentinel = temp->Sentinel;
	q->size = temp->size;
	free(temp);
}




















