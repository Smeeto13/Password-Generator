# Password-Generator
Simple yet fast Password-Generator writen in C++, Tested on X86_64 and ARM64 


Command line args:
  * Password Length
  * Minimum Number of Upper case
  * Minimum Number of Lower case
  * Minimum Number of Symbols
  * Minimum Number of Numbers
  
 Example:
    
    ./PassGen 10 4 3 2 1
    
   Will create a 10 character password with 4 Upper case, 3 Lower case, 2 Symbol and 1 Number characters.
  
   If the Password length given is insurficient to meet the min char requrements it will be increased to meet requirements, if the password langth is longer then the minimum char requirement random characters will be selected to meet the length requirement.
   
   If the program is ran without command line arguments it will run in a interactive mode.
   
   If using command line operation the lenght must be provided, if one of the password requirements are provided they all must be.
  
Linux/Unix Build Instructions:
  
    g++ 'Pass Gen.cpp' input.cpp -O2 -march=native -o PassGen
