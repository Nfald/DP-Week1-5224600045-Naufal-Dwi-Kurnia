#include "BasicScoringRule.h"

int BasicScoringRule::computeBaseScore(const TurnInput& input, int round) {
    return input.value * round;
}