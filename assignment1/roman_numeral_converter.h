//roman_numeral_converter.h class

#ifndef ROMAN_NUMERAL_CONVERTER_H_
#define ROMAN_NUMERAL_CONVERTER_H_
#include <string>


class Converter
{
    private: //variable definitions
        int totalInt;
        std::string romanNumeral;

    public: 
        Converter(); //default constructor 
        Converter(std::string str);//paramatized constructor 
        void setRomanNumeral(std::string str);
        void getIntValue();
        void convert(std::string str);
        void display();
};
#endif
