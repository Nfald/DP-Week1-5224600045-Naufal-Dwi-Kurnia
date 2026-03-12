#ifndef RANDOM_INPUT_GENERATOR_H
#define RANDOM_INPUT_GENERATOR_H

#include "IInputGenerator.h"

class RandomInputGenerator : public IInputGenerator {
public:
    RandomInputGenerator();
    TurnInput generate(int round) override;
};

#endif