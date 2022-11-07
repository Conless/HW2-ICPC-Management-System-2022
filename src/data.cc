// The implementation of include/data.h
// This source contains the implementation of the class Submission, SubmitData and TeamData, which formed the basic data types
// of the ICPC Management System.

// Author: Conless
// Date: 2022-11-01
// File name: /src/data.cc

#include "data.h"

#include <iostream>

#include "resource.h"

bool Submission::operator<(const Submission &x) const { // Compare two different submissions
    if (tim != x.tim)                                   // If the submit time is different
        return tim < x.tim;
    return submitid < x.submitid; // Otherwise we should compare their submit id
}

SubmitData::SubmitData() { // The constructor of class SubmitData
    ac_cnt = 0;
    for (int i = 0; i < MAXM; i++) {
        submit_cnt[i] = 0;
        submit_cnt_bfac[i] = 0;
        ac_tim[i] = 0;
        for (int j = 0; j < 4; j++)
            las_sub[i][j] = {0, 0, 0, 0, 0};
    }
}
SubmitData::SubmitData(const SubmitData &x) { // Copy constructor of class SubmitData
    ac_cnt = x.ac_cnt;
    for (int i = 0; i < MAXM; i++) {
        submit_cnt[i] = x.submit_cnt[i];
        submit_cnt_bfac[i] = x.submit_cnt_bfac[i];
        ac_tim[i] = x.ac_tim[i];
        for (int j = 0; j < 4; j++)
            las_sub[i][j] = x.las_sub[i][j];
    }
}

void TeamData::submit(const Submission &x) { // Submit a problem by a team, while the scoreboard is not frozen
    sub.submit_cnt[x.pid]++;
    sub.las_sub[x.pid][x.status] = x;
    if (x.status == kAC && !aced_problem(x.pid)) { // Get a new accepted problem
        sub.ac_cnt++;
        sub.ac_tim[x.pid] = x.tim;
        ac_tim_sort.push_back(
            x.tim); // Notice that the submission is in time order, we can directly push them into the monotonic queue
        penalty += 20 * sub.submit_cnt_bfac[x.pid] + x.tim; // Update the penalty
    } else if (x.status != kAC && !aced_problem(x.pid)) {
        sub.submit_cnt_bfac[x.pid]++;
    }
    return;
}
void TeamData::submitf(const Submission &x) { // Submit a problem by a team, while the scoreboard is frozen
    subf.submit_tot++;
    subf.submit_cnt[x.pid]++;
    subf.las_sub[x.pid][x.status] = x;
    if (x.status == kAC && !aced_problem(x.pid)) { // Update its ac data, but don't update its ac queue
        subf.ac_cnt++;
        subf.ac_tim[x.pid] = x.tim;
    } else if (x.status != kAC && !aced_problem(x.pid)) {
        subf.submit_cnt_bfac[x.pid]++;
    }
    return;
}
void TeamData::output_info(const int now_rank) { // Output the information of a team
    std::cout << team_name << " " << now_rank << " " << sub.ac_cnt << " " << penalty << " ";
}
void TeamData::output_data(const int problem_cnt) { // Output the whole data of a team, while the scoreboard is not frozen
    for (int j = 0; j < problem_cnt; j++) {
        if (sub.ac_tim[j]) {
            if (sub.submit_cnt_bfac[j])
                std::cout << "+" << sub.submit_cnt_bfac[j];
            else
                std::cout << "+";
        } else {
            if (sub.submit_cnt[j])
                std::cout << "-" << sub.submit_cnt[j];
            else
                std::cout << ".";
        }
        if (j != problem_cnt - 1)
            std::cout << " ";
    }
    std::cout << '\n';
}
void TeamData::output_data_freezed(const int problem_cnt) { // Output the whole data of a team, while the scoreboard is frozen
    for (int j = 0; j < problem_cnt; j++) {
        if (sub.ac_tim[j]) {
            if (sub.submit_cnt_bfac[j])
                std::cout << "+" << sub.submit_cnt_bfac[j];
            else
                std::cout << "+";
        } else if (!subf.submit_cnt[j]) {
            if (sub.submit_cnt[j])
                std::cout << "-" << sub.submit_cnt[j];
            else
                std::cout << ".";
        } else {
            if (sub.submit_cnt[j])
                std::cout << "-" << sub.submit_cnt[j] << "/" << subf.submit_cnt[j];
            else
                std::cout << "0/" << subf.submit_cnt[j];
        }
        if (j != problem_cnt - 1)
            std::cout << " ";
    }
}
void TeamData::output_data_replace(const std::string &replaced_team) { // Output the information when scorlling
    std::cout << team_name << " " << replaced_team << " " << sub.ac_cnt << " " << penalty << '\n';
}
void TeamData::unfreeze(const int pid) { // Unfreeze a problem of a team
    sub.submit_tot += subf.submit_cnt[pid];
    subf.submit_tot -= subf.submit_cnt[pid];
    for (int j = 0; j < 4; j++) {
        if (!subf.las_sub[pid][j].tim)
            continue;
        sub.las_sub[pid][j] = subf.las_sub[pid][j];
        subf.las_sub[pid][j] = {0, 0, 0, 0, 0};
    }
    sub.submit_cnt[pid] += subf.submit_cnt[pid];
    subf.submit_cnt[pid] = 0;
    sub.submit_cnt_bfac[pid] += subf.submit_cnt_bfac[pid];
    subf.submit_cnt_bfac[pid] = 0;
    if (subf.ac_tim[pid]) { // If that problem is aced by this team
        auto pos = lower_bound(ac_tim_sort.begin(), ac_tim_sort.end(), subf.ac_tim[pid]);
        ac_tim_sort.insert(pos, subf.ac_tim[pid]); // Find a correct place to insert the ac data
        sub.ac_cnt++;
        subf.ac_cnt--;
        sub.ac_tim[pid] = subf.ac_tim[pid];
        subf.ac_tim[pid] = 0;
        penalty += 20 * sub.submit_cnt_bfac[pid] + sub.ac_tim[pid];
    }
}
bool TeamData::operator<(const TeamData &x) const { // Compare the data of two teams
    if (sub.ac_cnt != x.sub.ac_cnt)
        return sub.ac_cnt > x.sub.ac_cnt;
    if (penalty != x.penalty)
        return penalty < x.penalty;
    if (sub.ac_cnt) { // Directly compare the monotonic queue of submission of a team, instead of sorting the ac data, which
                      // reduce the time when comparing
        for (int i = sub.ac_cnt - 1; i >= 0; i--)
            if (ac_tim_sort[i] != x.ac_tim_sort[i])
                return ac_tim_sort[i] < x.ac_tim_sort[i];
    }
    return team_name < x.team_name;
}