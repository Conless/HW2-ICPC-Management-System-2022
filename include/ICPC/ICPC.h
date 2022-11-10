// The declaration of the operation functions used in the ICPC Management System
// This source is the main header file of the whole project
// The implementation of it is in /src/ICPC.cc

// Author: Conless
// Date: 2022-11-02
// File name: /include/ICPC.h

#ifndef ICPC_H
#define ICPC_H

#include <iostream>
#include <string>

// The data type of an input message
struct InputMessage {
    int opt;
    std::string data[4];
};

// The compare function of two teams, which is stored in the form of id number in the set
class CompareTeam {
  public:
    bool operator()(const int &a, const int &b) const;
};

// The operation functions
void ReadMsg(InputMessage &msg);
void AddTeam(const std::string &team_name);
void StartCompetition(const int duration_time, int problem_count);
void SubmitProblem(const std::string &problem_name, const std::string &team_name, const int submit_status, const int tim);
void FlushBoard();
void FreezeBoard();
void OutputData();
void ScrollBoard();
void QueryRanking(const std::string &team_name);
void QuerySubmission(const std::string &team_name, const std::string &problem_name, const int submit_status);
bool OperateMsg(const InputMessage &msg);

#endif
