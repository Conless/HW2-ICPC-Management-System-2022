#include "../include/input.h"

#include "../include/resource.h"

void skipword(const char end_sign = ' ') {
    getchar();
    while (getchar() != end_sign)
        ;
}

void rdstr(std::string &s, const int max_len = 30) {
    char str[max_len];
    scanf("%s", str);
    s = static_cast<std::string>(str);
    return;
}

void InputMessage::Read() {
    std::string option;
    rdstr(option);
    if (option == "ADD_TEAM") {
        opt = kAdd;
        data = new std::string[1];
        rdstr(data[0]);
    } else if (option == "START") {
        opt = kStart;
        data = new std::string[2];
        skipword();
        rdstr(data[0]);
        skipword();
        rdstr(data[1]);
        std::cout << data[0] << " " << data[1] << std::endl;
    } else if (option == "SUBMIT") {
        opt = kSub;
        data = new std::string[4];
        rdstr(data[0]);
        skipword();
        rdstr(data[1]);
        skipword();
        rdstr(data[2]);
        skipword();
        rdstr(data[3]);
    }
}