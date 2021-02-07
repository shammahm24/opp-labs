//roman_numeral_converter.cpp --  implementing Converter methods
#include <iostream>
#include "roman_numeral_converter.h"

Converter::Converter()
{
    //initialize variables
    romanNumeral="";
    totalInt=0;
}

Converter::Converter(std::string str)//wih arguments in the constructor
{
    //initialize variables
    romanNumeral=str;
    totalInt=0;
}

//implement methods

//add a new roman numeral when not included in constructor
void Converter::setRomanNumeral(std::string str)
{
    romanNumeral=str;
}

//read roman numeral string and convert to int

void Converter::getIntValue()
{
    totalInt=romanNumeral[romanNumeral.length()-1];
    for(int i=romanNumeral.length()-2;i>=0;i--)
    {
        if(romanNumeral[i]<romanNumeral[i+1])
        {
            totalInt-=romanNumeral[i];
        }
        else
        {
            totalInt+=romanNumeral[i];
        }
    }
}

void Converter::display()
{
    
    std::cout<<romanNumeral<<" = "<<totalInt<<" ";
}
