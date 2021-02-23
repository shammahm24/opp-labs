//File name: roman_numeral_converter.cpp
//Author : Tanyaradzwa Matasva
//Date ; February 7, 2021
//Compiler:g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that converts Roman numerals to Arabic numerals

//roman_numeral_converter.cpp --  implementing Converter methods
#include <iostream>
#include <string>
#include "roman_numeral_converter.h"

Converter::Converter() //contructor 
{
    //initialize variables
    romanNumeral="";
    status="";
    result="";
    currentInt=0;
    totalInt=0;
}

Converter::Converter(std::string str)// constructor
{
    //initialize variables
    romanNumeral=str;
    status="";
    result="";
    currentInt=0;
    totalInt=0;
}

//implement methods


void Converter::setRomanNumeral(std::string str)//add a new roman numeral when not included in constructor
{
    romanNumeral=str;
}

void Converter::convert()//read roman numeral string and convert to int
{
    int repeats=0;
    int largest=0;
    int repeatSmaller=0;
    largest=prevInt=totalInt=getIntValue(romanNumeral[romanNumeral.length()-1]); //assign the right most character as largest digit

    /*
    traverse roman numeral from input
    */
    for(int i=romanNumeral.length()-2;i>=0;i--)
    {
        currentInt=getIntValue(romanNumeral[i]); //get int value for current character
        if(currentInt==-1) //check non roman numeral characters
            {
                status="Invalid number";
                break;
            }
        

        /*
        Calculate int value of the roman numeral
        */
        if(currentInt<prevInt) //subtract smaller number
        {
            totalInt-=currentInt;
            if(repeats>0)
            {
                repeats=0;
            }
        }
        else if(currentInt == prevInt) //add equal number
        {
            repeats+=1;
            totalInt+=currentInt;
            
        }
        else if(currentInt>prevInt) //add larger number
        {
            totalInt+=currentInt;
            if(currentInt>largest){
                repeatSmaller=0;
            }
            

        }
        
        /*
        Validate entry
        */
      
         if(repeatSmaller<1)
        {
            if(currentInt<largest)
                {
                    repeatSmaller+=1;
                    
                }
           
        }
        else
        {
            status="Invalid - More than 1 smaller numeral before larger numeral";
            break;
        }

        if(repeats>1)
        {
            status="Invalid - Repeats more than 3 times consercutively";
            break;
        }   
        

        if(currentInt>largest){ //update the largest int
            largest=currentInt;
            repeatSmaller=0;
            repeats=0;
        }
        
        prevInt=getIntValue(romanNumeral[i]);
        
    }
    
}

void Converter::display() //Display results
{
    if(status.length()>0){
        result=status;
        status="";
    }
    else
    {
        result=std::to_string(totalInt);
    }
    
    
}

int Converter::getIntValue(char c) //get the int value for current character
{
    char letter=c;
    switch (letter)
    {
    case 'I':/* constant-expression */
        /* code */
        return 1;
        break;
    
    case 'V':
        return 5;
        break;

    case 'X':
        return 10;
        break;

    case 'L':
        return 50;
        break;

    case 'C':
        return 100;
        break;

    case 'D':
        return 500;
        break;

    case 'M':
        return 1000;
        break; 

    default:
        return -1;
        break;
    }
}

std::ostream & operator<<(std::ostream & os,Converter & converter)
{
    os<<converter.romanNumeral<<" = "<<converter.result<<std::endl;
    return os;
}


