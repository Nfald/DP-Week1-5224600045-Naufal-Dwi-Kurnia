#include <iostream>
#include "RunSession.h"

RunSession::RunSession(std::unique_ptr<IInputGenerator> ig,
                       std::unique_ptr<IScoringRule> sr,
                       std::unique_ptr<IRewardRule> rr)
    : inputGenerator(std::move(ig)),
      scoringRule(std::move(sr)),
      rewardRule(std::move(rr)),
      currentRound(1),
      money(0) {}

void RunSession::run() {
    std::cout << "=== RUN START ===\n";

    while (currentRound <= 3) {
        std::cout << "Round " << currentRound << "\n";

        // 1. Generate input
        TurnInput input = inputGenerator->generateInput(currentRound);
        std::cout << "[PLAY] input generated: " << input.value << "\n";

        // 2. Compute base score
        int baseScore = scoringRule->computeBaseScore(input);
        std::cout << "[SCORE] base score: " << baseScore << "\n";

        // 3. Compute reward
        int reward = rewardRule->computeReward(baseScore, currentRound);

        // 4. Update money
        money += reward;
        std::cout << "[REWARD] gain: " << reward
                  << " | money: " << money << "\n";

        // 5. Shop phase
        shopSystem.showShopOffer();

        // 6. Advance round
        currentRound++;
        std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}