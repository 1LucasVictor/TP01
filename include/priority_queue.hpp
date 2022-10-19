#ifndef QUEUE
#define QUEUE
#include "mail.hpp"
#include <string>
using namespace std;
// Allow using this queue for any data type
typedef Mail KeyType; 

// This queue implementation only works if the KeyType has a 'priority' attribute, with its 
// respective getPriority() method.


class ItemType
{
    public:
        ItemType();
        ItemType(KeyType k);
        void setKey(KeyType k);
        KeyType getKey();
    private:
        KeyType key;
    friend class QCell;
};

class QCell
{
    public:
        QCell();
    private:
        ItemType item;
        QCell *next;
    friend class Queue;
};

class Queue
{
    public:
        Queue();
        ~Queue();
        //Insert a new item into queue, following the item->key->priority
        void insert(ItemType item);
        ItemType getItem();
        void clean();
        int length();
    private:
        QCell *first;
        QCell *last;  
        int size;
};

#endif