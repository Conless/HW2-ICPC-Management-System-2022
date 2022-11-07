// The implementation of include/ICPC.h
// This source contains the main operation functions of the ICPC Management System

// Author: Conless
// Date: 2022-11-02
// File name: /src/ICPC.cc

#include "ICPC.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <unordered_map>

#include "data.h"
#include "resource.h"

// The judge flags of the system
int started_flag = 0, freeze_flag = 0;
int team_cnt = 0, problem_cnt = 0, submit_cnt = 0;

// The hash map which returns the id of a team
std::unordered_map<std::string, int> team_key;

// The data of all teams
std::vector<TeamData> team_list;

// The rank list of all teams
std::set<int, CompareTeam> rank_list;

// Function used when inputting, to skip a word of skip to a unique char
void skipword(const char end_sign = ' ') {
    getchar();
    while (getchar() != end_sign)
        ;
}

// Read a string separated by space
void rdstr(std::string &s, const int max_len = 30) {
    char str[max_len];
    scanf("%s", str);
    s = static_cast<std::string>(str);
    return;
}

// Read and judge the input messages
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

// The implementation of the compare function of two teams, here used a simple trick in order to reduce the time of comparing
// two same teams
bool CompareTeam::operator()(const int &a, const int &b) const { return a == b ? false : team_list[a] < team_list[b]; }

// Add a team
void AddTeam(const std::string &team_name) {
    if (!started_flag) {            // Judge if the competition started
        if (!team_key[team_name]) { // Judge if the team has been added
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

// Start the competition and initialize the rank list
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

// Submit a problem
void SubmitProblem(const std::string &problem_name, const std::string &team_name, const int submit_status, const int tim) {
    int problem_key = problem_name[0] - 'A';
    Submission new_sub(team_key[team_name], problem_key, submit_status, tim, submit_cnt++);
    if (!freeze_flag) { // If the scoreboard is not frozen
        if (submit_status == kAC) {
            rank_list.erase(new_sub.tid);           // First erase the team before the submission
            team_list[new_sub.tid].submit(new_sub); // Edit the submit data of the team
            rank_list.insert(new_sub.tid);          // Insert it back
        } else {
            team_list[new_sub.tid].submit(new_sub);
        }
    } else {
        team_list[new_sub.tid].submitf(new_sub);
    }
}

void FlushBoard() {
    int rk_cnt = 0;
    for (auto it : rank_list) { // Read the rank list from the top to last
        team_list[it].rank =
            ++rk_cnt; // Pre-save the rank data of each team, which can reduce the time cost when querying the ranking to O(1)
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
    for (auto it : rank_list) { // Output the original scoreboard
        team_list[it].output_info(rk_cnt++);
        team_list[it].output_data_freezed(problem_cnt);
        std::cout << '\n';
    }
    for (auto it : rank_list) // Pre-edit the teams which have no ac records after, which would not make a change to the ranking
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
    do { // Edit the teams with ac records
        found_frz = 0;
        auto it = it_las; // Record where we reached at the last search
        if (it == rank_list.begin())
            break;
        do {
            it_las = it;
            it--;
            if (team_list[*it].frozen()) { // If this team have frozen ac records
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
                    if (team_list[*it].frozen(i)) { // If the problem is frozen
                        team_list[*it].unfreeze(i);
                        last_place[*it] = i + 1;
                        break;
                    }
                }
                it_nex = rank_list.insert(*it).first; // The team that it replaces
                it_nex++;
                if (it_nex != rank_list.end() && las_nex != *it_nex)
                    team_list[*it].output_data_replace(team_list[*it_nex].team_name);
                break;
            }
        } while (it != rank_list.begin());
    } while (found_frz);
    rk_cnt = 1;
    for (auto it : rank_list) { // Output the new scoreboard
        team_list[it].output_info(rk_cnt);
        team_list[it].output_data(problem_cnt);
        team_list[it].rank = rk_cnt;
        rk_cnt++;
    }
    freeze_flag = 0;
}

void QueryRanking(const std::string &team_name) {
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

inline int JudgeSubStatus(const std::string &submit_status) {
    for (int i = 0; i < 5; i++) {
        if (submit_status == kSubmitStatus[i])
            return i;
    }
    return -1;
}

void QuerySubmission(const std::string &team_name, const std::string &problem_name, const int submit_status) {
    auto iter = team_key.find(team_name);
    if (iter == team_key.end())
        std::cout << kQsubNoTeam << '\n';
    else {
        std::cout << kQsubSuc << '\n';
        int tid = iter->second;
        Submission las_sub(0, 0, 0, 0, 0);
        if (problem_name == "ALL") { // If we want to find the last submission of all problems
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
        if (las_sub.tim) // If the submission is found
            std::cout << team_name << " " << static_cast<char>(las_sub.pid + 'A') << " " << kSubmitStatus[las_sub.status] << " "
                      << las_sub.tim << '\n';
        else
            std::cout << kQsubNoSub << '\n';
    }
    return;
}

bool OperateMsg(const InputMessage &msg) {
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