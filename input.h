#pragma once
#include <string>
#include <iostream>
class input
{
	public:
        //Declares a function for providing a Yes or No user prompt.
        bool prompt(std::string);

        //Declares python style input function for unsigned short.
        unsigned short ushort(std::string);

        //Declares python style input function for unsigned int.
        unsigned int uint(std::string);
};

