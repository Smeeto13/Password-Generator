#include "input.h"

bool input::prompt(std::string msg = "") {
    if (msg.empty() == false) {
        std::cout << msg << std::endl;
    }

    bool choice = false;
    std::string userIn = "";
    
    // Clears input stream
    std::cin.ignore();

    do {
        std::cout << "Yes or No? (Y/N)" << std::endl;

        std::getline(std::cin, userIn);

        // Convert to lowercase
        for (unsigned short i = 0; i < userIn.length(); i++) userIn[i] = std::tolower(userIn[i]);

        // Check input
        if (userIn == "yes") userIn = "y";
        if (userIn == "no") userIn = "n";
        if (userIn == "y") choice = true;
        if (userIn == "n") choice = false;

        // Check and clear cin errors
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Error Detected and Cleared" << std::endl;
        }

    } while (userIn != "y" && userIn != "n");

    return choice;
}

//Declares python style input function for unsigned short.
unsigned short input::ushort(std::string msg = "") {
    if (msg.empty() == false) {
        std::cout << msg << std::endl;
    }

    unsigned short out;
    std::cin >> out;

    while (!std::cin)
    {
        std::cout << "Overflow, try a number below 65535!\nNew Num:" << std::endl;
        std::cin.clear();
        std::cin >> out;
    }

    return out;
}

//Declares python style input function for unsigned int.
unsigned int input::uint(std::string msg = "") {
    if (msg.empty() == false) {
        std::cout << msg << std::endl;
    }

    unsigned int out;
    std::cin >> out;

    while (!std::cin)
    {
        std::cout << "Overflow, try a number below 4,294,967,295!\nNew Num:" << std::endl;
        std::cin.clear();
        std::cin >> out;
    }

    return out;
}