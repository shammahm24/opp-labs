//File name: roman_numeral_converter.h
//Author : Tanyaradzwa Matasva
//Date ; February 7, 2021
//Compiler:g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Description : Program that converts Roman numerals to Arabic numerals

//roman_numeral_converter.h class

#ifndef ROMAN_NUMERAL_CONVERTER_H_
#define ROMAN_NUMERAL_CONVERTER_H_
#include <string>
#include <ostream>


class Converter
{
    private: //variable definitions
        int totalInt;
        int currentInt;
        int prevInt;
        char currentLetter;
        std::string romanNumeral;
        std::string status;
        std::string result;

    public: 
        Converter(); //default constructor 
        Converter(std::string str);//paramatized constructor 
        void setRomanNumeral(std::string str); //add roman numeral when using default constructor
        int getIntValue(char c); // get int value for current character
        void convert(); //calculate int value
        void display(); //print int value
        friend std::ostream & operator<<(std::ostream & os,Converter & converter);
        
};
#endif
