# Homework-8-Simple-Ciphers
Homework 8
===
In this Homework you will be exploring a couple simple cipher algorithms.
In adddition, you will gain experience working with inheritance
and polymorphism. The two ciphers you will implement are the 
Caesar cipher and XOR cipher. 
Below you will find additional information for each of these.

For this homework, you will be given header (.h) files and you 
will be required to implement the corresponding source (.cpp) files.
The header files are also not fully implemented but comments have
been provided to guide you through the definitions.

Usage of Inheritance 
===
This homework explores inheritance by defining a base class Cipher.
The Cipher class is meant to define common behavior for all cipher 
classes that inherit from it. For example, all ciphers are expected to 
have an encode function and a decode function. Please read the comments
in the Cipher.h and define/implement the functions/constructors. 

Usage of Polymorphism
===
The Cipher class defines the encode and decode functions, however 
it should not implement them. The cipher class is meant to be abstract
because its methods should be inherited but only implemented in
the derived classes. Thus, the encode and decode methods should be
pure virtual functions to make Cipher to be an abtract class.

Futhermore, the main function (provided) demontrates polymorphism
by using base class pointers (Cipher) to call derived class objects.
The derived class in this case are the CaesarCipher and XORCipher 
classes. Each of these classes have their own implementations for 
encode and decode methods.

Caesar cipher
===
The Caesar cipher is simple substitution cipher that replaces a letter
with another letter a fixed number of positions down the alphabet.

See https://en.wikipedia.org/wiki/Caesar_cipher for more complete inforamtion.

For this homework Pseudo code is provided to help you along the way.

XOR Cipher
===
The XOR cipher is a simple addative ciper that uses the XOR operator
to encode/decode a message. The cipher simply XOR a character with 
and another key character. 

See https://en.wikipedia.org/wiki/XOR_cipher more information.

Psuedo code has been provided to help you.

Caesar Cipher Encode
===
    For each character in message:
       If character is valid (A-Z):
          Convert character from ASCII code (-65) to alphabet number
          Shift number by subtracting cipher shift
          If shifted number > 25:
             Subtract 26 from number
          If shifted number is < 0: 
             Add 26 to the number
          Reconvert number to ASCII Code (+65)
          Add code to encoded message
          * Note: Do not encode any space, keep it a space
       Else:
          return False
     Store encoded message in encoded member variable 
          
Caesar Cipher Decode
===
The decode algorithm is the same procedure as the encode with one
minor difference. Instead of adding the shift value you need 
to add the shift value from the converted ASCII code. 

XOR Cipher Encode/Decode
===
The XOR cipher decode and encode algorithms are the same procedure.

    For each character in message:
       If character is valid (any character):
          XOR character with the XOR key character
          Add to encoded/decoded message
       Else:
          return False
   Store in encoded/decoded member variable

Input Provided main
===
1. Name of cipher to use (Caesar or XOR)
2. Specific cipher info
   Shift amount for Caesar
   Key for XOR  
3. Action (DECODE/ENCODE)
4. Message to encode/decode

Example:
Caesar
3
DECODE
XYZ
