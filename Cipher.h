#ifndef CYPHER_H
#define CYPHER_H

#include <string>

// Abstract Base Class
class Cipher
{
public:
    /**
     * Abstract (pure virtual) function encode
     * @param decodedMsg -  message that requires encoding
     * @return true if encode was successful
    */
    virtual bool encode(std::string msg) = 0;

    /**
     * Abstract (pure virtual) function decode
     * @param encodedMsg - encoded message that requires decoded
     * @return true if decode was successful
     */
    virtual bool decode(std::string msg) = 0;

    /**
     *
     * Abstract Helper function (pure virtual) to check if a character is valid for a cipher
     * @param c - character to check
     * @return true if character may be used in the cipher
     */
virtual bool helperFunction (char) = 0;
    inline std::string getEncoded() const { return encoded; }

    inline std::string getDecoded() const { return decoded; }

    inline std::string getCipherName() const { return cipherName; }

protected:
    /**
     * Protected constrcutor, sets the Cipher name
     * May only be called by derived classes
     * @param name - name to set for cipherName
     */
Cipher(std::string cipherName) : cipherName(cipherName) {}
    /**
     * Stores a decoded message
     */
    std::string decoded;

    /**
     * Stores an encoded message
     */
    std::string encoded;

    /**
     * Name of the cipher
     */
    std::string cipherName;
};
#endif
