#include <string>

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