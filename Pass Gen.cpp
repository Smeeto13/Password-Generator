#include<iostream>
#include<random>
#include"input.h"

// Function to select random character of "type".
void pick(unsigned short charType, unsigned short select) {
    //Strings holding available characters for password.
    const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    const std::string symbol = "!@#$%&";
    const std::string number = "0123456789";

    //Selects and outputs characters for password.
    switch (charType)
    {
    case 0:
        std::cout << ALPHABET[select % 26];
        break;
    case 1:
        std::cout << alphabet[select % 26];
        break;
    case 2:
        std::cout << symbol[select % 6];
        break;
    case 3:
        std::cout << number[select % 10];
        break;
    }
}

// Main function, takes arguments for password generation.
int main(int argc, const char* argv[])
{
    input in;

    // Holds target password length.
    unsigned int passLength = 0;

    /* Holds password minimum requirements.
    0 = Lower case, 1 = Upper case, 2 = Symbols, 3 = Numbers. */
    unsigned short passRequirements[4] = {0};

    // Holds total length of requirements (total = passRequirements[0] + passRequirements[1] + passRequirements[2] + passRequirements[3];).
    unsigned int total;

    // Selects character type to be picked.
    unsigned short type;

    // Used to ensure character type requirements are met before generating characters of random type to fill length requirement. 
    bool reqMet;

    // Random number generator, calling RNG(gen) will give a random number between 0 and 100.
    std::random_device gen;
    std::uniform_int_distribution<> RNG(0, 100);

    // Prints amount of entropy.
    std::cout << "entropy: " << gen.entropy() << std::endl;

    // Takes password length either from launch args or terminal input.
    if (argc > 1)
    {
        passLength = std::atoi(argv[1]);
        if (argc > 2)
        {
            // Upper case
            passRequirements[0] = std::atoi(argv[2]);
            // Lower case
            passRequirements[1] = std::atoi(argv[3]);
            // Symbols
            passRequirements[2] = std::atoi(argv[4]);
            // Numbers
            passRequirements[3] = std::atoi(argv[5]);
        }
    }
    else
    {
        // self explanatory, takes user input in the case of launch args being given.
        passLength = in.uint("How long should your password be?");
        if (in.prompt("Do you want to set additional password requrements?") == true) {
            passRequirements[0] = in.ushort("How many Upper case characters?");
            passRequirements[1] = in.ushort("How many lower case characters?");
            passRequirements[2] = in.ushort("How many Symbols?");
            passRequirements[3] = in.ushort("How many Numbers?");
        }
    }

    // Finds the total of elements in array "passRequirements", used in some checks later in the code.
    total = passRequirements[0] + passRequirements[1] + passRequirements[2] + passRequirements[3];

    // Picks the larger of "passLength" and "total" to make sure the generator can produce a password meeting the requirements.
    if (passLength < total)
    {
        std::cout << "Password Requirements greater than password length!, Setting Password length to meet requirements\n";
        passLength = total;
    }

    std::cout << "Password: ";

    // Picks and outputs random characters.
    for (unsigned int i = 0; i < passLength; i++)
    {
        reqMet = false;
        while (reqMet == false)
        {
            type = RNG(gen) % 4;

            // Ensures requirements are met before expending remaining characters as random types.
            if (passRequirements[type] != 0 && total != 0)
            {
                // Calls "pick" function with type of character wanted and a random number for character selection.
                pick(type, RNG(gen));

                // Decreases "passRequirements[type]" and "total" by 1 so the program knows when requirements are met.
                passRequirements[type] -= 1;
                total -= 1;

                // exits loop.
                reqMet = true;
            }
            // Outputs character of any type if character type requirements are met.
            else if (total == 0)
            {
                // Calls "pick" function with type of character wanted and a random number for character selection.
                pick(type, RNG(gen));

                // exits loop.
                reqMet = true;
            }
        }
    }
    // Prints a new line and exits program.
    std::cout << std::endl;
    
    #ifdef WIN32
        system("pause");
    #endif
    
    return 0;
}
