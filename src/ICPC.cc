#include "../include/ICPC.h"

#include <ctime>
#include <iostream>
#include <set>
#include <unordered_map>

#include "../include/data.h"
#include "../include/resource.h"


int started_flag = 0, freeze_flag = 0;
int team_cnt = 0, problem_cnt = 0, submit_cnt = 0;

std::unordered_map<std::string, int> team_key;

std::vector<TeamData> team_list;

std::set<int, CompareTeam> rank_list;

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

void ReadMsg(InputMessage &msg) {
    std::string option;
    rdstr(option);
    if (option == "ADDTEAM") {
        msg.opt = kAdd;
        rdstr(msg.data[0]);
    } else if (option == "START") {
        msg.opt = kStart;
        skipword();
        rdstr(msg.data[0]);
        skipword();
        rdstr(msg.data[1]);
    } else if (option == "SUBMIT") {
        // tagggg = 1;
        msg.opt = kSub;
        rdstr(msg.data[0]);
        skipword();
        rdstr(msg.data[1]);
        skipword();
        rdstr(msg.data[2]);
        skipword();
        rdstr(msg.data[3]);
    } else if (option == "FLUSH") {
        msg.opt = kFlush;
    } else if (option == "FREEZE") {
        msg.opt = kFreeze;
    } else if (option == "SCROLL") {
        msg.opt = kScroll;
    } else if (option == "QUERY_RANKING") {
        msg.opt = kQrank;
        rdstr(msg.data[0]);
    } else if (option == "QUERY_SUBMISSION") {
        msg.opt = kQsub;
        rdstr(msg.data[0]);
        skipword('=');
        rdstr(msg.data[1]);
        skipword('=');
        rdstr(msg.data[2]);
    } else if (option == "END") {
        msg.opt = kEnd;
    }
}

bool CompareTeam::operator()(const int &a, const int &b) const { return a == b ? false : team_list[a] < team_list[b]; }

void AddTeam(std::string team_name) {
    if (!started_flag) {
        if (!team_key[team_name]) {
            std::cout << kAddTeamSuc << '\n';
            team_key[team_name] = team_cnt;
            team_list.push_back(TeamData(team_name, team_cnt));
            rank_list.insert(team_cnt);
            team_cnt++;
        } else {
            std::cout << kAddTeamDuplicated << '\n';
        }
    } else {
        std::cout << kAddTeamAfterStarted << '\n';
    }
    return;
}

void StartCompetition(const int duration_time, int problem_count) {
    if (!started_flag) {
        started_flag = 1;
        problem_cnt = problem_count;
        int rk_cnt = 1;
        for (auto it : rank_list)
            team_list[it].rank = rk_cnt++;
        std::cout << kStartSuc << '\n';
    } else {
        std::cout << kStartAlready << '\n';
    }
    return;
}

void SubmitProblem(const std::string problem_name, const std::string team_name, const int submit_status, const int tim) {
    int problem_key = problem_name[0] - 'A';
    Submission new_sub(team_key[team_name], problem_key, submit_status, tim, submit_cnt++);
    if (!freeze_flag) {
        if (submit_status == kAC) {
            rank_list.erase(new_sub.tid);
            team_list[new_sub.tid].submit(new_sub);
            rank_list.insert(new_sub.tid);
        } else {
            team_list[new_sub.tid].submit(new_sub);
        }
    } else {
        team_list[new_sub.tid].submitf(new_sub);
    }
}

void FlushBoard() {
    int rk_cnt = 0;
    for (auto it : rank_list) {
        team_list[it].rank = ++rk_cnt;
    }
    std::cout << kFlushSuc << '\n';
    return;
}

void FreezeBoard() {
    if (!freeze_flag) {
        freeze_flag = 1;
        std::cout << kFreezeSuc << '\n';
    } else {
        std::cout << kFreezeFail << '\n';
    }
    return;
}

void ScrollBoard() {
    if (!freeze_flag) {
        std::cout << kScrollFail << '\n';
        return;
    }
    bool found_frz;
    int rk_cnt = 1;
    std::cout << kScrollSuc << '\n';
    auto endd = rank_list.end();
    for (auto it: rank_list) {
        team_list[it].output_info(rk_cnt++);
        team_list[it].output_data_freezed(problem_cnt);
        std::cout << '\n';
    }
    for (auto it: rank_list)
        if (team_list[it].frozen()) {
            for (int i = 0; i < problem_cnt; i++) {
                if (!team_list[it].aced_problem(i) && team_list[it].frozen(i)) {
                    team_list[it].unfreeze(i);
                }
            }
        }
    static std::vector<int> last_place;
    last_place.assign(team_cnt, 0);
    auto it_las = rank_list.end();
    do {
        found_frz = 0;
        auto it = it_las;
        if (it == rank_list.begin())
            break;
        do {
            it_las = it;
            it--;
            if (team_list[*it].frozen()) {
                found_frz = 1;
                auto it_nex = it;
                it_nex++;
                int las_nex;
                if (it_nex == rank_list.end())
                    las_nex = -1;
                else
                    las_nex = *it_nex;
                rank_list.erase(*it);
                for (int i = last_place[*it]; i < problem_cnt; i++) {
                    if (team_list[*it].frozen(i)) {
                        team_list[*it].unfreeze(i);
                        last_place[*it] = i + 1;
                        break;
                    }
                }
                it_nex = rank_list.insert(*it).first;
                it_nex++;
                if (it_nex != rank_list.end() && las_nex != *it_nex)
                    team_list[*it].output_data_replace(team_list[*it_nex].team_name);
                break;
            }
        } while (it != rank_list.begin());
    } while (found_frz);
    rk_cnt = 1;
    for (auto it: rank_list) {
        team_list[it].output_info(rk_cnt);
        team_list[it].output_data(problem_cnt);
        team_list[it].rank = rk_cnt;
        rk_cnt++;
    }
    freeze_flag = 0;
}

void QueryRanking(const std::string team_name) {
    if (team_key.find(team_name) == team_key.end())
        std::cout << kQrankFail << '\n';
    else {
        std::cout << kQrankSuc << '\n';
        if (freeze_flag)
            std::cout << kQrankWarn << '\n';
        std::cout << team_name << " NOW AT RANKING " << team_list[team_key[team_name]].rank << '\n';
    }
    return;
}

inline int JudgeSubStatus(const std::string submit_status) {
    for (int i = 0; i < 5; i++) {
        if (submit_status == kSubmitStatus[i])
            return i;
    }
    return -1;
}

void QuerySubmission(const std::string team_name, const std::string problem_name, const int submit_status) {
    if (team_key.find(team_name) == team_key.end())
        std::cout << kQsubNoTeam << '\n';
    else {
        std::cout << kQsubSuc << '\n';
        int tid = team_key[team_name];
        Submission las_sub(0, 0, 0, 0, 0);
        if (problem_name == "ALL") {
            if (submit_status == kALL) {
                for (int i = 0; i < problem_cnt; i++)
                    for (int j = 0; j < 4; j++) {
                        las_sub = std::max(las_sub, team_list[tid].last_submit(i, j));
                    }
            } else {
                for (int i = 0; i < problem_cnt; i++) {
                    las_sub = std::max(las_sub, team_list[tid].last_submit(i, submit_status));
                }
            }
        } else {
            int pid = problem_name[0] - 'A';
            if (submit_status == kALL) {
                for (int j = 0; j < 4; j++) {
                    las_sub = std::max(las_sub, team_list[tid].last_submit(pid, j));
                }
            } else {
                las_sub = std::max(las_sub, team_list[tid].last_submit(pid, submit_status));
            }
        }
        if (las_sub.tim)
            std::cout << team_name << " " << static_cast<char>(las_sub.pid + 'A') << " " << kSubmitStatus[las_sub.status] << " "
                      << las_sub.tim << '\n';
        else
            std::cout << kQsubNoSub << '\n';
    }
    return;
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
        std::cout << kEndCompetition << '\n';
        return 0;
    }
    return 1;
}