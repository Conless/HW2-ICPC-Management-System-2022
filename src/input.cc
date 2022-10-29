#include "../include/input.h"

void InputMessage::Read() {
    std::cin >> option;
    if (option == "ADD_TEAM") {
        opt = 1;
        data = new std::string[1];
        std::cin >> data[0];
    } else if (option == "START") {
        data = new std::string[2];

        std::cin >> data[0];
        std::cin >> data[0];
        
        std::cin >> data[1];
        std::cin >> data[1];
    } else if (option == "SUBMIT") {
        data = new std::string[4];
        
    }
}