#include "account_list.hpp"
#include <iostream>

LCell::LCell()
{   
    next = nullptr;
}

Account_List::Account_List()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

int Account_List::length()
{
    return size;
}

int Account_List::insert(User u)
{    
    //Check if a user with the same ID is already registred
    if(setPosition(u.getId()) != nullptr) return 0;
    auto aux = new LCell();
    aux->user = u;
    if(first == nullptr) 
    {
        first = aux;
        last = aux;
    }
    else 
    {
        last->next = aux;
        last = aux;
    }
    size++;
    // ESCREVEMEMLOG((long int) last, sizeof(LCell) , last->user.getId());
    return 1;
}

int Account_List::remove(int id)
{    
    int ret = 0;
    if(length() <= 0) return ret;

    first->user.getId(); 
    if(first->user.getId() == id)
    {
    // LEMEMLOG((long int) first, sizeof(LCell) , first->user.getId());s
    auto temp = first;
    first = first->next;
    if(length()==1) last = nullptr;
    temp->user.~User();
    delete temp;
    ret = 1;
    size--;
    }
    else
    {
        auto aux = setPosition(id, 1);
        if(aux != nullptr)
        {   
            auto temp = aux->next;
            if(temp == last) last = aux;
            aux->next = aux->next->next;
            temp->user.~User();
            delete temp;
            ret = 1;
            size--;
        } else ret = 0;
    }
    if(size == 0)
    {
        last = nullptr;
        first = nullptr;
    } 
    return ret;
}

User *Account_List::getUser(int id)
{
    LCell *aux = setPosition(id) ;
    return (aux == nullptr) ? nullptr : &(aux->user);
}

LCell *Account_List::setPosition(int id, int previous)
{   
    if(first == nullptr) return nullptr;
    // LEMEMLOG((long int) first, sizeof(LCell) , first->user.getId());
    if(first->user.getId() == id) return first;
    else
    {
        auto aux = first;
        while(aux->next != nullptr && aux->next->user.getId() != id) 
        {
            aux = aux->next;
            // LEMEMLOG((long int) aux->next, sizeof(LCell) , aux->next->user.getId());
        }
        if(aux->next == nullptr) return nullptr;
        return  previous ? aux : aux->next;
    }
}
Account_List::~Account_List()
{      
    auto temp = first;
    while(temp != nullptr)
    {   
        first = first->next;
        temp->user.~User();
        delete temp;
        temp = first;
    }
}