#ifndef RUNSESSION_H
#define RUNSESSION_H

#include <memory>
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    std::unique_ptr<IInputGenerator> inputGenerator;
    std::unique_ptr<IScoringRule> scoringRule;
    std::unique_ptr<IRewardRule> rewardRule;
    ShopSystem shopSystem;

    int currentRound;
    int money;

public:
    RunSession(std::unique_ptr<IInputGenerator> ig,
               std::unique_ptr<IScoringRule> sr,
               std::unique_ptr<IRewardRule> rr);

    void run();
};

#endif