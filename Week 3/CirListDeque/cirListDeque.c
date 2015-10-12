/* CS261- Assignment 3 - cirListDeque.c*/
/* Name: John R Toth
 * Date: 7/12/15
 * Solution description: Deque implementation file: Fill, print and reverse deque contents.
 * NOTES: I utilized Stack Overflow for advisement on how to reverse the order of the deque.
 * I included the web address for the Stack Overflow post, in the relevant section below.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
    TYPE value;/* value of the link */
    struct DLink * next;/* pointer to the next link */
    struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
    int size;/* number of links in the deque */
    struct DLink *Sentinel; /* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
 Deque Functions
 ************************************************************************ */

/* Initialize deque.
 
 param:  q       pointer to the deque
 pre:    q is not null
 post:   q->Sentinel is allocated and q->size equals zero
 */
void _initCirListDeque (struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    assert(q != 0);                                     //assert that q is not null
    
    q->Sentinel = malloc(sizeof(struct DLink));
    assert(q->Sentinel != 0);                           //assert that Sentinel is not empty
    
    q->Sentinel->next = q->Sentinel;                    //the Sentinel's next pointer, points to itself
    q->Sentinel->prev = q->Sentinel;                    //the Sentinel's' prev pointer, pointst to itself
    
    q->size = 0;
    
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
    struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
    _initCirListDeque(newCL);
    return(newCL);
}


/* Create a link for a value.
 
 param:  val     the value to create a link for
 pre:    none
 post:   a link to store the value
 */
struct DLink * _createLink (TYPE val)
{
    /* FIXME: you must write this */
    
    struct DLink *newLink = (struct DLink*)malloc(sizeof(struct DLink));
    
    assert(newLink != 0);
    
    newLink->value = val;                                   //newLink now contains the value passed in
    
    /*temporary return value..you may need to change it*/
    return newLink;
}

/* Adds a link after another link
 
 param:  q       pointer to the deque
 param:  lnk     pointer to the existing link in the deque
 param:  v       value of the new link to be added after the existing link
 pre:    q is not null
 pre:    lnk is not null
 pre:    lnk is in the deque
 post:   the new link is added into the deque after the existing link
 */
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
    /* FIXME: you must write this */
    
    assert(q != 0);                                         //assert that q is not null
    assert(lnk != 0);                                       //assert that lnk is not null
    
    struct DLink *newLink;
    
    newLink = _createLink(v);                       //a new link is created using _createLink
    newLink->next = lnk->next;                      //newLink's next pointer is set to lnk's next pointer
    newLink->prev = lnk;                            //newLink's prev pointer is set to lnk
    newLink->value = v;                             //newLink's value is filled with the passed value, v.
    
    lnk->next->prev = newLink;
    lnk->next = newLink;
    
    q->size++;                                              //update size field for the newly inserted link
    
    
}

/* Adds a link to the back of the deque
 
 param:  q       pointer to the deque
 param:  val     value for the link to be added
 pre:    q is not null
 post:   a link storing val is added to the back of the deque
 */
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    _addLinkAfter(q, q->Sentinel->prev, val);               //add val to the back of the deque
    
}

/* Adds a link to the front of the deque
 
 param:  q       pointer to the deque
 param:  val     value for the link to be added
 pre:    q is not null
 post:   a link storing val is added to the front of the deque
 */
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    _addLinkAfter(q, q->Sentinel, val);                     //add val to the front of the deque
    
}

/* Get the value of the front of the deque
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   none
 ret:    value of the front of the deque
 */
TYPE frontCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));                        //ensure q is neither null nor empty
    
    /*temporary return value..you may need to change it*/
    
    return q->Sentinel->next->value;                        //returns value of the next value Sentinel points to
}


/* Get the value of the back of the deque
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   none
 ret:    value of the back of the deque
 */
TYPE backCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    /*temporary return value..you may need to change it*/
    
    return q->Sentinel->prev->value;                    //returns value of the prev value Sentinel points to
}

/* Remove a link from the deque
 
 param:  q       pointer to the deque
 param:  lnk     pointer to the link to be removed
 pre:    q is not null and q is not empty
 post:   the link is removed from the deque
 */
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    lnk->prev->next = lnk->next;                            //lnk next becomes lnk prev's next
    lnk->next->prev = lnk->prev;                            //lnk prev becomes lnk next's prev
    
    free(lnk);                                              //free removed lnk's memory
    q->size--;                                              //update size field
    
}

/* Remove the front of the deque
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   the front is removed from the deque
 */
void removeFrontCirListDeque (struct cirListDeque *q) {
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    _removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   the back is removed from the deque
 */
void removeBackCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    _removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque
 
 param:  q       pointer to the deque
 pre:    none
 post:   All links (including Sentinel) are de-allocated
 */
void freeCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    while(q->size > 0)
    {
        _removeLink(q, q->Sentinel->next);                  //frees all memory until array size == 0
    }
    
    q->Sentinel = NULL;                                     //set Sentinel to null
    
}

/* Check whether the deque is empty
 
 param:  q       pointer to the deque
 pre:    q is not null
 ret:    1 if the deque is empty. Otherwise, 0.
 */
int isEmptyCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != 0);
    
    if(q->size == 0)
        return 1;
    
    else
        return 0;
}

/* Print the links in the deque from front to back
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   the links in the deque are printed from front to back
 */
void printCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    struct DLink *current = q->Sentinel->next;
    assert(current != 0);
    
    printf("The links from front to back are:\n");
    while(current != q->Sentinel)
    {
        printf("%f\n", current->value);
        current = current->next;
    }
    
    
}

/* Reverse the deque
 
 param:  q       pointer to the deque
 pre:    q is not null and q is not empty
 post:   the deque is reversed
 */
void reverseCirListDeque(struct cirListDeque *q)
{
    /* FIXME: you must write this */
    
    //I was unsure how to approach this, so I took advisement from a Stack Overflow post. The link to this
    //post can be found here: http://stackoverflow.com/questions/12981833/reversing-the-order-of-a-circular-deque-c
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    
    struct cirListDeque *temp = createCirListDeque();       //create temp deque to hold reversed deque
    //contents
    
    while (!isEmptyCirListDeque(q))
    {
        addBackCirListDeque(temp, backCirListDeque(q));     //backout q deque into temp, this reverses the
        removeBackCirListDeque(q);                          //order of the array values. Delete q deque
        //links.
    }
    q->Sentinel = temp->Sentinel;                           //q->Sentinel is updated to temp's Sentinel
    q->size = temp->size;                                   //q->size is updated to temp's size
    
    free(temp);                                             //free the memory allocated to temp
    
}
