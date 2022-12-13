#include <iostream>
#include <string>
#include "XORCipher.h"

XORCipher::XORCipher(char key) : key(key), Cipher(XORCipher::CIPHER_NAME) {}


bool XORCipher::encode(std::string msg) {
  char ch;
  for(int i = 0; msg[i] != '\0'; i++){
    ch = msg[i];
    if (helperFunction(ch)) {
      ch = ch ^ key;
      msg[i] = ch;
    }
    else {
      return false;
    }
  }
  encoded = msg;
  return true;
}

bool XORCipher::decode(std::string msg) {
  char ch;
  for(int i = 0; msg[i] != '\0'; i++){
    ch = msg[i];
    if (helperFunction(ch)) {
      ch = ch ^ key;
      msg[i] = ch;
    }
    else {
      return false;
    }
  }
  decoded = msg;
  return true;
}
 
bool XORCipher::helperFunction(char key) {
  return true;
}

const std::string XORCipher::CIPHER_NAME = "XOR";
