#ifndef LIST
#define LIST
#include "user.hpp"
using namespace std;

class LCell
{
    public:
        LCell();
    private:
        User user;
        LCell *next;
    friend class Account_List;
};

class Account_List
{
    public:
        Account_List();
        ~Account_List();
        //Adds a new user in the list
        int insert(User u);
        //Removes the user with the following id from the list
        int remove(int id);
        int length();
        //Returns the user ID pointer
        User *getUser(int id);
    private:
        LCell *first;
        LCell *last;
        int size;
        
        // Return the LCell that contains the user with the ID. If the ID isn't registred return null;
        // If previous == 1, return the previous LCell
        // When id is on first positions, previous == 1 return the first position;
        LCell *setPosition(int id, int previous = 0);
};
#endif