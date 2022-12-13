#ifndef TESTS_H
#define TESTS_H

#include <memory>
#include <string>
#include "Cipher.h"

/**
 * Test encoding a message
 * @param cipher - shared smart pointer to base class cipher to use
 * @param msg - string of the message to encode
 * @return true if encode is success else false
 */
bool testEncode(std::shared_ptr<Cipher> cipher, std::string msg);

/**
 * Test decoding a message
 * @param cipher - shared pointer to base class cipher to use
 * @param msg - string of the message to decode
 * @return true if decode is success else false
 */
bool testDecode(std::shared_ptr<Cipher> cipher, std::string msg);

/**
 * Print out details of specific cipher using downcasting
 * @param cipher - shared smart pointer to base class cipher
 * @return true if downcasts and details printed out else false
 */
bool printCipherDetails(std::shared_ptr<Cipher> cipher);

/**
 * String constant for encode action
 */
const std::string ACTION_ENCODE = "ENCODE";

/**
 * String constant for decode action
 */
const std::string ACTION_DECODE = "DECODE";

#endif
