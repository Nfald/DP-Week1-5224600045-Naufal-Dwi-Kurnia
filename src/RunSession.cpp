#include <iostream>
#include "RunSession.h"

RunSession::RunSession(
    IInputGenerator& inputGenerator,
    IScoringRule& scoringRule,
    IRewardRule& rewardRule,
    ShopSystem& shopSystem
)
    : inputGenerator(inputGenerator),
      scoringRule(scoringRule),
      rewardRule(rewardRule),
      shopSystem(shopSystem),
      currentRound(1),
      money(0) {}

void RunSession::advanceRound() {
    std::cout << "[ROUND] Advancing from round " << currentRound << std::endl;
    currentRound++;
}

void RunSession::run() {
    std::cout << "=== RUN START ===" << std::endl;

    while (currentRound <= TOTAL_ROUNDS) {
        std::cout << "Round " << currentRound << std::endl;

        TurnInput input = inputGenerator.generate(currentRound);
        std::cout << "[PLAY] Input generated: " << input.value << std::endl;

        int baseScore = scoringRule.computeBaseScore(input, currentRound);
        std::cout << "[SCORE] Base score: " << baseScore << std::endl;

        int reward = rewardRule.computeReward(baseScore, currentRound);
        std::cout << "[REWARD] Reward gained: " << reward << std::endl;

        money += reward;
        std::cout << "[MONEY] Total money: " << money << std::endl;

        shopSystem.showOffer(currentRound, money);

        advanceRound();

        if (currentRound <= TOTAL_ROUNDS) {
            std::cout << std::endl;
        }
    }

    std::cout << "=== RUN END ===" << std::endl;
    std::cout << "Final money: " << money << std::endl;
}