#ifndef BASIC_REWARD_RULE_H
#define BASIC_REWARD_RULE_H

#include "IRewardRule.h"

class BasicRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore, int round) override;
};

#endif