#include "user.hpp"
User::User(int id)
{
    _id = id;
    countInBox = 0;
}

User::User()
{
    _id = -1;
    countInBox = 0;
}

int User::getId()
{
    return _id;
}

// Returns a email with priority -1 to indicate that InBox is empty
Mail User::getMail()
{   
    if(countInBox)
    {
        countInBox--;
        return InBox.getItem().getKey();
    }
    else return Mail("", -1);
}

void User::setMail(Mail m)
{   
   InBox.insert(ItemType(m));
   countInBox++;
}

int User::checkInBox()
{
    return countInBox;
}

User::~User()
{
    InBox.~Queue();
}
