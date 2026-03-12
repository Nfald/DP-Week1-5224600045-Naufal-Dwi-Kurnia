#ifndef I_INPUT_GENERATOR_H
#define I_INPUT_GENERATOR_H

#include "TurnInput.h"

class IInputGenerator {
public:
    virtual ~IInputGenerator() = default;
    virtual TurnInput generate(int round) = 0;
};

#endif