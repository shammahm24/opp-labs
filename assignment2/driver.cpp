//File name: driver.cpp
//Author : Tanyaradzwa Matasva
//Date ; February 21, 2021
//Compiler:g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that tracks a postman's activity

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "postman.h"

int main()
{
   
    ifstream infile("test.txt");
    string temp="";
    
    if(!infile)
    {
        cout<<"Failed to open file. \n";
        return 1;
    }
    else
    {
        
        while(std::getline(infile,temp))
        {
            
            Postman postman(stoi(temp));
            cout<<endl;

            cout<<"Number of mailboxes specified: "<<temp<<endl;
            cout<<endl;

            for(int i=0;i<stoi(temp);i++)
            {
                cout<<i+1<<"    ";
            }
            cout<<endl;
            postman.visitBoxes();
            cout<<postman; //print with overriden operator
            cout<<endl;
        }
        infile.close();
    }
    return 0;
}