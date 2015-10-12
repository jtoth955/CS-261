
#ifndef LinkedListQueue
#define LinkedListQueue
#define TYPE int
#define EQ(a, b) (a == b)
struct link {
	TYPE value;
	struct link *next;
};
struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};
#endif
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//function prototypes

void listQueueInit(struct listQueue *q);
void listQueueAddBack(struct listQueue *q, TYPE e);
TYPE listQueueFront(struct listQueue *q);
void listQueueRemoveFront(struct listQueue *q);
int listQueueIsEmpty(struct listQueue *q);

int main(int argc, char** argv) {

struct listQueue * q = (struct listQueue *)malloc(sizeof(struct listQueue));

   listQueueInit(q);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Add 3 to the back of the list.\n");
   listQueueAddBack(q,3);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Add 6 to the back of the list.\n");
   listQueueAddBack(q,6);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Remove from the front.\n");
   listQueueRemoveFront(q);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   free(q);

return 0;

}

//function definitions

void listQueueInit(struct listQueue *q) {
	struct link *lnk = (struct link *)malloc(sizeof(struct link));
	assert(lnk != 0);		//lnk is the sentinel
	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}
void listQueueAddBack(struct listQueue *q, TYPE e) {
	struct link *lnk = (struct link*)malloc(sizeof(struct link));		//must cast to (struct link *)
	assert(lnk != 0);
	lnk->value = e;
	lnk->next = 0;
	q->lastLink->next = lnk;
	q->lastLink = lnk;
}
TYPE listQueueFront(struct listQueue *q) {
	if(!listQueueIsEmpty(q))
		return q->firstLink->next->value;

	return 0;
}
void listQueueRemoveFront(struct listQueue *q) {
	struct link *lnk = q->firstLink->next;
	assert(!listQueueIsEmpty(q));
	q->firstLink->next = lnk->next;
	
	if(q->firstLink->next == 0)
	{
		q->lastLink = q->firstLink;
	}
	free(lnk);
}
int listQueueIsEmpty(struct listQueue *q) {
	return q->firstLink == q->lastLink;
}

