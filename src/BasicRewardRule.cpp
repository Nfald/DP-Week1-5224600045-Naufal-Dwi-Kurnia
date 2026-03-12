#include "BasicRewardRule.h"

int BasicRewardRule::computeReward(int baseScore, int round) {
    return baseScore + 10;
}