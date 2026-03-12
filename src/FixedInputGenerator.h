#ifndef FIXED_INPUT_GENERATOR_H
#define FIXED_INPUT_GENERATOR_H

#include <vector>
#include "IInputGenerator.h"

class FixedInputGenerator : public IInputGenerator {
private:
    std::vector<int> inputs;

public:
    FixedInputGenerator(const std::vector<int>& values);
    TurnInput generate(int round) override;
};

#endif