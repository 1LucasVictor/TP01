#include "priority_queue.hpp"


ItemType::ItemType()
{   
    key = KeyType();
}
ItemType::ItemType(KeyType k)
{
    key = k;
}
void ItemType::setKey(KeyType k)
{
    key = k;
}
KeyType ItemType::getKey()
{
    return key;
}
QCell::QCell()
{   
    Mail aux;
    item.setKey(aux);
    next = nullptr;
}

Queue::Queue()
{
    first = nullptr;
    last = first;
    size = 0;
}
Queue::~Queue()
{
    clean();
}

void Queue::insert(ItemType item)
{
    auto aux = new QCell();
    aux->item = item;
    if(first == nullptr)
    {
        first = aux;
        last = aux;
    }
    else if(first->item.getKey().getPriority() < item.getKey().getPriority())
    {
        aux->next = first;
        first = aux;
    }
    else 
    {   
        auto temp = first;
        while(temp->next != nullptr && temp->next->item.getKey().getPriority() >= item.getKey().getPriority() )
        {
            temp = temp->next;
        }
        if(temp->next != nullptr)
        {
            aux->next = temp->next;
            temp->next = aux;
        } else 
        {
            temp->next = aux;
            last = aux;
        }
    }
    size++;
}

ItemType Queue::getItem()
{   
    if(size == 0)
        throw "The queue is empty!";
    auto aux = first;
    auto content = aux->item;
    first = first->next;
    delete aux;
    size--;
    return content;
}

int Queue::length()
{
    return size;
}

void Queue::clean()
{
    auto aux = first;
    while(aux != nullptr)
    {
        first = first->next;
        delete aux;
        aux = first;
    }
    size = 0;
    last = nullptr;
}