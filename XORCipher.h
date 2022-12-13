#ifndef XORCYPHER_H
#define XORCYPHER_H

#include "Cipher.h"

// Derived Concrete Class of Abstract Base Class Cipher
class XORCipher : public Cipher
{
public:

    /**
     * Constructor
     * @param key - key to use for cipher
     */
 XORCipher(char);   
    /**
     * Concrete implementation of encode, perform XOR encode of message
     * @param decodedMsg - string message to encode
     * @return true if encode is successful else false
     */    
bool encode(std::string msg) override;
    /**
     * Concrete implementation of decode, perform XOR decode of message
     * @param encodedMsg - string message to decode
     * @return true if decode is successful else false
     */
  bool decode(std::string msg) override;
    /**
     * Check if character is valid for XOR cipher
     * @param c - character to check
     * @return true always for XOR cipher
     */
bool helperFunction (char) override;
   bool xorcipherCheck(char); 
    /**
     *
     * @return key used in the cipher
     */
    inline char getKeyValue() const { return key; };

    /**
     * Static const string to the XORCipher name
     */
    static const std::string CIPHER_NAME;

private:

    /**
     * Key used in XOR cipher
     */
    char key;

};

#endif
