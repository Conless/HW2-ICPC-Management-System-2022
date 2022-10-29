#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

class InputMessage {
  public:
    int opt;
    
    std::string option;
    std::string *data;

  public:
    void Read();
};

#endif
