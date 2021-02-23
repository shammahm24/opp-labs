//File name: driver.cpp
//Author : Tanyaradzwa Matasva
//Date ; February 7, 2021
//Compiler: g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that converts Roman numerals to Arabic numerals
//use roman_numeral_converter.cpp
//compile roman_numeral_converter.cpp and driver.cpp together
#include <iostream>
#include <fstream>
#include <string>
#include "roman_numeral_converter.h"

int main()
{
    using std::cout;
    using std::endl;
    std::cout<<"*** Running Roman numeral to Arabic converter ***"<<endl;
    Converter converter;

    std::ifstream infile("input.txt");
    std::string temp="";

    if(!infile)
    {
        cout<<"Failed to open file. \n";
        return 1;
    }
    else
    {
        while(std::getline(infile,temp))
        {
            converter.setRomanNumeral(temp);
            converter.convert();
            converter.display();

            std::cout<<converter;
        }
        infile.close();
    }

    

    return 0;
    
}