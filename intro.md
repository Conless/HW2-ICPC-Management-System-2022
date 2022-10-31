## 算法思路

首先, 对于队伍数据, 用两个 vector 数组存储, 分别记录队伍直到上一次封榜/刷新榜单前的数据与实时数据, 包括了队伍名称, 队伍对于每一题的提交次数, 正确提交前的提交次数, 通过题目的数量, 对于每一道题的通过时间, 对于每一个题目每一个状态的最后一次提交. 还有其在封榜之后进行的操作, 包括了封榜后队伍对每一题的提交次数, 正确提交前的提交次数, 通过题目的数量, 对于每一题的通过时间, 对于每一个题目每一个状态的最后一次提交.

接下来, 用一个 unordered_map 建立从队伍名到队伍编号的映射.

用两个 set 管理队伍的实时排名.

添加队伍时, 将每一支队伍依次添加到两个 vector, unordered_map 与 set 中, 最坏时间复杂度为 set 添加的 O(nlogn).

提交题目时, 如果此时不处于封榜状态, 将提交信息添加到实时队伍数据的 vector 中, 然后对实时数据的 set 进行先删除后插入的操作. 如果此时处于封榜状态, 将提交信息添加到实时队伍数据的 vector 的封榜信息中, 不用操作 set.

刷新榜单时, 直接将储存实时数据的 vector 和 set 拷贝给储存上一次数据的结构, 同时, 从 set.begin() 开始, 更新每一支队伍的排名数据, 总时间复杂度为 O(nlogn).

封榜时, 将封榜的标记标为 true 即可.

滚榜时, 首先, 对于原始 set, 直接取出 --set.end(), 然后据此找到其在实时 vector 中的位置, 进行更新即可.

## 项目架构

- include
  - resource.h
  - operator.h
    - data.h
    - input.h
- src
  - main.cpp
  - operator.cc
    - data.cc
    - input.cc



## 实现架构

完成整个管理系统, 所需要的主干信息为每支队伍的信息 

需要实现的接口有

- resource.h    √
  - 输入判断信息 √
  - 提交状态记号 √

- operator.h
  - bool OperateMsg(const InputMessage) 实现输入信息分类 √
  - void AddTeam(teamname)
  - 

- input.h √
  - struct InputMessage; 储存输入信息 √
  - void ReadMsg(InputMessage &msg) √

- data.h
  - struct Submission
    - pid, uid, status, tim
  - struct SubmitData
    - submit_cnt[30], submit_cnt_bfac[30]
    - ac_cnt[30], ac_tim[30]
    - ac_flag[30]
    - Submission las_sub[4]
  
  - class Team
    - teamname, teamkey
    - SubmitData sub, subf;
    - void submit(const Submission)
    - void qsub(const int status)

  - class CompareTeam
    - bool operator()
  - class CompareTeamSync
    - bool operator()
  - class RankList
    - set<int, CompareTeam> rklist
    - set<int, CompareTeamSync> rklist_sync
    - void flush()
    - void freeze()
    - void scroll()

  - bool AddTeamList(string team_name)
  - void FlushAllTeam()