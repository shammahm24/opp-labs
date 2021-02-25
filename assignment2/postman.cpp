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
        //get previouse row data
        copyPrev(i);
        for(int j=i;j<size;j+=(i+1))
        {
            
            //update new open and closed boxes
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

void Postman::copyPrev(int i)
{
        
        for(int j=0;j<size;j++){
            if(table[i-1][j]=='C'||table[i-1][j]=='c')
            {
                table[i][j]='c';
            
            }
            if(table[i-1][j]=='O'||table[i-1][j]=='o')
            {
                table[i][j]='o';
                
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
        for(int j=0;j<p.size;j++)
        {
            os<<p.table[i][j]<<"    ";
        }
        os<<std::endl;
    }
    delete[] p.table;
    return os;
}