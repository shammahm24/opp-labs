//File name: postman.cpp
//Author : Tanyaradzwa Matasva
//Date ; February 21, 2021
//Compiler:g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that tracks a postman's activity

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
#include "postman.h"



//Constructors
Postman::Postman()
{
    size = 5;
    table = new char *[size];
    createTable(size,table);
}

Postman::Postman(int s):size(s)
{
    
    table = new char *[size];
    createTable(size,table);
    
}

Postman::Postman(Postman &p):size(p.size)
{
    size = size;
    table = new char *[size];
    createTable(size,table);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;i++)
        {
            table[i][j]=p.table[i][j];
        }
    }
}

//other methods

void Postman::createTable(int size,char**table)
{
    for(int i=0;i<size;i++)
    {
        table[i] = new char[size];
    }

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            table[i][j]='c';
        }
    }
}

void Postman::visitBoxes()
{
    
    for(int i=1;i<size;i++){
        for(int j=i+1;j<size;i+i)
        {
            if(table[i][j]=='c')
            {
                table[i][j]='O';
            }
            else
            {
                table[i][j]='C';
            }
        }
    }
}

void Postman::display()
{
    for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    cout<<table[i][j];
                }
            }
}

//overloaded operators
Postman Postman::operator=(const Postman&p)
{
    assert(p.size==size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;i++)
        {
            table[i][j]=p.table[i][j];
        }
    }

    return(*this);
}

std::ostream & operator<<(std::ostream & os,Postman &p)
{
    
    for(int i=0;i<p.size;i++)
    {
        for(int j=0;j<p.size;)
        {
            os<<p.table[i][j];
        }
        os<<std::endl;
    }
    
    return os;
}