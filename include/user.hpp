#ifndef USER
#define USER
#include "priority_queue.hpp"


class User
{
   public:
      User(int id);
      User();
      ~User();
      //Returns the user ID
      int getId();
      //Returns the first email from the inbox, also removes this email from inbox.
      Mail getMail();
      //Puts an email in the inbox.
      void setMail(Mail m);
      //Returns the numbers of emails in the inbox
      int checkInBox();
   private:
      Queue InBox;
      int countInBox;
      int _id;
};



#endif