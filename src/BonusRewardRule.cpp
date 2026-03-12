#include "BonusRewardRule.h"

int BonusRewardRule::computeReward(int baseScore, int round) {
    int bonus = 0;

    if (baseScore >= 15) {
        bonus = 20;
    } else if (baseScore >= 8) {
        bonus = 10;
    } else {
        bonus = 5;
    }

    return baseScore + bonus;
}