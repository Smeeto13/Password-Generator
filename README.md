# Password-Generator
Simple Password-Generator writen in C++


Command line args:
  * Password Length
  * Minimum Number of Upper case
  * Minimum Number of Lower case
  * Minimum Number of Symbols
  * Minimum Number of Numbers
  
 Example:
    
    ./PassGen 10 4 3 2 1
    
   Will create a 10 character password with 4 Upper case, 3 Lower case, 2 Symbol and 1 Number characters.
  
   If the Password length given is insurficient to meet the min char requrements it will be increased to meet requirements.
  
Linux/Unix Build Instructions:
  
    g++ 'Pass Gen.cpp' input.cpp -O2 -march=native -o PassGen
