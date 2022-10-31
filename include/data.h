#include <functional>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Submission {
  public:
    int teamkey, prokey, status, tim;

  public:
    Submission() {}
    Submission(const Submission &x) : teamkey(x.teamkey), prokey(x.prokey), status(x.status), tim(x.tim) {}
    Submission(int teamkey, int prokey, int status, int tim) : teamkey(teamkey), prokey(prokey), status(status), tim(tim) {}
    bool operator<(const Submission x) const { return tim < x.tim; }
};

class Team {
    std::string team_name;
    int key;

    int accepted_cnt, time_used;
    std::set<Submission, std::greater<Submission>> sub[4];
    
  public:
    Team(const std::string, const int key);
    bool operator<(const Team x) const;
    void submit(Submission x);
    void flush();
};

bool AddTeamList(const std::string team_name);
void FlushAllTeam();
void SubmitProblem(const std::string problem_name, const std::string team_name, const int submit_status, const int tim);

