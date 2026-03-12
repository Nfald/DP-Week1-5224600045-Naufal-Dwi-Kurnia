#ifndef BASIC_SCORING_RULE_H
#define BASIC_SCORING_RULE_H

#include "IScoringRule.h"

class BasicScoringRule : public IScoringRule {
public:
    int computeBaseScore(const TurnInput& input, int round) override;
};

#endif