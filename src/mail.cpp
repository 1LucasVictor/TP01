#include "mail.hpp"

Mail::Mail()
{
    message = "";
    priority = 0;
}


Mail::Mail(string msg, int p)
{
    message = msg;
    priority = p;
}

void Mail::setPriority(int p)
{
    priority = p;
}
void Mail::setMessage(string m)
{
    message = m;
}

int Mail::getPriority()
{
    return priority;
}

string Mail::getMessage()
{
    return message;
}
