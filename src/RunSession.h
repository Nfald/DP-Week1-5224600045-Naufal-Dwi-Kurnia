#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    static const int TOTAL_ROUNDS = 3;

    IInputGenerator& inputGenerator;
    IScoringRule& scoringRule;
    IRewardRule& rewardRule;
    ShopSystem& shopSystem;

    int currentRound;
    int money;

    void advanceRound();

public:
    RunSession(
        IInputGenerator& inputGenerator,
        IScoringRule& scoringRule,
        IRewardRule& rewardRule,
        ShopSystem& shopSystem
    );

    void run();
};

#endif