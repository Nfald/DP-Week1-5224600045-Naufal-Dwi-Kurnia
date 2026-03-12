#ifndef I_SCORING_RULE_H
#define I_SCORING_RULE_H

#include "TurnInput.h"

class IScoringRule {
public:
    virtual ~IScoringRule() = default;
    virtual int computeBaseScore(const TurnInput& input, int round) = 0;
};

#endif