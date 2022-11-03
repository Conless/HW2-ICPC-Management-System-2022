// The main header file
#include "../include/ICPC.h"


int main() {
    freopen("data/bigger.in", "r", stdin);
    freopen("test.out", "w", stdout);
    std::ios::sync_with_stdio(false);           // stop the sync with stdio
    while (true) {
        InputMessage msg;
        ReadMsg(msg);                                 // Read a message and judge its type 
        if (!OperateMsg(msg))                         // Operate the message it reads
            break;
    }
    printf("%.2lf", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}