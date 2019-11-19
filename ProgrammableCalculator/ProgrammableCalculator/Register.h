//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_REGISTERS_H
#define HW5_REGISTERS_H


class Register {
public:
    inline Register() : value(0.) {}
    inline ~Register() = default;
    inline double getValue() { return value; }
    inline void setValue(double v) { value = v; }

private:
    double value;
};


#endif //HW5_REGISTERS_H
