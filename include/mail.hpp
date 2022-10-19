#ifndef MAIL
#define MAIL
#include <string>
using namespace std;
class Mail
{   
    public:
        Mail();
        Mail(string msg, int p);
        //Changes the email Priority.
        void setPriority(int p);
        //Changes the email message.
        void setMessage(string m);
        //Returns the email priority.
        int getPriority();
        //Returns the email message
        string getMessage();
       
    private:
        int priority;
        string message;
};

#endif