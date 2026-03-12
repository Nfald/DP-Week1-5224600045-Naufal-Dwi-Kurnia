#include "FixedInputGenerator.h"

FixedInputGenerator::FixedInputGenerator(const std::vector<int>& values)
    : inputs(values) {}

TurnInput FixedInputGenerator::generate(int round) {
    TurnInput input{0};

    if (round >= 1 && round <= static_cast<int>(inputs.size())) {
        input.value = inputs[round - 1];
    }

    return input;
}