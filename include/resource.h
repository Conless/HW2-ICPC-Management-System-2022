// Options Sign
const int kAdd = 1;
const int kStart = 2;
const int kSub = 3;
const int kFlush = 4;
const int kFreeze = 5;
const int kScroll = 6;
const int kQrank = 7;
const int kQsub = 8;

// The messages used when adding teams
const char kAddTeamSuc[] = "[Info]Add successfully.";
const char kAddTeamAfterStarted[] = "[Error]Add failed: competition has started.";
const char kAddTeamDuplicated[] = "[Error]Add failed: duplicated team name.";

// The messages used when starting the competition
const char kStartSuc[] = "[Info]Competition starts.";
const char kStartAlready[] = "[Error]Start failed: competition has started.";

// The messages used when flushing
const char kFlushSuc[] = "[Info]Flush scoreboard.";

// The messages used when freezing
const char kFreezeSuc[] = "[Info]Freeze scoreboard.";
const char kFreezeFail[] = "[Error]Freeze failed: scoreboard has been frozen.";

// The messages used when scrolling
const char kScrollSuc[] = "[Info]Scroll scoreboard.";
const char kScrollFail[] = "[Error]Scroll failed: scoreboard has not been frozen.";

// The messages used when querying ranking
const char kQrankSuc[] = "[Info]Complete query ranking.";
const char kQrankFail[] = "[Error]Query ranking failed: cannot find the team.";
const char kQrankWarn[] = "[Warning]Scoreboard is frozen. The ranking may be inaccurate until it were scrolled.";

// The messages used when querying submission
const char kQsubSuc[] = "[Info]Complete query submission.";
const char kQsubNoSub[] = "Cannot find any submission.";
const char kQsubNoTeam[] = "[Error]Query submission failed: cannot find the team.";

// The messages used when ending the competition
const char kEndCompetition[] = "[Info]Competition ends.";