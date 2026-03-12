#include <vector>
#include "FixedInputGenerator.h"
#include "BasicScoringRule.h"
#include "BasicRewardRule.h"
#include "ShopSystem.h"
#include "RunSession.h"

int main() {
    FixedInputGenerator inputGenerator({3, 5, 2});
    BasicScoringRule scoringRule;
    BasicRewardRule rewardRule;
    ShopSystem shopSystem;

    RunSession session(inputGenerator, scoringRule, rewardRule, shopSystem);
    session.run();

    return 0;
}