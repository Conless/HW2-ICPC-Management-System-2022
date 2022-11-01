// Here starts the including headers
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// Here starts the definition of important constants, signs and messages

const int MAXM = 30;

// Options Sign
const int kAdd = 1;
const int kStart = 2;
const int kSub = 3;
const int kFlush = 4;
const int kFreeze = 5;
const int kScroll = 6;
const int kQrank = 7;
const int kQsub = 8;
const int kEnd = 0;

// The messages used when adding teams
const std::string kAddTeamSuc = "[Info]Add successfully.";
const std::string kAddTeamAfterStarted = "[Error]Add failed: competition has started.";
const std::string kAddTeamDuplicated = "[Error]Add failed: duplicated team name.";

// The messages used when starting the competition
const std::string kStartSuc = "[Info]Competition starts.";
const std::string kStartAlready = "[Error]Start failed: competition has started.";

// The messages used when flushing
const std::string kFlushSuc = "[Info]Flush scoreboard.";

// The messages used when freezing
const std::string kFreezeSuc = "[Info]Freeze scoreboard.";
const std::string kFreezeFail = "[Error]Freeze failed: scoreboard has been frozen.";

// The messages used when scrolling
const std::string kScrollSuc = "[Info]Scroll scoreboard.";
const std::string kScrollFail = "[Error]Scroll failed: scoreboard has not been frozen.";

// The messages used when querying ranking
const std::string kQrankSuc = "[Info]Complete query ranking.";
const std::string kQrankFail = "[Error]Query ranking failed: cannot find the team.";
const std::string kQrankWarn = "[Warning]Scoreboard is frozen. The ranking may be inaccurate until it were scrolled.";

// The messages used when querying submission
const std::string kQsubSuc = "[Info]Complete query submission.";
const std::string kQsubNoSub = "Cannot find any submission.";
const std::string kQsubNoTeam = "[Error]Query submission failed: cannot find the team.";

// The messages used when ending the competition
const std::string kEndCompetition = "[Info]Competition ends.";

// The submit status
const int kAC = 0;
const int kWA = 1;
const int kRE = 2;
const int kTLE = 3;
const int kALL = 4;
const std::string kSubmitStatus[] = {"Accepted", "Wrong_Answer", "Runtime_Error", "Time_Limit_Exceed", "ALL"};

int tagggg = 1, totcnt;
namespace ReadData {
struct InputMessage {
    int opt;
    std::string data[4];
};

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
} // namespace ReadData

class Submission {
  public:
    int tid, pid, status, tim, submitid;

  public:
    Submission() {}
    Submission(const Submission &x) : tid(x.tid), pid(x.pid), status(x.status), tim(x.tim), submitid(x.submitid) {}
    Submission(int tid, int pid, int status, int tim, int submitid)
        : tid(tid), pid(pid), status(status), tim(tim), submitid(submitid) {}
    bool operator<(const Submission x) const {
        if (tim != x.tim)
            return tim < x.tim;
        return submitid < x.submitid;
    }
    bool exist() { return tim; }
};

std::unordered_map<std::string, int> team_key;

class SubmitData {
  public:
    int ac_cnt, submit_tot;
    int submit_cnt[MAXM], submit_cnt_bfac[MAXM];
    int ac_tim[MAXM];
    Submission las_sub[MAXM][4];

  public:
    SubmitData() {
        ac_cnt = 0;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = 0;
            submit_cnt_bfac[i] = 0;
            ac_tim[i] = 0;
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = {0, 0, 0, 0, 0};
        }
    }
    SubmitData(const SubmitData &x) {
        ac_cnt = x.ac_cnt;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = x.submit_cnt[i];
            submit_cnt_bfac[i] = x.submit_cnt_bfac[i];
            ac_tim[i] = x.ac_tim[i];
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = x.las_sub[i][j];
        }
        // ac_tim_sort = x.ac_tim_sort;
    }
    void clear() {
        ac_cnt = 0;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = 0;
            submit_cnt_bfac[i] = 0;
            ac_tim[i] = 0;
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = {0, 0, 0, 0, 0};
        }
    }
};

class TeamData {
  public:
    std::string team_name;
    int tid, penalty;
    SubmitData sub, subf;
    std::vector<int> ac_tim_sort;

    inline bool aced_problem(int pid) { return sub.ac_tim[pid] || subf.ac_tim[pid]; }

  public:
    TeamData() {}
    TeamData(std::string team_name, int tid) : team_name(team_name), tid(tid) {}
    void submit(const Submission x) {
        sub.submit_cnt[x.pid]++;
        sub.las_sub[x.pid][x.status] = x;
        if (x.status == kAC && !aced_problem(x.pid)) {
            sub.ac_cnt++;
            sub.ac_tim[x.pid] = x.tim;
            ac_tim_sort.push_back(x.tim);
            penalty += 20 * sub.submit_cnt_bfac[x.pid] + x.tim;
        } else if (x.status != kAC && !aced_problem(x.pid)) {
            sub.submit_cnt_bfac[x.pid]++;
        }
        return;
    }
    void submitf(const Submission x) {
        subf.submit_tot++;
        subf.submit_cnt[x.pid]++;
        subf.las_sub[x.pid][x.status] = x;
        if (x.status == kAC && !aced_problem(x.pid)) {
            subf.ac_cnt++;
            subf.ac_tim[x.pid] = x.tim;
        } else if (x.status != kAC && !aced_problem(x.pid)) {
            subf.submit_cnt_bfac[x.pid]++;
        }
        return;
    }
    Submission qsub(const int pid, const int status) { return std::max(sub.las_sub[pid][status], subf.las_sub[pid][status]); }
};

std::vector<TeamData> team_list_sync;
// TeamData team_list_sync[10005];

int started_flag = 0, freeze_flag = 0;
int team_cnt = 0, problem_cnt = 0, submit_cnt = 0;

// std::unordered_map<std::string, int> name_rank;
std::vector<int> name_rank;

// class CompareTeam {
//   public:
//     bool operator()(const int &a, const int &b) const {
//         if (a == b)
//             return false;
//         if (team_list[a].sub.ac_cnt != team_list[b].sub.ac_cnt)
//             return team_list[a].sub.ac_cnt > team_list[b].sub.ac_cnt;
//         if (team_list[a].penalty != team_list[b].penalty)
//             return team_list[a].penalty < team_list[b].penalty;
//         if (team_list[a].sub.ac_cnt) {
//             int cnt1 = 0, cnt2 = 0;
//             int tim1[30], tim2[30];
//             for (int i = 0; i < problem_cnt; i++) {
//                 if (team_list[a].sub.ac_tim[i])
//                     tim1[cnt1++] = team_list[a].sub.ac_tim[i];
//                 if (team_list[b].sub.ac_tim[i])
//                     tim2[cnt2++] = team_list[b].sub.ac_tim[i];
//             }
//             // memcpy(tim1, team_list[a].sub.ac_tim, sizeof(tim1));
//             // memcpy(tim2, team_list[b].sub.ac_tim, sizeof(tim2));
//             std::sort(tim1, tim1 + cnt1, std::greater<int>());
//             std::sort(tim2, tim2 + cnt2, std::greater<int>());
//             for (int i = 0; i < cnt1; i++)
//                 if (tim1[i] != tim2[i])
//                     return tim1[i] < tim2[i];
//         }
//         return team_list[a].team_name < team_list[b].team_name;
//     }
// };

class CompareTeamSync {
  public:
    bool operator()(const int &a, const int &b) const {
        if (a == b)
            return false;
        if (team_list_sync[a].sub.ac_cnt != team_list_sync[b].sub.ac_cnt)
            return team_list_sync[a].sub.ac_cnt > team_list_sync[b].sub.ac_cnt;
        if (team_list_sync[a].penalty != team_list_sync[b].penalty)
            return team_list_sync[a].penalty < team_list_sync[b].penalty;
        if (team_list_sync[a].sub.ac_cnt) {
            // int cnt1 = 0, cnt2 = 0;
            // int tim1[30], tim2[30];
            // for (int i = 0; i < problem_cnt; i++) {
            //     if (team_list_sync[a].sub.ac_tim[i])
            //         tim1[cnt1++] = team_list_sync[a].sub.ac_tim[i];
            //     if (team_list_sync[b].sub.ac_tim[i])
            //         tim2[cnt2++] = team_list_sync[b].sub.ac_tim[i];
            // }
            // // memcpy(tim1, team_list[a].sub.ac_tim, sizeof(tim1));
            // // memcpy(tim2, team_list[b].sub.ac_tim, sizeof(tim2));
            // std::sort(tim1, tim1 + cnt1, std::greater<int>());
            // std::sort(tim2, tim2 + cnt2, std::greater<int>());
            // for (int i = 0; i < cnt1; i++)
            //     if (tim1[i] != tim2[i])
            //         return tim1[i] < tim2[i];
            for (int i = team_list_sync[a].sub.ac_cnt - 1; i >= 0; i--)
                if (team_list_sync[a].ac_tim_sort[i] != team_list_sync[b].ac_tim_sort[i])
                    return team_list_sync[a].ac_tim_sort[i] < team_list_sync[b].ac_tim_sort[i];
        }
        return team_list_sync[a].team_name < team_list_sync[b].team_name;
    }
};

double time_used[10];

std::set<int, CompareTeamSync> rank_list_sync;

void AddTeam(std::string team_name) {
    // std::cout << "ADD " << team_name << '\n';
    // double x = (double)clock() / CLOCKS_PER_SEC;
    if (!started_flag) {
        if (!team_key[team_name]) {
            std::cout << kAddTeamSuc << '\n';
            team_key[team_name] = team_cnt;
            // team_list_sync[team_cnt] = TeamData(team_name, team_cnt);
            team_list_sync.push_back(TeamData(team_name, team_cnt));
            rank_list_sync.insert(team_cnt);
            team_cnt++;
        } else {
            std::cout << kAddTeamDuplicated << '\n';
        }
    } else {
        std::cout << kAddTeamAfterStarted << '\n';
    }
    // time_used[1] += (double)clock() / CLOCKS_PER_SEC - x;
    return;
}

void StartCompetition(const int duration_time, int problem_count) {
    // std::cout << "START " << duration_time << " " << problem_count << '\n';
    if (!started_flag) {
        started_flag = 1;
        problem_cnt = problem_count;
        int rk_cnt = 1;
        for (int i = 0; i < team_cnt; i++)
            name_rank.push_back(0);
        for (auto it : rank_list_sync)
            name_rank[team_list_sync[it].tid] = rk_cnt++;
        std::cout << kStartSuc << '\n';
    } else {
        std::cout << kStartAlready << '\n';
    }
    return;
}

void SubmitProblem(const std::string problem_name, const std::string team_name, const int submit_status, const int tim) {
    // std::cout << "SUBMIT " << problem_name << " " << team_name << " " << submit_status << " " << tim << '\n';
    // double x = (double)clock() / CLOCKS_PER_SEC;
    int problem_key = problem_name[0] - 'A';
    Submission new_sub(team_key[team_name], problem_key, submit_status, tim, submit_cnt++);
    if (!freeze_flag) {
        rank_list_sync.erase(new_sub.tid);
        team_list_sync[new_sub.tid].submit(new_sub);
        rank_list_sync.insert(new_sub.tid);
    } else {
        team_list_sync[new_sub.tid].submitf(new_sub);
    }
    // time_used[2] += (double)clock() / CLOCKS_PER_SEC - x;
}

void FlushBoard() {
    // if (!tagggg)
    //     return;
    // std::cout << "FLUSH" << '\n';
    // team_list = team_list_sync;
    int rk_cnt = 0;
    // double x = (double)clock() / CLOCKS_PER_SEC;
    for (auto it : rank_list_sync) {
        name_rank[team_list_sync[it].tid] = ++rk_cnt;
    }
    std::cout << kFlushSuc << '\n';
    // time_used[3] += (double)clock() / CLOCKS_PER_SEC - x;
    // tagggg = 0;
    return;
}

void FreezeBoard() {
    // std::cout << "FREEZE" << '\n';
    if (!freeze_flag) {
        // UpdateSync();
        freeze_flag = 1;
        std::cout << kFreezeSuc << '\n';
    } else {
        std::cout << kFreezeFail << '\n';
    }
    return;
}

void OutputData();

void ScrollBoard() {
    // std::cout << "SCROLL" << '\n';
    if (!freeze_flag) {
        std::cout << kScrollFail << '\n';
        return;
    }
    bool found_frz;
    int rk_cnt = 1;
    std::cout << kScrollSuc << '\n';
    auto endd = rank_list_sync.end();
    for (auto it = rank_list_sync.begin(); it != rank_list_sync.end(); it++) {
        std::cout << team_list_sync[*it].team_name << " " << rk_cnt++ << " " << team_list_sync[*it].sub.ac_cnt << " "
                  << team_list_sync[*it].penalty << " ";
        for (int j = 0; j < problem_cnt; j++) {
            if (team_list_sync[*it].sub.ac_tim[j]) {
                if (team_list_sync[*it].sub.submit_cnt_bfac[j])
                    std::cout << "+" << team_list_sync[*it].sub.submit_cnt_bfac[j];
                else
                    std::cout << "+";
            } else if (!team_list_sync[*it].subf.submit_cnt[j]) {
                if (team_list_sync[*it].sub.submit_cnt[j])
                    std::cout << "-" << team_list_sync[*it].sub.submit_cnt[j];
                else
                    std::cout << ".";
            } else {
                if (team_list_sync[*it].sub.submit_cnt[j])
                    std::cout << "-" << team_list_sync[*it].sub.submit_cnt[j] << "/" << team_list_sync[*it].subf.submit_cnt[j];
                else
                    std::cout << "0/" << team_list_sync[*it].subf.submit_cnt[j];
            }
            if (j != problem_cnt - 1)
                std::cout << " ";
        }
        std::cout << '\n';
    }
    // OutputData();
    static std::vector<int> last_place;
    // double x = (double)clock() / CLOCKS_PER_SEC;
    last_place.assign(team_cnt, 0);
    for (auto it = rank_list_sync.begin(); it != rank_list_sync.end(); it++)
        if (team_list_sync[*it].subf.submit_tot) {
            for (int i = 0; i < problem_cnt; i++) {
                if (!team_list_sync[*it].aced_problem(i) && team_list_sync[*it].subf.submit_cnt[i]) {
                    team_list_sync[*it].sub.submit_tot += team_list_sync[*it].subf.submit_cnt[i];
                    team_list_sync[*it].subf.submit_tot -= team_list_sync[*it].subf.submit_cnt[i];
                    for (int j = 0; j < 4; j++) {
                        if (!team_list_sync[*it].subf.las_sub[i][j].tim)
                            continue;
                        team_list_sync[*it].sub.las_sub[i][j] = team_list_sync[*it].subf.las_sub[i][j];
                        team_list_sync[*it].subf.las_sub[i][j] = {0, 0, 0, 0, 0};
                    }
                    team_list_sync[*it].sub.submit_cnt[i] += team_list_sync[*it].subf.submit_cnt[i];
                    team_list_sync[*it].subf.submit_cnt[i] = 0;
                    team_list_sync[*it].sub.submit_cnt_bfac[i] += team_list_sync[*it].subf.submit_cnt_bfac[i];
                    team_list_sync[*it].subf.submit_cnt_bfac[i] = 0;
                }
            }
        }
    do {
        found_frz = 0;
        auto it = rank_list_sync.end();
        if (it == rank_list_sync.begin())
            break;
        do {
            it--;
            if (team_list_sync[*it].subf.ac_cnt) {
                found_frz = 1;
                auto it_nex = it;
                it_nex++;
                int las_nex;
                if (it_nex == rank_list_sync.end())
                    las_nex = -1;
                else
                    las_nex = *it_nex;
                rank_list_sync.erase(*it);
                for (int i = last_place[*it]; i < problem_cnt; i++) {
                    if (team_list_sync[*it].subf.ac_tim[i]) {
                        team_list_sync[*it].sub.submit_tot += team_list_sync[*it].subf.submit_cnt[i];
                        team_list_sync[*it].subf.submit_tot -= team_list_sync[*it].subf.submit_cnt[i];
                        for (int j = 0; j < 4; j++) {
                            if (!team_list_sync[*it].subf.las_sub[i][j].tim)
                                continue;
                            team_list_sync[*it].sub.las_sub[i][j] = team_list_sync[*it].subf.las_sub[i][j];
                            team_list_sync[*it].subf.las_sub[i][j] = {0, 0, 0, 0, 0};
                        }
                        team_list_sync[*it].sub.submit_cnt[i] += team_list_sync[*it].subf.submit_cnt[i];
                        team_list_sync[*it].subf.submit_cnt[i] = 0;
                        team_list_sync[*it].sub.submit_cnt_bfac[i] += team_list_sync[*it].subf.submit_cnt_bfac[i];
                        team_list_sync[*it].subf.submit_cnt_bfac[i] = 0;
                        if (team_list_sync[*it].subf.ac_tim[i]) {
                            auto pos = lower_bound(team_list_sync[*it].ac_tim_sort.begin(),
                                                   team_list_sync[*it].ac_tim_sort.end(), team_list_sync[*it].subf.ac_tim[i]);
                            team_list_sync[*it].ac_tim_sort.insert(pos, team_list_sync[*it].subf.ac_tim[i]);
                            team_list_sync[*it].sub.ac_cnt++;
                            team_list_sync[*it].subf.ac_cnt--;
                            team_list_sync[*it].sub.ac_tim[i] = team_list_sync[*it].subf.ac_tim[i];
                            team_list_sync[*it].subf.ac_tim[i] = 0;
                            team_list_sync[*it].penalty +=
                                20 * team_list_sync[*it].sub.submit_cnt_bfac[i] + team_list_sync[*it].sub.ac_tim[i];
                        }
                        last_place[*it] = i + 1;
                        break;
                    }
                }
                rank_list_sync.insert(*it);
                // OutputData();
                auto it_now = rank_list_sync.find(*it);
                it_nex = it_now;
                it_nex++;
                if (it_nex != rank_list_sync.end() && las_nex != *it_nex) {
                    std::cout << team_list_sync[*it].team_name << " " << team_list_sync[*it_nex].team_name << " "
                              << team_list_sync[*it].sub.ac_cnt << " " << team_list_sync[*it].penalty << '\n';
                }
                break;
            }
        } while (it != rank_list_sync.begin());
    } while (found_frz);
    // time_used[4] += (double)clock() / CLOCKS_PER_SEC - x;
    // team_list = team_list_sync;
    // name_rank.clear();
    // rk_cnt = 1;
    // for (auto it = rank_list_sync.begin(); it != rank_list_sync.end(); it++) {
    //     name_rank.insert({team_list[*it].team_name, rk_cnt});
    //     rk_cnt++;
    // }
    rk_cnt = 1;
    for (auto it = rank_list_sync.begin(); it != rank_list_sync.end(); it++) {
        std::cout << team_list_sync[*it].team_name << " " << rk_cnt << " " << team_list_sync[*it].sub.ac_cnt << " "
                  << team_list_sync[*it].penalty << " ";
        name_rank[team_list_sync[*it].tid] = rk_cnt;
        rk_cnt++;
        for (int j = 0; j < problem_cnt; j++) {
            if (team_list_sync[*it].sub.ac_tim[j]) {
                if (team_list_sync[*it].sub.submit_cnt_bfac[j])
                    std::cout << "+" << team_list_sync[*it].sub.submit_cnt_bfac[j];
                else
                    std::cout << "+";
            } else {
                if (team_list_sync[*it].sub.submit_cnt[j])
                    std::cout << "-" << team_list_sync[*it].sub.submit_cnt[j];
                else
                    std::cout << ".";
            }
            if (j != problem_cnt - 1)
                std::cout << " ";
        }
        std::cout << '\n';
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
        std::cout << team_name << " NOW AT RANKING " << name_rank[team_key[team_name]] << '\n';
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
                        las_sub = std::max(las_sub, team_list_sync[tid].sub.las_sub[i][j]);
                        las_sub = std::max(las_sub, team_list_sync[tid].subf.las_sub[i][j]);
                    }
            } else {
                for (int i = 0; i < problem_cnt; i++) {
                    las_sub = std::max(las_sub, team_list_sync[tid].sub.las_sub[i][submit_status]);
                    las_sub = std::max(las_sub, team_list_sync[tid].subf.las_sub[i][submit_status]);
                }
            }
        } else {
            int pid = problem_name[0] - 'A';
            if (submit_status == kALL) {
                for (int j = 0; j < 4; j++) {
                    las_sub = std::max(las_sub, team_list_sync[tid].sub.las_sub[pid][j]);
                    las_sub = std::max(las_sub, team_list_sync[tid].subf.las_sub[pid][j]);
                }
            } else {
                las_sub = std::max(team_list_sync[tid].sub.las_sub[pid][submit_status],
                                   team_list_sync[tid].subf.las_sub[pid][submit_status]);
            }
        }
        if (las_sub.exist())
            std::cout << team_name << " " << static_cast<char>(las_sub.pid + 'A') << " " << kSubmitStatus[las_sub.status] << " "
                      << las_sub.tim << '\n';
        else
            std::cout << kQsubNoSub << '\n';
    }
    return;
}
bool OperateMsg(const ReadData::InputMessage msg) {
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

void OutputData() {
    std::cout << '\n';
    for (auto it = rank_list_sync.begin(); it != rank_list_sync.end(); it++) {
        std::cout << *it << ":" << team_list_sync[*it].team_name << " " << name_rank[team_list_sync[*it].tid] << ' '
                  << team_list_sync[*it].sub.ac_cnt << ' ' << team_list_sync[*it].penalty << ' ';
        for (int i = 0; i < team_list_sync[*it].sub.ac_cnt; i++)
            std::cout << team_list_sync[*it].ac_tim_sort[i] << ' ';
        std::cout << '\n';
    }

    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    while (true) {
        ReadData::InputMessage msg;
        ReadMsg(msg);
        if (!OperateMsg(msg))
            break;
    }
    return 0;
}