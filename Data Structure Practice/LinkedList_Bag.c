
#ifndef LinkedListBag
#define LinkedListBag
#define TYPE int
#define EQ(A, B) (A == B)

struct link {
	TYPE value;
	struct link *next;
	struct link *prev;
};
struct listBag {
	int size;
	struct link *frontSentinel;
	struct link *backSentinel;
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//function prototypes

void linkedBagInit(struct listBag *lst);
void linkedBagFree(struct listBag *lst);
void _addLink(struct listBag *lst, struct link *lnk, TYPE e);
void _removeLink(struct listBag *lst, struct link *lnk);
TYPE isEmptyLinkBag(struct listBag *lst);
void linkedBagAdd(struct listBag *lst, TYPE e);
TYPE linkedBagContains(struct listBag *lst, TYPE e);
void linkedBagRemove(struct listBag *lst, TYPE e);
void linkedBagPrint(struct listBag *lst);

int main(int argc, char** argv) {

		struct listBag *l = (struct listBag *)malloc(sizeof(struct listBag));

		linkedBagInit(l);
		printf("Is linked bag empty? = %i\n", isEmptyLinkBag(l));
		printf("Add 5 to the bag.\n");
		linkedBagAdd(l, 5);

		linkedBagPrint(l);
		printf("Add 9 to the bag.\n");
		linkedBagAdd(l, 9);

		linkedBagPrint(l);
		printf("Add 10 to the bag. \n");
		linkedBagAdd(l, 10);

		linkedBagPrint(l);
		printf("Add 15 to the bag.\n");
		linkedBagAdd(l, 15);

		linkedBagPrint(l);
		printf("Remove the number 9 from the bag.\n");
		linkedBagRemove(l, 9);

		linkedBagPrint(l);
		printf("\nDelete contents of the bag.\n");
		linkedBagFree(l);
		printf("\n");



	return 0;
}
void linkedBagInit(struct listBag *lst) {
	lst->frontSentinel = (struct link *)malloc(sizeof(struct link));
	assert(lst->frontSentinel != 0);
	lst->backSentinel = (struct link *)malloc(sizeof(struct link));
	assert(lst->backSentinel);
	lst->frontSentinel->next = lst->backSentinel;
	lst->backSentinel->prev = lst->frontSentinel;
	lst->size = 0;
}
void linkedBagFree(struct listBag *lst) {
	while(lst->size > 0)
	{
		_removeLink(lst, lst->frontSentinel->next);
	}
	
	lst->frontSentinel =  NULL;
	printf("The bag is now empty!\n");
}
void _addLink(struct listBag *lst, struct link *lnk, TYPE e) {
	struct link *newLink = (struct link *)malloc(sizeof(struct link));
	assert(newLink != 0);
	newLink->value = e;
	newLink->prev = lnk->prev;
	newLink->next = lnk;
	lnk->prev->next = newLink;
	lnk->prev = newLink;
	lst->size++;
}
void _removeLink(struct listBag *lst, struct link *lnk) {
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	lst->size--;
}
TYPE isEmptyLinkBag(struct listBag *lst) {
	return lst->size == 0;
}
void linkedBagAdd(struct listBag *lst, TYPE e) {
	_addLink(lst, lst->frontSentinel->next, e);
}
TYPE linkedBagContains(struct listBag *lst, TYPE e) {
	struct link *current;
	assert(!isEmptyLinkBag(lst));
	current = lst->frontSentinel->next;		//initialize current
	while(current != lst->backSentinel)
	{
		if(EQ(current->value, e))
			return 1;
		current = current->next;
	}
	return 0;
}
void linkedBagRemove(struct listBag *lst, TYPE e) {
	struct link *current; 
	assert(!isEmptyLinkBag(lst));
	current = lst->frontSentinel->next;		//initialize current
	while(current != lst->backSentinel)
	{
		if(EQ(current->value, e))
		{
			_removeLink(lst, current);
			break;							//only remove 1 copy of it
		}
		current = current->next;
	}
}
void linkedBagPrint(struct listBag *lst) {
	assert(lst != NULL);
	assert(!isEmptyLinkBag(lst));

	struct link *current = lst->frontSentinel->next;
	assert(current != 0);

	printf("The bag contains:\n");
	while(current != lst->backSentinel)
	{
		printf("%i\n", current->value);
		current = current->next;
	}
}