#include <memory>
#include "RunSession.h"
//#include "RandomInputGenerator.h"
#include "BasicScoringRule.h"
//#include "BasicRewardRule.h"

int main() {
   // std::unique_ptr<IInputGenerator> inputGen =
        std::make_unique<RandomInputGenerator>();

    std::unique_ptr<IScoringRule> scoring =
        std::make_unique<BasicScoringRule>();

    //std::unique_ptr<IRewardRule> reward =
        std::make_unique<BasicRewardRule>();

    RunSession session(std::move(inputGen),
                       std::move(scoring),
                       //std::move(reward));

    session.run();

    return 0;
}