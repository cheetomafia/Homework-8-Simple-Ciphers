#include <memory>
#include <iostream>

#include "tests.h"
#include "CaesarCipher.h"
#include "XORCipher.h"

using namespace std;

// True/false to show prompts before cin requests
// Set to false when running tests
const bool SHOW_PROMPTS = false;

int main() {

    // Storage of values from cin
    string cipherName;
    string msg;
    string action;

    // Result variable
    bool actionStatus;

    // Shared pointer to Abstract Base Class Cipher
    shared_ptr<Cipher> cipher;

    // Request name for the cipher to use
    if( SHOW_PROMPTS ) {
        cout << "Enter Cipher Name: ";
    }
    cin >> cipherName;

    // Use string compare name to know which cipher to setup
    if( cipherName.compare(CaesarCipher::CIPHER_NAME) == 0 )
    {
        // Requested Caesar cipher, it needs a shift value
        int shift;

        // Get shift value
        if( SHOW_PROMPTS ){
            cout << "Enter shift value: ";
        }
        cin >> shift;

        // Setup Polymorphism
        // Assign shared pointer (Abstract Base Class) to point to
        // Concrete Derived Class of Type CaesarCipher
        cipher = make_shared<CaesarCipher>(shift);

    }else if(cipherName.compare(XORCipher::CIPHER_NAME) == 0 ){

        // Requested XOR cipher, it requires a char key
        char key;

        // Get the key
        if( SHOW_PROMPTS ) {
            cout << "Enter key: ";
        }
        cin >> key;

        // Setup Polymorphism
        // Assign shared pointer (Abstract Base Class) to point to
        // Concrete Derived Class of Type XORCipher
        cipher = make_shared<XORCipher>(key);

    }else{
        cout << "Bad cipher name ( " << cipherName << " )\n";
        return -1;
    }

    // Request action (ENCODE or DECODE)
    if( SHOW_PROMPTS ){
        cout << "Enter action: ";
    }
    cin >> action;

    // CHECK proper action entered
    if( ( action.compare(ACTION_ENCODE) != 0 )  && ( action.compare(ACTION_DECODE) != 0 ) )
    {
        cout << "Bad cipher action ( " << action << " )\n";
        return -1;
    }

    // Request for message
    if( SHOW_PROMPTS ) {
        cout << "Enter Msg: ";
        cout.flush();
    }
    getline(cin >> ws, msg);

    // Based on action, perform encode or decode
    // Note: passing a shared pointer of Abstract Base Class type Cipher
    if( action.compare(ACTION_ENCODE) == 0 ) {
        actionStatus = testEncode(cipher, msg);

    }else if( action.compare(ACTION_DECODE) == 0 ) {
        actionStatus = testDecode(cipher, msg);

    }else{
        cout << "Bad cipher action ( " << action << " )\n";
        return -1;
    }

    // Attempt to print out the details of Abstract Base Class Cipher
    // Note: In function downacasting will be applied to get more info
    if( !actionStatus || !printCipherDetails(cipher) ) {
        return -1;
    }

    return 0;
}
