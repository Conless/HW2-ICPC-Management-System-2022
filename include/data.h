#include <string>
#include <vector>

const int MAXM = 26;

class Submission {
  public:
    int tid, pid, status, tim, submitid;

  public:
    Submission() {}
    Submission(const Submission &x) : tid(x.tid), pid(x.pid), status(x.status), tim(x.tim), submitid(x.submitid) {}
    Submission(int tid, int pid, int status, int tim, int submitid)
        : tid(tid), pid(pid), status(status), tim(tim), submitid(submitid) {}
    bool operator<(const Submission x) const;
};

class SubmitData {
  public:
    int ac_cnt, submit_tot;
    int submit_cnt[MAXM], submit_cnt_bfac[MAXM];
    int ac_tim[MAXM];
    Submission las_sub[MAXM][4];

  public:
    SubmitData();
    SubmitData(const SubmitData &x);
    void clear();
};

class TeamData {
  public:
    std::string team_name;
    int tid, penalty;
    SubmitData sub, subf;
    std::vector<int> ac_tim_sort;

  public:
    TeamData() {}
    TeamData(std::string team_name, int tid) : team_name(team_name), tid(tid) {}
    inline bool aced_problem(int pid) { return sub.ac_tim[pid] || subf.ac_tim[pid]; }
    void submit(const Submission x);
    void submitf(const Submission x);
};