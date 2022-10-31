#include "../include/data.h"

int team_cnt;
std::unordered_map<std::string, int> team_name_key;
std::vector<Team> team_list, team_list_sync;

Team::Team(const std::string team_name, const int key) : team_name(team_name), key(key) {}

bool AddTeamList(const std::string team_name) {
    if (team_name_key.find(team_name) != team_name_key.end())
        return 0;
    team_list.push_back(Team(team_name, team_cnt));
    team_name_key.insert({team_name, team_cnt});
    team_cnt++;
    return 1;
}

bool Team::operator<(const Team x) const {
    if (accepted_cnt != x.accepted_cnt)
        return accepted_cnt < x.accepted_cnt;
    if (time_used != x.time_used)
        return time_used < x.time_used;
    int siz_now = sub[0].size();
    for (auto it1 = sub[0].begin(); it1 != sub[0].end(); it1++) {
        auto it2 = x.sub[0].begin();
        if (it1->tim != it2->tim)
            return it1->tim < it2->tim;
    }
    return team_name < x.team_name;
}

void SubmitProblem(const std::string problem_name, const std::string team_name, const int submit_status, const int tim) {
    int team_id = team_name_key[team_name];
    int problem_id;
    Submission new_sub(team_id, problem_id, submit_status, tim);
    auto it = team_list_sync[team_id];
    it.submit(new_sub);
}