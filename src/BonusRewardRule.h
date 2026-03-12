#ifndef BONUS_REWARD_RULE_H
#define BONUS_REWARD_RULE_H

#include "IRewardRule.h"

class BonusRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore, int round) override;
};

#endif