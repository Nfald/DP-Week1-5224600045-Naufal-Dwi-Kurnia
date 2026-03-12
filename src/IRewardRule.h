#ifndef I_REWARD_RULE_H
#define I_REWARD_RULE_H

class IRewardRule {
public:
    virtual ~IRewardRule() = default;
    virtual int computeReward(int baseScore, int round) = 0;
};

#endif