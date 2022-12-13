#include "CaesarCipher.h"
#include <iostream>
#include <string>

CaesarCipher::CaesarCipher(int shift) : shift(shift), Cipher(CaesarCipher::CIPHER_NAME) {}

bool CaesarCipher::encode(std::string msg) {
  char ch;
  for(int i = 0; msg[i] != '\0'; i++){
    ch = msg[i];
    if (helperFunction(ch)) {
      ch = ch - char(shift);
      if(!helperFunction(ch+char(26))){
        ch = ch;
      }
      else {
        ch = ch + char(26);
      }
      msg[i] = ch;
    }
    else if (ch == ' ') {
      continue;
    }
    else {
      return false;
    }
  }
  encoded = msg;
  return true;
}

bool CaesarCipher::decode(std::string msg) {
  char ch;
  for(int i = 0; msg[i] != '\0'; i++){
    ch = msg[i];
    if (ch == ' '){
      continue;
    }
    else if(helperFunction(ch)){
      ch = ch + shift;
      if(!helperFunction(ch-char(26))){
        ch = ch;
      }
      else {
        ch = ch - char(26);
      }
      
      msg[i] = ch;
    } 
    else{
      return false;
    }
  }
  decoded = msg;
  return true;
}

bool CaesarCipher::helperFunction(char charactor){
  return (int(charactor) >= 65 && int(charactor) <=90);
}

const std::string CaesarCipher::CIPHER_NAME = "Caesar";
