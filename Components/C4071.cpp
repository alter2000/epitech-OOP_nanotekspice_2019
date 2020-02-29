//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4071 cpp file
//

#include <iostream>
#include "../Primitives.hpp"
#include "../Errors.hpp"
#include "C4071.hpp"

namespace nts
{
    C4001::C4071(const std::string &name)
        :       _name{name}, _link{ctls{14, nullptr}}
    {
        _link.at(2)  = new Or(this, 1, this, 2);
        _link.at(3)  = new Or(this, 5, this, 6);
        _link.at(9)  = new Or(this, 8, this, 9);
        _link.at(10) = new Or(this, 12, this, 13);
    }

    TriState C4071::compute(size_t cur)
    {
        if (cur < 1 || cur > 13)
            throw PinError("Pin does not exist: " + std::to_string(cur));
        return (_link[cur - 1]) ? _link[cur - 1]->compute() : UNDEFINED;
    }

    void C4071::setLink(size_t pin, IComponent &component, size_t target)
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

    void C4071::dump() const
    {
        std::cout << "4071: " << _name << std::endl;
    }
}
