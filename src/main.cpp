#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "account_list.hpp"
#include "msgassert.h"
using namespace std;

// Variable that will contain all the data
Account_List Accounts;
fstream input;
#define output std::cout

void add_User(int id)
{   
    if(Accounts.insert(User(id)))
    {
        output << "OK: CONTA " << id << " CADASTRADA" << endl;
    }
    else output << "ERRO: CONTA " << id << " JA EXISTENTE" << endl;
}

void remove_User(int id)
{   
   if(Accounts.length() > 0) 
   {    
        if(Accounts.remove(id))
        {   
                output << "OK: CONTA " << id << " REMOVIDA" << endl;
        }
        else output << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
    }
   else output << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
}
void send_Email(int id, string msg, int priority)
{
    User *receiver = Accounts.getUser(id);
    if(receiver != nullptr)
    {
        receiver->setMail(Mail(msg, priority));
        output << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
    }
    else output << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
}

//This function return the first email of the priority queue, if the account don't exist or
// the queue is empty return a Mail with priority -1
Mail get_Email(int id)
{   
    User *u = Accounts.getUser(id);
    if(u != nullptr)
    {   
        auto aux = u->getMail();
        if(aux.getPriority() >= 0)
        {   
            output << "CONSULTA " << id << ": "<< aux.getMessage() << endl;
        }
        else 
        {
            output << "CONSULTA "<< id <<": " <<"CAIXA DE ENTRADA VAZIA" << endl;
        } 
        return aux;
    }
    else
    {
        output << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
        return Mail("", -1);
    }
}
int main(int argc, char *argv[])
{   
    int regmem = 0;
    string in, out;
    if(argc < 2)
    {
        output << "Nome de arquivo de entrada de acesso tem que ser definido\n";
        return 0;
    }
    in = argv[1];

    erroAssert(in.length() > 0, "Nome de arquivo de entrada de acesso tem que ser definido");
    
    input.open(in, fstream::in);
    erroAssert(input.is_open(),"Falha ao abrir o arquivo");


    string command, temp_msg;
    stringstream final_msg;
    int temp_id, temp_pri;
    int c = 0;
    while(!input.eof())
    {    
        input >> command;
        input >> temp_id; 
        if(!command.compare("CADASTRA"))
        {
            add_User(temp_id);
        }
        else if(!command.compare("REMOVE"))
        {
            remove_User(temp_id);
        }
        else if(!command.compare("ENTREGA"))
        {   
            input >> temp_pri;
            input >> temp_msg;
            while(temp_msg.compare("FIM"))
            {   
                final_msg << temp_msg << " ";
                input >> temp_msg;
            }
            send_Email(temp_id, final_msg.str(), temp_pri);
            final_msg.str("");
        }
        else if(!command.compare("CONSULTA"))
        {   
            get_Email(temp_id);
        }
        command = "";
    }
    input.close();
}