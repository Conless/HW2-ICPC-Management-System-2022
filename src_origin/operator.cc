#include "../include/operator.h"
#include "../include/resource.h"
#include "../include/data.h"

#include <iostream>

int competition_started_status = 0;

inline int JudgeSubStatus(const std::string submit_status) {
    for (int i = 0; i < 5; i++) {
        if (submit_status == kSubmitStatus[i])
            return i;
    }
    return -1;
}

bool OperateMsg(const InputMessage msg) {
    if (msg.opt == kAdd) {
        AddTeam(msg.data[0]);
    } else if (msg.opt == kStart) {
        StartCompetition(std::stoi(msg.data[0]), std::stoi(msg.data[1]));
    } else if (msg.opt == kSub) {
        SubmitProblem(msg.data[0], msg.data[1], JudgeSubStatus(msg.data[2]), std::stoi(msg.data[3]));
    } else if (msg.opt == kFlush) {
        FlushBoard();
    } else if (msg.opt == kFreeze) {
        FreezeBoard();
    } else if (msg.opt == kScroll) {
        ScrollBoard();
    } else if (msg.opt == kQrank) {
        QueryRanking(msg.data[0]);
    } else if (msg.opt == kQsub) {
        QuerySubmission(msg.data[0], msg.data[1], JudgeSubStatus(msg.data[2]));
    } else {
        return 0;
    }
    return 1;
}

void AddTeam(std::string team_name) {
    std::cout << "ADD " << team_name << std::endl;
    if (!competition_started_status) {
        if (AddTeamList(team_name)) {
            std::cout << kAddTeamSuc << std::endl;
        } else {
            std::cout << kAddTeamDuplicated << std::endl;
        }
    } else {
        std::cout << kAddTeamAfterStarted << std::endl;
    }
    return;
}

void StartCompetition(const int duration_time, int problem_count) {
    std::cout << "START " << duration_time << " " << problem_count << std::endl;
    if (!competition_started_status) {
        competition_started_status = 1;
        std::cout << kStartSuc << std::endl;
    } else {
        std::cout << kStartAlready;
    }
    return;
}

void FlushBoard() {
    std::cout << "FLUSH" << std::endl;
    FlushAllTeam();
    std::cout << kFlushSuc << std::endl;
    return;
}

void FreezeBoard() {
    std::cout << "FREEZE" << std::endl;
    return;
}

void ScrollBoard() {
    std::cout << "SCROLL" << std::endl;
    return;
}

void QueryRanking(const std::string team_name) {
    std::cout << "QRANK " << team_name << std::endl;
    return;
}

void QuerySubmission(const std::string team_name, const std::string problem_name, const int submit_status) {
    std::cout << "QSUB " << team_name << " " << problem_name << " " << submit_status << std::endl;
    return;
}