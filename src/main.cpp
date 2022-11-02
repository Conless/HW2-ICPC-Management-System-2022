#include "../include/ICPC.h"

int main() {
    freopen("data/1.in", "r", stdin);
    freopen("test.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    while (true) {
        InputMessage msg;
        ReadMsg(msg);
        if (!OperateMsg(msg))
            break;
    }
    return 0;
}