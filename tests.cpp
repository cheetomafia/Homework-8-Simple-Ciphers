#include <memory>
#include <iostream>

#include "tests.h"
#include "CaesarCipher.h"
#include "XORCipher.h"

using namespace std;

bool testEncode(shared_ptr<Cipher> cipher, string msg)
{
    bool status = true;
    cout << "Encoding message using " << cipher->getCipherName() << " Cipher encoder!\n";

    // Attempt encode
    // Note: This uses polymorphism. cipher is shared pointer of Abstract Base Class Cipher
    // However when encode is invoked it calls the encode function of the
    // Derived Concrete Class in which it points
    if( cipher->encode(msg) )
    {
        cout << "Encoded Message is:\n";
        cout << cipher->getEncoded() << endl;
    }else{
        cout << "Failed to encode message!\n";
        status = false;
    }

    return status;
}

bool testDecode(shared_ptr<Cipher> cipher, string msg)
{
    bool status = true;
    cout << "Decoding message using " << cipher->getCipherName() << " Cipher decoder!\n";

    // Attempt decode
    // Note: This uses polymorphism. cipher is shared pointer of Abstract Base Class Cipher
    // However when decode is invoked it calls the decode function of the
    // Derived Concrete Class in which it points
    if( cipher->decode(msg) )
    {
        cout << "Decoded Message is:\n";
        cout << cipher->getDecoded() << endl;
    }else{
        cout << "Failed to decode message!\n";
        status = false;
    }

    return status;
}

bool printCipherDetails(shared_ptr<Cipher> cipher)
{
    bool status = true;

    // We want to print out the detail of the Derived Class that cipher points to
    // This information is not available in the Base Class Cipher
    // Therefore we need to downcast to gain access to that information

    // Use dynamic_pointer_cast to attempt downcast Cipher to CaesarCipher
    shared_ptr<CaesarCipher> cc = dynamic_pointer_cast<CaesarCipher>(cipher);

    // Use dynamic_pointer_cast to attempt downcast Cipher to XORCipher
    shared_ptr<XORCipher> xc = dynamic_pointer_cast<XORCipher>(cipher);

    cout << "Details for Cipher Used:\n";

    // If a cast is successful it will not be a nullptr
    // Go through and check which downcast was successful and print out extra details
    if( cc != nullptr ){
        cout << cc->getCipherName() << " Cipher used a shift of " << cc->getShiftValue() << endl;
    }else if( xc != nullptr ){
        cout << xc->getCipherName() << " Cipher used a key of " << xc->getKeyValue() << endl;
    }else{
        cout << "Unable to obtain cipher details!\n";
        status = false;
    }

    return status;
}
