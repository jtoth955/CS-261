/* CS261- Assignment 6 - hashMap.c
 * Name: John R Toth
 * Date: 8/04/15
 * Solution description: hashMap implementation file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += str[i];
    return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
    return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
    int index;
    if(ht == NULL)
        return;
    ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
    ht->tableSize = tableSize;
    ht->count = 0;
    for(index = 0; index < tableSize; index++)
        ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
    assert(tableSize > 0);
    hashMap *ht;
    ht = malloc(sizeof(hashMap));
    assert(ht != 0);
    _initMap(ht, tableSize);
    return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
    /*write this*/
    
    assert(ht->table != NULL);
    
    struct hashLink *ptr, *temp;                        //initialize ptr and temp to be used in freeing
    int i;
    
    for(i = 0; i < ht->tableSize; i++ )
    {
        ptr = ht->table[i];
    
        while(ptr != NULL)                              //if pointer @ index [i] is not empty, go through and free
        
        {
            temp = ptr->next;                           //continue to iterate to next ptr
            free(ptr->key);
            free(ptr);
            ptr = temp;                                 //ptr get's ptr->next val, loops again so long an as ptr != 0
        }
    }
    
    ht->count = 0;                                      //reset table data, count and size
    ht->tableSize = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
    assert(ht!= 0);
    /* Free all memory used by the buckets */
    _freeMap(ht);
    /* free the hashMap struct */
    free(ht);
}

/*
 Resizes the hash table to be the size newTableSize
 */
void _setTableSize(struct hashMap * ht, int newTableSize)
{
    /*write this*/
    
    
    struct hashLink *temp, **tempTable = ht->table;     //temp is initialized as ptr, tempTable gets current table
    int tempSize = ht->tableSize;                       //tempSize gets current tableSize
    
    _initMap(ht, newTableSize);                         //pass new table info to initMap to set it up
    
    for(int i = 0; i < tempSize; i++)
    {
        hashLink *curLink = tempTable[i];               //initialize curLink to current index
        
        while(curLink != NULL)                          //while curLink > 0, move elements from old to new array
        {
            insertMap(ht, curLink->key, curLink->value);
            temp = curLink->next;                       //temp gets incremented curLink
            free(curLink);                              //current curLink is deleted
            curLink = temp;                             //curLink gets is pointed at next link
        }
    }
    
    
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
    /*write this*/
    
    int idx;
    
    struct hashLink *newLink = (struct hashLink *)malloc(sizeof(struct hashLink));      //allocate memory for new link
    assert(newLink != 0);

    char *newKey = (char *)malloc(strlen(k) + 1);                                       //and allocate memory for new string for use after 
                                                                                        //the key has been checked to ensure it doesn't already exist

    if(HASHING_FUNCTION == 1)                            //compute hashMap bucket index, after determining which FN is valid
    {
        idx = stringHash1(k) % ht->tableSize;
    }

        else if(HASHING_FUNCTION == 2)
        {
            idx = stringHash2(k) % ht->tableSize;               
        }
    

    if(containsKey(ht, k))                              //check if hashLink already exists for passed key
    {
        removeKey(ht, k);                               //if found, remove key
    }
    
    strcpy(newKey, k);                                  //copy string into newKey memory

        newLink->key = newKey;
        newLink->value = v;
        newLink->next = ht->table[idx];
        ht->table[idx] = newLink;

        ht->count++;


        if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
        {                                               //if load factor is equal to or greater than predetermined
            _setTableSize(ht, ht->tableSize * 2);       //threshold, resize table
        }
    
    
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
    /*write this*/
    
    int idx;

    if(HASHING_FUNCTION == 1)                           //compute hashMap bucket index, after determining which FN is valid
    {
        idx = stringHash1(k) % ht->tableSize;
    }    

        else if(HASHING_FUNCTION == 2)
        {
            idx = stringHash2(k) % ht->tableSize;    
        }

    if(idx < 0) idx += ht->tableSize;
    
    hashLink *tempLink = ht->table[idx];
    
    while(tempLink != 0)
        {
            if(strcmp(k, tempLink->key)== 0)
            {
                return &tempLink->value;                //key value is found
            }
            else
            {
                tempLink = tempLink->next;              //tempLink gets the next value in the table
            }
        }
    
    return NULL;                                        //the key is not in the hashTable
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
    /*write this*/

    struct hashLink *curLink;
    int idx;

    if(HASHING_FUNCTION == 1)
    {
        idx = stringHash1(k) % ht->tableSize;
    }

        else if(HASHING_FUNCTION == 2)
        {
            idx = stringHash2(k) % ht->tableSize;
        }

    curLink = ht->table[idx];                           //point curLink to head of list

    while(curLink != NULL) 
    {
        if(strcmp(k, curLink->key) == 0)                //check list for keyType, return 1 if found
            return 1;
            curLink = curLink->next;
    }

    return 0;                                           //key was not found
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
    /*write this*/
    
    if(containsKey(ht, k) == 1)                         //if true, the key is in the table and needs to be found
    {
        int idx; 

        if(HASHING_FUNCTION == 1)                       //compute hashMap bucket index, after determining which FN is valid
        {
            idx = stringHash1(k) % ht->tableSize;
        }

            else if(HASHING_FUNCTION == 2)
            {
                idx = stringHash2(k) % ht->tableSize;           
            }
        
        hashLink *currLink = ht->table[idx];            //currLink set to found bucket index
        hashLink *temp = currLink;                      //temp will be used to update link pointers

        while(currLink != 0)
        {
            if(strcmp(currLink->key, k) == 0)
            {
                if(temp == currLink)
                {
                    temp = currLink->next;              //temp gets currLink pointer to next link
                    ht->table[idx] = temp;
                }
                else
                    temp->next = currLink->next;        //passed key value found in array, set temp->next to next 
                                                
                    currLink->value = 0;                //link in array so currLink can be freed
                    free(currLink);                     //free currLink
                    ht->count--;                        //decrement hashLink counter
                    break;                              //break from while loop as currLink has been freed
            }
            currLink = currLink->next;                  //point currLink to next link and continue looking
        }
    }

    else
        printf("Invalid key value.");                   //key value not in list, message is presented to user
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
    /*write this*/

    return ht->count;                                   //simply return the count of links in the table
    
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
    /*write this*/
    
    return ht->tableSize;                               //simply return the size of the current table
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
    /*write this*/
    
    int idx, sum = 0;
    
    for(idx = 0; idx < ht->tableSize; idx++)            //search all indices
    {
        if(ht->table[idx] == NULL)                      //if bucket is empty, increment int value num.
        {
            sum++;
        }
    }
    
    return sum;                                         //return sum
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
    /*write this*/
    
    return ((float)ht->count / ht->tableSize);          //return float of # of elements divided by table size
    
}


void printMap (struct hashMap * ht)
{
    int i;
    struct hashLink *temp;
    for(i = 0;i < capacity(ht); i++){
        temp = ht->table[i];
        if(temp != 0) {
            printf("\nBucket Index %d -> ", i);
        }
        while(temp != 0){           
            printf("Key:%s|", temp->key);
            printValue(temp->value);
            printf(" -> ");
            temp=temp->next;            
        }       
    }
}


