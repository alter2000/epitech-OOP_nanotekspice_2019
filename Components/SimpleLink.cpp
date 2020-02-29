//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// Simple Link cpp file
//

#include "SimpleLink.hpp"

SimpleLink::SimpleLink(nts::IComponent *component, size_t pin)
: in(std::make_pair(component, pin))
{
}

nts::Tristate SimpleLink::compute()
{
    return((this->in.first)->Compute(this->in.second));
}
