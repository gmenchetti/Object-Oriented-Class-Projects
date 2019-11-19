//
// Created by Guglielmo Menchetti on 2018-11-28.
//

#ifndef HW5_REGISTERCOUNTER_H
#define HW5_REGISTERCOUNTER_H

#include "Register.h"

class RegisterCounter {

public:
    inline Register& getX() { return x; }
    inline Register& getY() { return y; }
    inline Register& getW() { return w; }
    inline Register& getZ() { return z; }
    inline unsigned int getCurrentInstruction() { return currentInstruction; }
    inline unsigned int getExecuted() { return executedInstructions; }
    inline void setX(double v) { x.setValue(v); }
    inline void setY(double v) { y.setValue(v); }
    inline void setW(double v) { w.setValue(v); }
    inline void setZ(double v) { z.setValue(v); }
    inline void setCurrentInstruction(unsigned int c) { currentInstruction = c; }
    inline void incrementCurrent() { currentInstruction++; }
    inline void incrementExecuted() { executedInstructions++; }
    inline void resetExecuted() { executedInstructions = 0; }
    inline void resetCurrent() { currentInstruction = 0; }
    inline void resetRegisters() {
        x.setValue(0.);
        y.setValue(0.);
        w.setValue(0.);
        z.setValue(0.);
    }

private:
    Register x;
    Register y;
    Register w;
    Register z;
    unsigned int currentInstruction;
    unsigned int executedInstructions;
};


#endif //HW5_REGISTERCOUNTER_H
