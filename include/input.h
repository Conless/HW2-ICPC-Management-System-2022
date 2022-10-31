#ifndef INPUT_H
#define INPUT_H

#include <string>

struct InputMessage {
    int opt;
    std::string *data;
};

void ReadMsg(InputMessage &msg);

#endif
