#include "../include/data.h"

#include "../include/resource.h"

bool Submission::operator<(const Submission x) const {
        if (tim != x.tim)
            return tim < x.tim;
        return submitid < x.submitid;
}

SubmitData::SubmitData() {
        ac_cnt = 0;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = 0;
            submit_cnt_bfac[i] = 0;
            ac_tim[i] = 0;
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = {0, 0, 0, 0, 0};
        }
    }
    SubmitData::SubmitData(const SubmitData &x) {
        ac_cnt = x.ac_cnt;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = x.submit_cnt[i];
            submit_cnt_bfac[i] = x.submit_cnt_bfac[i];
            ac_tim[i] = x.ac_tim[i];
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = x.las_sub[i][j];
        }
    }
    void SubmitData::clear() {
        ac_cnt = 0;
        for (int i = 0; i < MAXM; i++) {
            submit_cnt[i] = 0;
            submit_cnt_bfac[i] = 0;
            ac_tim[i] = 0;
            for (int j = 0; j < 4; j++)
                las_sub[i][j] = {0, 0, 0, 0, 0};
        }
    }

    void TeamData::submit(const Submission x) {
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
    void TeamData::submitf(const Submission x) {
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