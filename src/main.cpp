#include "RandomInputGenerator.h"
#include "BasicScoringRule.h"
#include "BonusRewardRule.h"
#include "ShopSystem.h"
#include "RunSession.h"

int main() {
    RandomInputGenerator inputGenerator;
    BasicScoringRule scoringRule;
    BonusRewardRule rewardRule;
    ShopSystem shopSystem;

    RunSession session(inputGenerator, scoringRule, rewardRule, shopSystem);
    session.run();

    return 0;
}