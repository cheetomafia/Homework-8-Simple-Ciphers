#ifndef CAESARCYPHER_H
#define CAESARCYPHER_H

#include "Cipher.h"

// Derived Concrete Class of Abstract Base Class Cipher
class CaesarCipher : public Cipher
{
public:
    /**
     * Constructor
     * @param shift - set amount to shift in cipher
     */
    CaesarCipher(int);
    /**
    * Concrete implementation of encode, perform Caesar encode of message
    * @param decodedMsg - string message to encode
    * @return true if encode is successful else false
    */
    bool encode(std::string msg) override;
    /**
    * Concrete implementation of decode, perform Caesar decode of message
    * @param encodedMsg - string message to decode
    * @return true if decode is successful else false
    */
   bool decode(std::string msg) override; 
    /**
     * Checks is character is valid for Caesar cipher
     * For this implementation only valid are capital A-Z
     * Hint: ASCII representation of A-Z are decimal numbers 65-90
     * @param c - character to check
     * @return - true is character is A-Z otherwise false
     */
  bool helperFunction(char) override;  
    /**
     *
     * @return shift value used with the cipher
     */
    inline int getShiftValue() const { return shift; };

    /**
     * Static const name for Caesar cipher
     */
    static const std::string CIPHER_NAME;
private:

    /**
     * Shift value for Caesar cipher
     */
    int shift;

};


#endif
