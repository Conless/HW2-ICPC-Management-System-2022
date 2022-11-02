#include <iostream>
#include <string>

struct InputMessage {
    int opt;
    std::string data[4];
};

class CompareTeam {
  public:
    bool operator()(const int &a, const int &b) const;
};

void ReadMsg(InputMessage &msg);

void AddTeam(std::string team_name);

void StartCompetition(const int duration_time, int problem_count);

void SubmitProblem(const std::string problem_name, const std::string team_name, const int submit_status, const int tim);

void FlushBoard();

void FreezeBoard();

void OutputData();

void ScrollBoard();

void QueryRanking(const std::string team_name);

void QuerySubmission(const std::string team_name, const std::string problem_name, const int submit_status);

bool OperateMsg(const InputMessage msg);