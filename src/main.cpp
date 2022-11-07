// The main header file
#include "ICPC.h"

int main() {
    std::ios::sync_with_stdio(false);           // stop the sync with stdio
    while (true) {
        InputMessage msg;
        ReadMsg(msg);                                 // Read a message and judge its type 
        if (!OperateMsg(msg))                         // Operate the message it reads
            break;
    }
    return 0;
}
