// The declaration of the data type used in the ICPC Management System
// This source contains the declaration of class Submission, SubmitData and TeamData
// The implementation of it is in /src/data.cc

// Author: Conless
// Date: 2022-11-01
// File name: /include/data.h

#ifndef ICPC_DATA_H
#define ICPC_DATA_H

#include <string>
#include <vector>

const int MAXM = 26;

// The submission of a problem by a team
class Submission {
  public:
    int tid, pid, status, tim, submitid;

  public:
    Submission() {}
    Submission(const Submission &x) : tid(x.tid), pid(x.pid), status(x.status), tim(x.tim), submitid(x.submitid) {}
    Submission(int tid, int pid, int status, int tim, int submitid)
        : tid(tid), pid(pid), status(status), tim(tim), submitid(submitid) {}
    bool operator<(const Submission &x) const;
};

// The whole submit data of a team, separated when frozen and not frozen
class SubmitData {
  public:
    int ac_cnt, submit_tot;
    int submit_cnt[MAXM], submit_cnt_bfac[MAXM];
    int ac_tim[MAXM];
    Submission las_sub[MAXM][4];

  public:
    SubmitData();
    SubmitData(const SubmitData &x);
};

// The whole team data
class TeamData {
  public:
    std::string team_name;
    int rank, penalty;

  private:
    int tid;
    std::vector<int> ac_tim_sort;
    SubmitData sub, subf;

    // If setting all the data as public data, some functions of the class can be deleted. However, in order to better use the
    // feature of a class-type, here set some of the data as private data

  public:
    // The constructors of the TeamData
    TeamData() { penalty = 0; }
    TeamData(std::string team_name, int tid) : team_name(team_name), tid(tid), penalty(0) {}

    // Some judge functions
    inline bool aced_problem(int pid) { return sub.ac_tim[pid] || subf.ac_tim[pid]; }
    inline bool frozen() { return subf.submit_tot; }
    inline bool frozen(int pid) { return subf.submit_cnt[pid]; }

    // The compare function of TeamData
    bool operator<(const TeamData &x) const;

    // Get the last submission of a team
    Submission last_submit(int pid, int st) { return std::max(sub.las_sub[pid][st], subf.las_sub[pid][st]); }

    // Operation functions used in the system
    void submit(const Submission &x);
    void submitf(const Submission &x);
    void output_info(const int now_rank);
    void output_data(const int problem_cnt);
    void output_data_freezed(const int problem_cnt);
    void output_data_replace(const std::string &replaced_team);
    void unfreeze(const int pid);
};

#endif
