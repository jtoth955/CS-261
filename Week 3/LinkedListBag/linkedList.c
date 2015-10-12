/* CS261- Assignment 3 - linkedList.c
* Name: John R Toth
* Date: 7/12/15
* Solution description: Bag array using a linked list
*/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
    TYPE value;
    struct DLink * next;
    struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
    int size;
    struct DLink *firstLink;
    struct DLink *lastLink;
};

/*
    initList
    param lst the linkedList
    pre: lst is not null
    post: lst size is 0
 */

void _initList (struct linkedList *lst) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    
    lst->firstLink = malloc(sizeof(struct DLink));         //allocate memory for firstlink sentinel
    assert(lst->firstLink != 0);
    
    lst->lastLink = malloc(sizeof(struct DLink));          //allocate memory for lastlink sentinel
    assert(lst->lastLink);

    lst->firstLink->next = lst->lastLink;                       //firstlink next's sentinel set to lastlink
    lst->lastLink->prev = lst->firstLink;                       //lastlink prev's sentinel set to firstlink
    lst->size = 0;                                              //set lst size to 0
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
    struct linkedList *newList = malloc(sizeof(struct linkedList));
    _initList(newList);
    return(newList);
}

/*
    _addLinkBeforeBefore
    param: lst the linkedList
    param: l the  link to add before
    param: v the value to add
    pre: lst is not null
    pre: l is not null
    post: lst is not empty
 */

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(l != 0);
    assert(!isEmptyList(lst));
    
    struct DLink *newLink = malloc(sizeof(struct DLink));       //allocate memory to newLink
    assert(newLink != 0);                                       //ensure that allocation worked
    
    newLink->value = v;                                         //set newLink value to v
    newLink->prev = l->prev;                                    //set newLink prev pointer to l prev
    newLink->next = l;                                          //set newLink next pointer to l
    l->prev->next = newLink;                                    //l prev next now points is now newLink
    l->prev = newLink;                                          //l prev is now newLink
    
    lst->size++;                                                //lst size is updated
    
}


/*
    addFrontList
    param: lst the linkedList
    param: e the element to be added
    pre: lst is not null
    post: lst is not empty, increased size by 1
 */

void addFrontList(struct linkedList *lst, TYPE e)
{
    
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    _addLinkBefore(lst, lst->firstLink->next, e);               //add "e" to the front of the firstlink Sentinel
    
}

/*
    addBackList
    param: lst the linkedList
    param: e the element to be added
    pre: lst is not null
    post: lst is not empty, increased size by 1
 */

void addBackList(struct linkedList *lst, TYPE e) {
    
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    _addLinkBefore(lst, lst->lastLink, e);                      //add "e" to the lastlink Sentinel
}

/*
    frontList
    param: lst the linkedList
    pre: lst is not null
    pre: lst is not empty
    post: none
 */

TYPE frontList (struct linkedList *lst) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    /*temporary return value...you may need to change this */
    return lst->firstLink->next->value;                         //return the value ahead of firstlink sentinel
}

/*
    backList
    param: lst the linkedList
    pre: lst is not null
    pre: lst is not empty
    post: lst is not empty
 */

TYPE backList(struct linkedList *lst)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    /*temporary return value...you may need to change this */
    return lst->lastLink->prev->value;                          //return the value before the lastlink sentinel
}

/*
    _removeLink
    param: lst the linkedList
    param: l the linke to be removed
    pre: lst is not null
    pre: l is not null
    post: lst size is reduced by 1
 */

void _removeLink(struct linkedList *lst, struct DLink *l)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    l->prev->next = l->next;                                    //set l prev next to l next
    l->next->prev = l->prev;                                    //set l next prev to l prev
    
    free(l);                                                    //free allocated memory
    lst->size--;                                                //update size field
    
}

/*
    removeFrontList
    param: lst the linkedList
    pre:lst is not null
    pre: lst is not empty
    post: size is reduced by 1
 */

void removeFrontList(struct linkedList *lst) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    _removeLink(lst, lst->firstLink->next);
    
}

/*
    removeBackList
    param: lst the linkedList
    pre: lst is not null
    pre:lst is not empty
    post: size reduced by 1
 */

void removeBackList(struct linkedList *lst)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    _removeLink(lst, lst->lastLink->prev);
    
}

/*
    isEmptyList
    param: lst the linkedList
    pre: lst is not null
    post: none
 */

int isEmptyList(struct linkedList *lst) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    
    /*temporary return value...you may need to change this */

    return (lst->firstLink == lst->lastLink);                   //list is empty if both front and back pointers point to eachother
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    
    struct DLink *temp = lst->firstLink->next;                  //initialize temp pointer to cycle through print function
    assert(temp != 0);
    
    printf("The printed list is:\n");
    while(temp != lst->firstLink)
    {
        printf("%d\n", temp->value);
        temp = temp->next;                                      //cycle to next value with each loop iteration until temp == lst->firstlink
    }
    
}

/*
    Add an item to the bag
    param:  lst     pointer to the bag
    param:  v       value to be added
    pre:    lst is not null
    post:   a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    /* FIXME: you must write this */
    
    assert(lst != 0);
    
    addBackList(lst, v);                                        //pass lst and TYPE value to addBackList
    
}

/*  Returns boolean (encoded as an int) demonstrating whether or not
    the specified value is in the collection
    true = 1
    false = 0
 
    param:  lst     pointer to the bag
    param:  e       the value to look for in the bag
    pre:    lst is not null
    pre:    lst is not empty
    post:   no changes to the bag
 */
int containsList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    struct DLink *newLink;
    newLink = lst->firstLink->next;                             //initialize newLink to next value after firstlink sentinel

    while(newLink != lst->lastLink)
    {
        if(EQ(newLink->value, e))
            return 1;                                           //if found, fn returns 1
        newLink = newLink->next;                                //cycle to next value with each iteration, until newLink == lst->lastlink
    }
    
    /*temporary return value...you may need to change this */
    return 0;
}

/*  Removes the first occurrence of the specified value from the collection
    if it occurs
 
    param:  lst     pointer to the bag
    param:  e       the value to be removed from the bag
    pre:    lst is not null
    pre:    lst is not empty
    post:   e has been removed
    post:   size of the bag is reduced by 1
 */
void removeList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    struct DLink *temp;
    temp = lst->firstLink->next;                                //initialize temp to point to firstlink
    
    while(temp != lst->lastLink)
    {
        if(EQ(temp->value, e))
        {
            _removeLink(lst, temp);                             //if found, remove value and break from function
                break;
        }
        temp = temp->next;                                      //temp iterates to next link in lst
    }
}











