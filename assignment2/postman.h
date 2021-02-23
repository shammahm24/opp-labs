//File name: postman.h
//Author : Tanyaradzwa Matasva
//Date ; February 21, 2021
//Compiler:g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that tracks a postman's activity


#ifndef POSTMAN_
#define POSTMAN_
#include <string>
#include <ostream>

class Postman
{
    private: //private data members
    int size;
    char **table;

    public: //constructors and methods
    Postman();
    Postman(int size);
    Postman(Postman &p); // copy constructor
    void createTable(int size,char **table);
    void visitBoxes();
    void display();

    //overriden operators
    friend std::ostream & operator<<(std::ostream & os,Postman & postman);
    Postman operator= (const Postman &p);

};
#endif