//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4081 cpp file
//

#include <iostream>
#include "../Primitives.hpp"
#include "../Errors.hpp"
#include "C4081.hpp"

namespace nts
{
    C4081::C4081(const std::string &name)
        :       _name{name}, _link{ctls{14, nullptr}}
    {
        _link.at(2)  = new And(this, 1, this, 2);
        _link.at(3)  = new And(this, 5, this, 6);
        _link.at(9)  = new And(this, 8, this, 9);
        _link.at(10) = new And(this, 12, this, 13);
    }

    TriState C4081::compute(size_t cur)
    {
        if (cur < 1 || cur > 13)
            throw PinError("Pin does not exist: " + std::to_string(cur));
        return (_link[cur - 1]) ? _link[cur - 1]->compute() : UNDEFINED;
    }

    void C4081::setLink(size_t pin, IComponent &component, size_t target)
    {
        switch (pin) {
            case 1: case 2: case 5:  case 6:
            case 8: case 9: case 12: case 13:
                _link.at(pin - 1) = new SimpleLink(&component, target);
                return;
            case 3: case 4: case 10: case 11:
                component.setLink(target, *this, pin);
                return;
            default: return;
        }
    }

    void C4081::dump() const
    { 
        std::cout << "4081: " << _name << std::endl;
    }
}
