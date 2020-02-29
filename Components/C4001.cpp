//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4001 cpp file
//

#include <iostream>
#include "../Primitives.hpp"
#include "../Errors.hpp"
#include "C4001.hpp"

namespace nts
{
    C4001::C4001(const std::string &name)
        :	_name{name}, _link{std::vector<std::shared_ptr<Primitive>>{14, nullptr}}
    {
        _link.at(2)  = std::shared_ptr<Primitive>(new NOr(nts::UNDEFINED, nts::UNDEFINED));
        _link.at(3)  = std::shared_ptr<Primitive>(new NOr(nts::UNDEFINED, nts::UNDEFINED));
        _link.at(9)  = std::shared_ptr<Primitive>(new NOr(nts::UNDEFINED, nts::UNDEFINED));
        _link.at(10) = std::shared_ptr<Primitive>(new NOr(nts::UNDEFINED, nts::UNDEFINED));
    }

    TriState C4001::compute(size_t cur)
    {
        if (cur < 1 || cur > 13)
            throw PinError("Pin does not exist: " + std::to_string(cur));
        return (_link[cur - 1]) ? _link[cur - 1]->compute() : UNDEFINED;
    }

    void C4001::setLink(size_t pin, IComponent &component, size_t target)
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

    void C4001::dump() const
    {
        // TODO: dump all values too?
        std::cout << "4001: " << _name << std::endl;
    }

    ctls C4001::getLinks() const
    {
        // TODO: Valton
        return ctls{};
    }
}
